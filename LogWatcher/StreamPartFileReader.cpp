#include "StreamPartFileReader.h"

namespace LogWatcher
{
static const int bufferSize(3000);
StreamPartFileReader::StreamPartFileReader()
{
	countBlockString = bufferSize;
	init();
}
StreamPartFileReader::StreamPartFileReader(const QString& pathIn)
{
	m_path = pathIn;
	countBlockString = bufferSize;
	init();
}
StreamPartFileReader::~StreamPartFileReader() 
{
    delete m_scrollBar;
    delete m_tabListView;
    delete m_stringListModel;
}

void StreamPartFileReader::init()
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
		m_stringListModel = new QStringListModel();
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
        m_tabListView->viewMode( );

        m_tabListView->setModel(m_stringListModel);
	}
	else
	{
		isAccept = false;
	}
}

int StreamPartFileReader::updateDataAndModel()
{
	if( isAccept )
	{
		int position = m_stringListModel->rowCount();
		int oldMaxRows;
		bool isFirst = true;
		QString line;
		QString backLine;
		QRegExp isNewStringLog;
		int searchStart = 0;
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
			while( !m_file->atEnd() && searchStart < 100 ) 
            {
                QTextCodec* codec = QTextCodec::codecForName("CP 1251");
                line = codec->toUnicode(m_file->readLine()).simplified();
				if( isNewStringLog.indexIn(line) == 0 ) 
                {
					backLine = line;
					isFirst = false;
					wasStartPoint = true;
					break;
				}
				else 
                {
					oldMaxRows = m_stringListModel->rowCount();
					m_stringListModel->insertRow(oldMaxRows);
					QModelIndex index = m_stringListModel->index(oldMaxRows);
                    line.toStdString();
					/* BackLine doing modify this before insert into view */
					m_stringListModel->setData(index, QString::number(m_stringListModel->rowCount()) + ". " + line);
				}
				searchStart++;
			}
			if( !wasStartPoint ) 
            {
				isAccept = false;
				return -1;
			}
		}
		for( size_t i = 0; i < countBlockString; i++ )
		{
			QTextCodec* codec = QTextCodec::codecForName("CP 1251");
			line = codec->toUnicode(m_file->readLine());

			if( !line.isEmpty() )
			{
				/* Information distribution in columns */
				if( isNewStringLog.indexIn(line) == 0 )
				{
					if( !isFirst )
					{
						oldMaxRows = m_stringListModel->rowCount();
						m_stringListModel->insertRow(oldMaxRows);
						QModelIndex index = m_stringListModel->index(oldMaxRows);

						/* backLine doing modify this before insert into view */
						m_stringListModel->setData(index, QString::number(m_stringListModel->rowCount()) + ". " + backLine.simplified());

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
					if( m_stringListModel->rowCount() == 0 )
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
			oldMaxRows = m_stringListModel->rowCount();
			m_stringListModel->insertRow(oldMaxRows);
			QModelIndex index = m_stringListModel->index(oldMaxRows);
			m_stringListModel->setData(index, QString::number(m_stringListModel->rowCount()) + ". " + backLine.simplified());
		}
	}
	return 0;
}
}