#include "StreamPartFileSearcher.h"

namespace LogWatcher
{

/* Transaction Index */
extern std::set<QString> pathLock;
static const int bufferSize(4);

StreamPartFileSearcher::StreamPartFileSearcher()
{
	countBlockString = bufferSize;
	init();
    isStopped = false;
}
StreamPartFileSearcher::StreamPartFileSearcher(const QString& pathIn, const QStringList& regExpStrIn, const QList<QVariant>& colorStringIn)
{
	m_path = pathIn;
	m_regExpStrCount = regExpStrIn;
	m_colorStrCount = colorStringIn;
	countBlockString = bufferSize;
	m_checkerCount = -1;
	init();
    isStopped = false;
}

StreamPartFileSearcher::~StreamPartFileSearcher( )
{
    delete m_scrollBar;
    delete m_tabListView;
    delete m_stringListModel;
}

void StreamPartFileSearcher::init()
{
	if (!m_path.isEmpty())
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
		m_stringListModel = new MyStringListModel();
		m_tabListView = new QListView();
		m_scrollBar = new QScrollBar(Qt::Vertical);
		m_scrollBar->show();
		m_scrollBar->setMinimum(0);
		m_scrollBar->setMaximum(100);
		m_tabListView->verticalScrollBar();
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

int StreamPartFileSearcher::updateDataAndModel()
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
		if( m_stringListModel->rowCount() == 0 ) 
        {
			bool wasStartPoint = false;
			while( !m_file->atEnd() ) 
            {
				QTextCodec* codec = QTextCodec::codecForName("CP 1251");
				line = codec->toUnicode(m_file->readLine()).simplified();
				m_checkerCount += 1;
				if( isNewStringLog.indexIn(line) == 0 ) {
					backLine = line;
					isFirst = false;
					wasStartPoint = true;
					break;
				}
			}
			if( !wasStartPoint ) {
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
								m_stringCount += QString::number(m_checkerCount) + ". " + backLine;

								oldMaxRows = m_stringListModel->rowCount();
								m_stringListModel->insertRow(oldMaxRows);
								QModelIndex index = m_stringListModel->index(oldMaxRows);

								m_stringListModel->setStringList(m_stringCount);

								m_stringListModel->setData(index, m_colorStrCount.at(indx), Qt::ForegroundRole);
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
					m_stringCount += QString::number(m_checkerCount) + ". " + backLine;

					oldMaxRows = m_stringListModel->rowCount();
					m_stringListModel->insertRow(oldMaxRows);
					QModelIndex index = m_stringListModel->index(oldMaxRows);

					m_stringListModel->setStringList(m_stringCount);

					m_stringListModel->setData(index, m_colorStrCount.at(indx), Qt::ForegroundRole);
				}
			}
		}
	}
	return 0;
}

void StreamPartFileSearcher::stopThread( )
{
    isStopped = true;
}

int StreamPartFileSearcher::updateDataAndModelRun()
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
            QThread::sleep(1);
            flowControl = QtConcurrent::run(this, &StreamPartFileSearcher::updateDataAndModel);
            flowControl.waitForFinished();
        }
        
    }
    pathLock.erase(this->m_path);
	return 0;
}
}