#include "DlgEdit.h"

namespace LogWatcher {
DlgEdit::DlgEdit(int row, QWidget* parent)
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

DlgEdit::~DlgEdit()
{
    delete m_model;
    delete m_mapper;
}

/* Method for setting data model and mapper
 * */
void DlgEdit::setupModel()
{
	/* Initialization of the model and make a selection from it
	 * */
    m_model = new QSqlTableModel(this);
    m_model->setTable(DEVICE);
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
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


	/* Manual confirmation of data changes via mapper */
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void DlgEdit::on_buttonBox_accepted()
{
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