#include "DlgComment.h"

namespace LogWatcher {
DlgComment::DlgComment(int row, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	/* Methods for initializing the model,
     * from which data will be broadcast
     * */
	setupModel();

	/* If the line is not specified, that is -1
     * then the dialog works on the principle of creating a new record.
     * Namely, a new line is inserted into the model and work is being done with it.
     * */
	if( row == -1 )
	{
        m_model->insertRow(m_model->rowCount(QModelIndex()));
        m_mapper->toLast();
	}
	/* Otherwise, the dialog is configured to the specified entry.
	 * */
	else
	{
        m_mapper->setCurrentModelIndex(m_model->index(row, 0));
	}

    connect(ui.pushButtonSave, SIGNAL(clicked()), this, SLOT(on_buttonBox_accepted()));
}

DlgComment::~DlgComment()
{
    delete m_model;
    delete m_mapper;
}

/* Method for setting data model and mapper
 * */
void DlgComment::setupModel()
{
	/* Initialization of the model and make a selection from it */
    m_model = new QSqlTableModel(this);

	/* Does not select data from the table, but selects information about its field. */
    m_model->setTable(DEVICE);

	/*The model will be cached until I run submitAll () manually!*/
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);

	/* Populates the model with data from a table that was set using setTable () */
    m_model->select();

	/* Initialize the mapper and bind
     * data fields to LineEdit objects
     * */
    m_mapper = new QDataWidgetMapper();
    m_mapper->setModel(m_model);

	/* Adds a mapping between the widget and section from the model */
    m_mapper->addMapping(ui.lineEditLog, 1);
    m_mapper->addMapping(ui.lineEditComment, 2);
    m_mapper->addMapping(ui.radioButtonNext, 3);

	/* Manual confirmation of data change via mapper
     * The model is not updated until submit () is called
     * */
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void DlgComment::on_buttonBox_accepted()
{
	/* SQL query to verify the existence of a record.
     * If the record does not exist or only the index is found,
     * then the dialog allows you to insert records into the data table
     * */
	QSqlQuery query;

	query.prepare("SELECT EXISTS (SELECT * FROM DeviceTable WHERE Log = :Log );");
	query.bindValue(":Log", ui.lineEditLog->text());

	query.exec();
	query.next();

	/* If the record exists, then the dialog calls
     * warning message
     * */
	if( query.value(0).toBool() )
	{
		QMessageBox::information(this, trUtf8("Error"), trUtf8("Such a log already exists"));
	}
	else
	{
		/* New data is inserted into the table.
         * and the dialog ends with a signal for updating
         * tables in the main window
         * */
		if( !ui.lineEditComment->text().isEmpty() )
		{
            m_mapper->submit();
            m_model->submitAll();
			emit signalReady();
			this->close();
		}
		else
		{
			QMessageBox::information(this, trUtf8("Error"),
				trUtf8("Need add comment in the line edit"));
		}
	}
}
}