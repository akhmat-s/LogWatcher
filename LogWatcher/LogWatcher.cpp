#include "LogWatcher.h"

namespace LogWatcher {

/* Transaction Index */
std::set<QString> pathLock;
/* Analysis Transaction Index and Database */
bool isAnalyzeRunning = false;

LogWatcher::LogWatcher(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	/* GroupBox with button going to menuBar position. */
	setMenuWidget(ui.groupBox_2);

    /* Initializing the connection to the database */
    m_db.connectToDataBase();

	/* ComboBox Color */
	ui.comboBoxInfo->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(7, QColor(230, 230, 250), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBoxInfo->setItemData(ui.comboBoxInfo->currentIndex(), Qt::BackgroundRole);

	ui.comboBoxDebug->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(7, QColor(230, 230, 250), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBoxDebug->setItemData(ui.comboBoxDebug->currentIndex(), Qt::BackgroundRole);

	ui.comboBoxWarning->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(7, QColor(230, 230, 250), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBoxWarning->setItemData(ui.comboBoxWarning->currentIndex(), Qt::BackgroundRole);

	ui.comboBoxError->setItemData(0, QColor(Qt::white), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(1, QColor(Qt::red), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(2, QColor(Qt::yellow), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(3, QColor(Qt::cyan), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(4, QColor(238, 130, 238), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(5, QColor(128, 0, 128), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(6, QColor(Qt::magenta), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(7, QColor(230, 230, 250), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(8, QColor(Qt::gray), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(9, QColor(Qt::green), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(10, QColor(30, 144, 255), Qt::BackgroundRole);
	ui.comboBoxError->setItemData(ui.comboBoxError->currentIndex(), Qt::BackgroundRole);

	m_analyzClrCount.append(QBrush(Qt::white));
	m_analyzClrCount.append(QBrush(Qt::red));
	m_analyzClrCount.append(QBrush(Qt::yellow));
	m_analyzClrCount.append(QBrush(Qt::cyan));
	m_analyzClrCount.append(QBrush(QColor(238, 130, 238)));
	m_analyzClrCount.append(QBrush(QColor(128, 0, 128)));
	m_analyzClrCount.append(QBrush(Qt::magenta));
	m_analyzClrCount.append(QBrush(QColor(216, 191, 216)));
	m_analyzClrCount.append(QBrush(Qt::gray));
	m_analyzClrCount.append(QBrush(Qt::green));
	m_analyzClrCount.append(QBrush(QColor(30, 144, 255)));

	//-----------------------------------------------------------------------

	ui.tabWidget->removeTab(0);
	ui.tabWidget_2->removeTab(0);
	connect(ui.openButton, SIGNAL(clicked()), this, SLOT(on_pushButtonOpen_clicked()));
	connect(ui.pushButtonOpenSearch, SIGNAL(clicked()), this, SLOT(on_pushButtonOpenSearch_clicked()), Qt::UniqueConnection);
	connect(ui.pushButtonAnalyz, SIGNAL(clicked()), this, SLOT(on_pushButtonAnalyz_clicked()), Qt::UniqueConnection);
	connect(ui.pushButtonEditData, SIGNAL(clicked()), this, SLOT(on_pushButtonEditData_clicked()), Qt::UniqueConnection);

	connect(ui.tabWidget, &QTabWidget::tabCloseRequested, this, &LogWatcher::on_tabWidget_tabCloseReguested);
	connect(ui.tabWidget_2, &QTabWidget::tabCloseRequested, this, &LogWatcher::on_tabWidget_tabCloseReguestedSearch);
	connect(ui.radioButtonNext, SIGNAL(clicked()), this, SLOT(on_pushButtonNext_clicked()));
	connect(ui.radioButtonIntellect, SIGNAL(clicked()), this, SLOT(on_pushButtonIntellect_clicked()));
}

LogWatcher::~LogWatcher()
{
}

void LogWatcher::on_pushButtonNext_clicked()
{
	m_core.setRadioTypeLog("Next");
}
void LogWatcher::on_pushButtonIntellect_clicked()
{
	m_core.setRadioTypeLog("Intellect");
}

void LogWatcher::appendFileData(int position)
{
    m_core.updateTabDataAndModel(ui.tabWidget->currentIndex());
}

void LogWatcher::on_pushButtonOpen_clicked()
{
	m_filePathsCount = QFileDialog::getOpenFileNames(this, "Open a file", QDir::homePath());
	for( size_t i = 0; i < m_filePathsCount.length(); i++ )
	{
		if( !m_core.isFileExist(m_filePathsCount[i]) )
		{
			m_tabListViewRead = m_core.addFileData(m_filePathsCount[i]);
			if( m_tabListViewRead != 0 )
			{
				int tabIndex = ui.tabWidget->addTab(m_tabListViewRead, m_filePathsCount[i]);
				ui.tabWidget->setCurrentIndex(tabIndex);
				connect(m_tabListViewRead->verticalScrollBar(), &QScrollBar::valueChanged, this, &LogWatcher::appendFileData);
                
				/* Set the Context Menu */
				m_tabListViewRead->setContextMenuPolicy(Qt::CustomContextMenu);

				/* Connect the SLOT context menu */
				connect(m_tabListViewRead, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
			}
			else
			{
				QMessageBox::warning(this, "Error", "File not correspond to TypeLog");
			}
		}
	}
}

void LogWatcher::on_pushButtonOpenSearch_clicked()
{
    m_core.garbageRemove();

    /* Path we are looking at the header of the current tab */
    QString str = ui.tabWidget->tabText(ui.tabWidget->currentIndex());

	/* Dialog Box Invocation */
	SrchDlg serchWindow;
	serchWindow.setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

	if( serchWindow.exec() == QDialog::Accepted )
	{
		QStringList searchStrLstCount;
		QList<QVariant> numberOfcolorhStrLst;
		searchStrLstCount = serchWindow.searchString();
        numberOfcolorhStrLst = serchWindow.findComboBoxColor();
		if( str.isEmpty() ) {
			QMessageBox::warning(this, "Error", "File is empty");
			return;
		}
        if( pathLock.find(str) != pathLock.end() )
        {
            QMessageBox::warning(this, "Error", "File search or analyze is busy.");
            return;
        }
        else
        {
            pathLock.insert(str);
        }

        QListView* tabListView = m_core.addFileSearchData(str, searchStrLstCount, numberOfcolorhStrLst);
		if( tabListView != 0 )
		{
			int tabIndex = ui.tabWidget_2->addTab(tabListView, str);
			ui.tabWidget_2->setCurrentIndex(tabIndex);
            
            m_core.updateTabSearchAndModel(ui.tabWidget_2->currentIndex());
		}
		else
		{
            pathLock.erase(str);
			QMessageBox::warning(this, "Error", "File not correspond to TypeLog");
            return;
		}
	}
}

void LogWatcher::on_pushButtonAnalyz_clicked()
{
    m_core.garbageRemove();

    /* Path we are looking at the header of the current tab */
    QString str = ui.tabWidget->tabText(ui.tabWidget->currentIndex());
    if( pathLock.find(str) != pathLock.end() )
    {
        pathLock.erase(str);
        isAnalyzeRunning = false;
        QMessageBox::warning(this, "Error", "File search or analyze is busy.");
        return;
    }
    else
    {
        pathLock.insert(str);
    }
    if( isAnalyzeRunning )
    {
        QMessageBox::warning(this, "Error", "File analyze already running.");
        return;
    }
    else
    {
        isAnalyzeRunning = true;
    }

	QStringList analyzStrLstCount;
	QList<QVariant>  colorAllCount;
	if( ui.checkBoxInfo->isChecked() )
	{
		analyzStrLstCount.append(QString("(?:.*INFO)"));
		int c1 = ui.comboBoxInfo->currentIndex();
		colorAllCount.append(m_analyzClrCount.at(c1));
	}
	if( ui.checkBoxDebug->isChecked() )
	{
		analyzStrLstCount.append(QString("(?:.*DEBUG)"));
		int c2 = ui.comboBoxDebug->currentIndex();
		colorAllCount.append(m_analyzClrCount.at(c2));
	}
	if( ui.checkBoxWarning->isChecked() )
	{
		analyzStrLstCount.append(QString("(?:.*WARNING)"));
		int c3 = ui.comboBoxWarning->currentIndex();
		colorAllCount.append(m_analyzClrCount.at(c3));
	}
	if( ui.checkBoxError->isChecked() )
	{
		analyzStrLstCount.append(QString("(?:.*ERROR)"));
		int c4 = ui.comboBoxError->currentIndex();
		colorAllCount.append(m_analyzClrCount.at(c4));
	}
	if( !ui.checkBoxInfo->isChecked() && !ui.checkBoxDebug->isChecked() 
        && !ui.checkBoxWarning->isChecked() && !ui.checkBoxError->isChecked() )
	{
		analyzStrLstCount.append(QString("(?:\\s*)"));
        colorAllCount.append(QBrush(Qt::white));
	}
	if( str.isEmpty() ) 
    {
        pathLock.erase(str);
        isAnalyzeRunning = false;
		QMessageBox::warning(this, "Error", "File is empty");
		return;
	}

    QListView* tabListView = m_core.addFileAnalyzData(str, analyzStrLstCount, colorAllCount);
    if( tabListView != 0 )
    {
        int tabIndex = ui.tabWidget_2->addTab(tabListView, str);
        ui.tabWidget_2->setCurrentIndex(tabIndex);

        m_core.updateTabAnalyzAndModel(ui.tabWidget_2->currentIndex());
    }
    else
    {
        pathLock.erase(str);
        isAnalyzeRunning = false;
        QMessageBox::warning(this, "Error", "File not correspond to TypeLog");
        return;
    }
}

void LogWatcher::on_pushButtonEditData_clicked()
{
    if( isAnalyzeRunning )
    {
        QMessageBox::warning(this, "Error", "File analyze already running.");
        return;
    }
    QPointer<DataWidgetMapper> dataBase = new DataWidgetMapper(this);
    dataBase->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    dataBase->setAttribute(Qt::WA_DeleteOnClose);
    dataBase->show();
    connect(dataBase, SIGNAL(destroyed(QObject*)), this, SLOT(widgetDestroyed(QObject*)));
}

void LogWatcher::slotCustomMenuRequested(const QPoint& pos)
{
	/* Create a context menu object */
    QPointer<QMenu> menu = new QMenu();
    menu->setAttribute(Qt::WA_DeleteOnClose);

	/* Create actions for the context menu */
    QPointer<QAction> addDevice = new QAction(trUtf8("Add"));
    QPointer<QAction> findDevice = new QAction(trUtf8("Find"));

	/* We take out the original log by position */
	QString addLine;
	addLine.append(m_core.getFileDataListView(ui.tabWidget->currentIndex())->indexAt(pos).data(Qt::DisplayRole).toString());

	/* Delete line numbering */
	m_logOrig = addLine.section(". ", 1);

	/* We connect SLOT handlers for context menu actions */
	connect(addDevice, SIGNAL(triggered()), this, SLOT(slotCreateRecord()));
	connect(findDevice, SIGNAL(triggered()), this, SLOT(slotFindRecord()));

	/* Set the actions in the menu */
	menu->addAction(addDevice);
	menu->addAction(findDevice);

	/* Call the context menu */
	menu->popup(m_tabListViewRead->viewport()->mapToGlobal(pos));
}

void LogWatcher::slotCreateRecord()
{
    m_dwm.addLog(m_logOrig);
}

void LogWatcher::slotFindRecord()
{
    if( isAnalyzeRunning )
    {
        QMessageBox::warning(this, "Error", "File analyze already running.");
        return;
    }
    QPointer<DataWidgetMapper> dataBase = new DataWidgetMapper(this);
    dataBase->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    dataBase->setAttribute(Qt::WA_DeleteOnClose);
    dataBase->show();
    dataBase->findLog(m_logOrig);
    connect(dataBase, SIGNAL(destroyed(QObject*)), this, SLOT(widgetDestroyed(QObject*)));
}

void LogWatcher::on_tabWidget_tabCloseReguested(int index)
{
	ui.tabWidget->removeTab(index);
	m_core.removeFileData(index);
}

void LogWatcher::on_tabWidget_tabCloseReguestedSearch(int index)
{
	ui.tabWidget_2->removeTab(index);
	m_core.removeSearchAnalyzeFileData(index);
}
}