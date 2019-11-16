#include "DataWidgetMapper.h"

namespace LogWatcher {
DataWidgetMapper::DataWidgetMapper(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("LOG DATABASE");
	ui.dockWidget->hide();

	/* Creating an object for working with the database and initializing the connection to the database */
    m_db.connectToDataBase();

	/* Initializing a model for presenting data with specifying column names */
	this->setupModel(DEVICE,
		QStringList() << trUtf8("id")
		<< trUtf8("Log")
		<< trUtf8("Comment")
		<< trUtf8("Type")
	);
	/* Initializing the appearance of a data table */
	this->createUI();
}

DataWidgetMapper::~DataWidgetMapper()
{
    deleteLater();
    delete m_modelDevice;
}

void DataWidgetMapper::setupModel(const QString& tableName, const QStringList& headers)
{
	/* Initialization of the data presentation model */
    m_modelDevice = new QSqlTableModel(this);
    m_modelDevice->setTable(tableName);
    m_modelDevice->select(); // Make data selection from the table

	/* Setting column names in a table with data sorting */
	for( int i = 0, j = 0; i < m_modelDevice->columnCount(); i++, j++ )
    {
        m_modelDevice->setHeaderData(i, Qt::Horizontal, headers[j]);
	}
}

void DataWidgetMapper::createUI()
{
    /* Install the model on the TableView */
	ui.deviceTableView->setModel(m_modelDevice);

    /* Hide the column with id records */
	ui.deviceTableView->setColumnHidden(0, true);

    /* Hiding the Log Type column */
	ui.deviceTableView->setColumnHidden(3, true);

	/* Allow row selection */
	ui.deviceTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

	/* Set the selection mode to only one row in the table */ 
	ui.deviceTableView->setSelectionMode(QAbstractItemView::SingleSelection);

	/* Set the size of the columns according to the content */
	ui.deviceTableView->resizeColumnsToContents();
	ui.deviceTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.deviceTableView->horizontalHeader()->setStretchLastSection(true);

	/* Set the Context Menu */
	ui.deviceTableView->setContextMenuPolicy(Qt::CustomContextMenu);

	connect(ui.deviceTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord()));

	/* SLOT context menu */
	connect(ui.deviceTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
}

/* Method for activating the add records dialog
 * */
void DataWidgetMapper::addLog(const QString& logIn)
{
	/* Create a dialog and connect its completion signal
	 * to the update slot of the view of the data representation model, but it is transmitted
	 * as parameters, the recording string
	 * */
	QPointer<DlgComment> addDeviceDialog = new DlgComment();
    addDeviceDialog->setAttribute(Qt::WA_DeleteOnClose);
	addDeviceDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

	/* Sending the original log */
	addDeviceDialog->getUI().lineEditLog->setText(logIn);

	connect(addDeviceDialog, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));

	/* Run the dialog box */
	addDeviceDialog->setWindowTitle(trUtf8("Add Log"));
	addDeviceDialog->exec();
}

void DataWidgetMapper::findLog(const QString& logIn)
{
	ui.dockWidget->show();

    /* Install the model on the TableView */
	ui.deviceTableView_2->setModel(m_modelDevice);

    /* Hide the column with id records */
	ui.deviceTableView_2->setColumnHidden(0, true);

    /* Hiding the Log Type column */
	ui.deviceTableView_2->setColumnHidden(3, true);

	/* Allow row selection */ 
	ui.deviceTableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);

	/* Set the selection mode to only one row in the table */ 
	ui.deviceTableView_2->setSelectionMode(QAbstractItemView::SingleSelection);

	/* Set the size of the columns according to the content */ 
	ui.deviceTableView_2->resizeColumnsToContents();
	ui.deviceTableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.deviceTableView_2->horizontalHeader()->setStretchLastSection(true);

	QSortFilterProxyModel* proxy = new QSortFilterProxyModel(this);
	proxy->setSourceModel(m_modelDevice);

	proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
	proxy->setFilterKeyColumn(-1);
	ui.deviceTableView_2->setModel(proxy);

	proxy->setFilterFixedString(logIn);
}

void DataWidgetMapper::slotCustomMenuRequested(const QPoint& pos)
{
	/* Create a context menu object */
    QPointer<QMenu> menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

	/* Create actions for the context menu */
    QPointer<QAction> editDevice = new QAction(trUtf8("Edit"), this);
    QPointer<QAction> deleteDevice = new QAction(trUtf8("Delete"), this);

	/* We connect SLOT handlers for context menu actions */
	connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));
	connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecord()));

	/* Set the actions in the menu */
	menu->addAction(editDevice);
	menu->addAction(deleteDevice);

	/* Call the context menu */
	menu->popup(ui.deviceTableView->viewport()->mapToGlobal(pos));
}

/* Slot for deleting a record from a table
 * */
void DataWidgetMapper::slotRemoveRecord()
{
	/* Find out which row was selected
     * */
	int row = ui.deviceTableView->selectionModel()->currentIndex().row();

	/* Check that the row was actually selected */
	if( row >= 0 ) 
    {
		/* We ask whether it is really worth deleting a record.
         * If yes, delete the record
         * */
		if( QMessageBox::warning(this,
			trUtf8("Delete record"),
			trUtf8("Are you sure you want to delete this entry?"),
			QMessageBox::Yes | QMessageBox::No) == QMessageBox::No )
		{
			/* If the answer is no, we roll back the actions
             * and close the dialog without deleting the record
             * */
			QSqlDatabase::database().rollback();
			return;
		}
		else 
        {
			/* Otherwise, we delete the record.
             * Upon successful removal, update the table.
             * */
			if( !m_modelDevice->removeRow(row) ) 
            {
				QMessageBox::warning(this, trUtf8("Notification"),
					trUtf8("Failed to delete entry\n"
						"Perhaps it is used by other tables\n"
						"Check all dependencies and try again"));
			}
            m_modelDevice->select();
			ui.deviceTableView->setCurrentIndex(m_modelDevice->index(-1, -1));
		}
	}
}

/* Presentation Model Update Slot
 * */
void DataWidgetMapper::slotUpdateModels()
{
	/* Fills the model with data from the table that was installed */
    m_modelDevice->select();
	ui.deviceTableView->resizeColumnsToContents();
}

/* Method for activating the dialog for adding records in edit mode
 * with passing the index of the selected row
 * */
void DataWidgetMapper::slotEditRecord()
{
	/* Create a dialog and connect its completion signal
     * to the update slot of the view of the data representation model, but it
     * as parameters, the recording string
     * */
	QPointer<DlgEdit> editdDeviceDialog = new DlgEdit(ui.deviceTableView->selectionModel()->currentIndex().row());
    editdDeviceDialog->setAttribute(Qt::WA_DeleteOnClose);
	editdDeviceDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

	connect(editdDeviceDialog, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));

	/* Run the dialog box
	 * */
	editdDeviceDialog->setWindowTitle(trUtf8("Edit Log"));
	editdDeviceDialog->exec();
}
}