#include "StreamPartFileAnalyz.h"

namespace LogWatcher
{

/* Transaction Index */
extern std::set<QString> pathLock;

/* Analysis Transaction Index and Database */
extern bool isAnalyzeRunning;
static const int bufferSize(4);

StreamPartFileAnalyz::StreamPartFileAnalyz()
{
	countBlockString = bufferSize;
	init();
    isStopped = false;
}

StreamPartFileAnalyz::StreamPartFileAnalyz(const QString& pathIn, const QStringList& regExpStrIn, const QList<QVariant>& colorStringIn)
{
	m_path = pathIn;
	m_regExpStrCount = regExpStrIn;
	m_colorStrCount = colorStringIn;
	countBlockString = bufferSize;
	m_checkerCount = -1;
	m_lineItemCount = -1;
	init();
    isStopped = false;
}

StreamPartFileAnalyz::~StreamPartFileAnalyz()
{    
    delete m_scrollBar;
    delete m_tabListView;
    delete m_stringListModel;
}

void StreamPartFileAnalyz::init()
{
	if( !m_path.isEmpty() )
	{
		m_file = new QFile(m_path);
	}
	else
	{
		isAccept = false;
		return;
	}
	if( m_file->open(QIODevice::ReadOnly | QIODevice::Text) )
	{
		isAccept = true;
		m_stringListModel = new QStandardItemModel();
		m_tabListView = new QListView();
		m_scrollBar = new QScrollBar(Qt::Vertical);
		m_scrollBar->setMinimum(0);
		m_scrollBar->setMaximum(100);
		m_tabListView->setVerticalScrollBar(m_scrollBar);
		m_tabListView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

		/* Rows style */
		m_tabListView->setStyleSheet("QListView::item:!selected{ border-bottom: 1px solid black; padding: 0px; height: 20%; position: absolute;}");

		/* Elements will be placed each time the view is resized. */
		m_tabListView->setResizeMode(QListView::Adjust);
		m_tabListView->setViewMode(QListView::ListMode);

        /* This property holds whether selections are done in terms of single items, rows or columns. */
        m_tabListView->setSelectionBehavior(QAbstractItemView::SelectRows);

        /* When the user selects an item, any already-selected item becomes unselected. */
        m_tabListView->setSelectionMode(QAbstractItemView::SingleSelection);

        /* Not Edit Rows */
        m_tabListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        /* This enables the view to do some optimizations for performance purposes. */
        m_tabListView->setUniformItemSizes(true);

        /* This property will change the other unset properties to conform with the set view mode */
        m_tabListView->viewMode();

        m_tabListView->setModel(m_stringListModel);
	}
	else
	{
		isAccept = false;
	}
}

int StreamPartFileAnalyz::updateDataAndModel()
{
	if( isAccept )
	{
		int oldMaxRows;
		bool isFirst = true;
		QString line;
		QString backLine;
		QRegExp isNewStringLog;
		if( m_radioTypeLog == "Next" )
		{
			isNewStringLog.setPattern("~\\s*");
		}
		else if( m_radioTypeLog == "Intellect" )
		{
			isNewStringLog.setPattern("\\[CPU\\=\\d{4}\\]\\s*");
		}
		else 
        {
			/* By default Next */
			isNewStringLog.setPattern("~\\s*");
		}
		if (m_stringListModel->rowCount() == 0) 
        {
			bool wasStartPoint = false;
			while ( !m_file->atEnd() ) 
            {
				QTextCodec* codec = QTextCodec::codecForName("CP 1251");
				line = codec->toUnicode(m_file->readLine()).simplified();
				m_checkerCount += 1;
				if( isNewStringLog.indexIn(line) == 0 ) 
                {
					backLine = line;
					isFirst = false;
					wasStartPoint = true;
					break;
				}
			}
			if( !wasStartPoint ) 
            {
				isAccept = false;
				return -1;
			}
		}

		for( size_t i = 0; i < countBlockString && !m_file->atEnd(); )
		{
			QTextCodec* codec = QTextCodec::codecForName("CP 1251");
			line = codec->toUnicode(m_file->readLine());
			if( !line.isEmpty() )
			{
				if( isNewStringLog.indexIn(line) == 0 )
				{
					if( !isFirst )
					{
						m_checkerCount += 1;

						/* If you entered here, the backLine would go to GUI. */
						backLine = backLine.simplified();
						for( size_t indx = 0; indx < m_regExpStrCount.size(); ++indx )
						{

							QRegExp regExp(m_regExpStrCount.at(indx), Qt::CaseInsensitive);
							if( regExp.indexIn(backLine) == 0 )
							{
                                QString logCom = analyzLog(backLine, m_radioTypeLog);

								if( !logCom.isEmpty() )
								{
									logCom.toStdString();
									m_lineItemCount += 1;

									QStandardItem* item = new QStandardItem();
									item->setData(QString::number(m_checkerCount) + ". " + backLine, Qt::DisplayRole);
									item->setForeground(m_colorStrCount.at(indx).value<QColor>());
									item->setToolTip(logCom);

									m_stringListModel->setItem(m_lineItemCount, 0, item);
								}
								i++;
							}
						}
						backLine = line;
					}
					else
					{
						backLine = line;
						isFirst = false;
					}
				}
				else 
                {
					if( m_stringListModel->rowCount() == 0 && m_checkerCount == 0 )
					{
						isAccept = false;
						return -1;
					}
					backLine += line;
				}
			}
		}
		if( !backLine.isEmpty() )
		{
			m_checkerCount += 1;
			backLine = backLine.simplified();
			for( size_t indx = 0; indx < m_regExpStrCount.size(); ++indx )
			{
				QRegExp regExp(m_regExpStrCount.at(indx), Qt::CaseInsensitive);
				if( regExp.indexIn(backLine) == 0 )
				{
                    QString logCom = analyzLog(backLine, m_radioTypeLog);

					if( !logCom.isEmpty() )
					{
						logCom.toStdString();
						m_lineItemCount += 1;

						QStandardItem* item = new QStandardItem();
						item->setData(QString::number(m_checkerCount) + ". " + backLine, Qt::DisplayRole);
						item->setForeground(m_colorStrCount.at(indx).value<QColor>());
						item->setToolTip(logCom);

						m_stringListModel->setItem(m_lineItemCount, 0, item);
					}
				}
			}
		}
	}
	return 0;
}

void StreamPartFileAnalyz::stopThread()
{
    isStopped = true;
}

int StreamPartFileAnalyz::updateDataAndModelRun()
{
    QFuture<int> flowControl;
	for( int i = 0; !m_file->atEnd(); i++ )
	{
        if( this->isStopped )
        {
            break;
            return 1;
        }
        else
        {
            flowControl = QtConcurrent::run(this, &StreamPartFileAnalyz::updateDataAndModel);
            flowControl.waitForFinished( );
        }
	}
    pathLock.erase(this->m_path);
    isAnalyzeRunning = false;
	return 0;
}

QString StreamPartFileAnalyz::analyzLog(const QString& logIn, const QString& typeIn)
{
    m_dataBaseAnalyze.connectToDataBase(); 
    QSqlQuery query(m_dataBaseAnalyze.m_db);
    if( typeIn == "Next" )
    {
        query.prepare("SELECT Comment FROM DeviceTable WHERE Type = 1 AND Log = :Log ");
    }
    else
    {
        query.prepare("SELECT Comment FROM DeviceTable WHERE Type = 0 AND Log = :Log ");
    }

    query.bindValue(":Log", logIn);
    query.exec();
    query.next();
    QString comment = query.value(0).toString();
    m_dataBaseAnalyze.closeDataBase();

    return comment; 
}
}
