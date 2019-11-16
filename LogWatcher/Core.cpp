#include "Core.h"

namespace LogWatcher {

/* Transaction Index */
extern std::set<QString> pathLock;
/* Analysis Transaction Index and Database */
extern bool isAnalyzeRunning;

Core::Core()
{
	this->m_radioTypeLog = "Next";
    
    /* Auto count max size of flows */
    m_threadCount = QThread::idealThreadCount();
    QThreadPool::globalInstance()->setMaxThreadCount(m_threadCount);
}

Core::~Core()
{
    for( QList<FileData *>::iterator i = m_numberOfFileData.begin(); i != m_numberOfFileData.end(); i++ )
    {
        delete (*i);
    }
    for( QList<SearchAnalyzFileData *>::iterator i = m_numberOfSearchAnalyzeFileData.begin();
        i != m_numberOfSearchAnalyzeFileData.end( ); i++ )
    {
        delete (*i);
    }
}

bool Core::isFileExist(const QString& pathIn)
{
    for( size_t i = 0; i < m_numberOfFileData.length(); i++ )
    {
        if( m_numberOfFileData[i]->m_path == pathIn )
        {
            return true;
        }
    }
    return false;
}

QListView* Core::addFileData(const QString& pathIn)
{
	FileData* data = new FileData();
	data->m_path = pathIn;
	data->m_partReader = new StreamPartFileReader(pathIn);
	data->m_partReader->m_radioTypeLog = this->m_radioTypeLog;
	int retError = data->m_partReader->updateDataAndModel();
	if( retError != 0 )
	{
		return 0;
	}
	m_numberOfFileData.append(data);
	return data->m_partReader->m_tabListView;
}

QListView* Core::getFileDataListView(const int indexIn)
{
    return m_numberOfFileData[indexIn]->m_partReader->m_tabListView;
}

QListView* Core::addFileSearchData(const QString& pathIn, const QStringList& stringSearchIn, const QList<QVariant>& colorStringIn)
{
    SearchAnalyzFileData* data = new SearchAnalyzFileData();
    data->m_path = pathIn;
    data->m_partSearcher = new StreamPartFileSearcher(pathIn, stringSearchIn, colorStringIn);
    data->m_partSearcher->m_radioTypeLog = this->m_radioTypeLog;
    int retError = data->m_partSearcher->updateDataAndModel();
    if( retError != 0 )
    {
	    return 0;
    }
    m_numberOfSearchAnalyzeFileData.append(data);
    return data->m_partSearcher->m_tabListView;
}

QListView*  Core::addFileAnalyzData(const QString& pathIn, const QStringList& stringSearchIn, const QList<QVariant>& colorStringIn)
{
	SearchAnalyzFileData * data = new SearchAnalyzFileData();
	data->m_path = pathIn;
	data->m_partAnalyz = new StreamPartFileAnalyz(pathIn, stringSearchIn, colorStringIn);
	data->m_partAnalyz->m_radioTypeLog = this->m_radioTypeLog;
	int retError = data->m_partAnalyz->updateDataAndModel();
	if( retError != 0 )
	{
		return 0;
	}
	m_numberOfSearchAnalyzeFileData.append(data);
	return data->m_partAnalyz->m_tabListView;
}

int Core::updateTabDataAndModel(int pathIn)
{
    m_numberOfFileData[pathIn]->m_partReader->updateDataAndModel();
    return 0;
}

int Core::updateTabSearchAndModel(int pathIn)
{
    garbageRemove();
    QtConcurrent::run(m_numberOfSearchAnalyzeFileData[pathIn]->m_partSearcher, &StreamPartFileSearcher::updateDataAndModelRun);
    return 0;
}

int Core::updateTabAnalyzAndModel(int pathIn)
{
    garbageRemove();
    QtConcurrent::run(m_numberOfSearchAnalyzeFileData[pathIn]->m_partAnalyz, &StreamPartFileAnalyz::updateDataAndModelRun);
    return 0;
}

int Core::setRadioTypeLog(const QString& typeIn) 
{
    m_radioTypeLog = typeIn;
    return 0;
}

int Core::removeFileData(int indx)
{
    delete m_numberOfFileData.at(indx);
    m_numberOfFileData.removeAt(indx);
    return 0;
}

int Core::removeSearchAnalyzeFileData(int indx)
{
    if( m_numberOfSearchAnalyzeFileData[indx]->m_partAnalyz != 0 )
    {
        m_numberOfSearchAnalyzeFileData[indx]->m_partAnalyz->stopThread();
    }
    else if( m_numberOfSearchAnalyzeFileData[indx]->m_partSearcher != 0 )
    {
        m_numberOfSearchAnalyzeFileData[indx]->m_partSearcher->stopThread();
    }
    m_numberOfSearchAnalyzeFileDataRemove.append((m_numberOfSearchAnalyzeFileData.at(indx)));
    m_numberOfSearchAnalyzeFileData.removeAt(indx);
    return 0;
}

void Core::garbageRemove()
{
    for( int i = 0; i != m_numberOfSearchAnalyzeFileDataRemove.size(); i++ )
    {
        if( m_numberOfSearchAnalyzeFileDataRemove.at(i)->m_partAnalyz != 0 )
        {
            if( m_numberOfSearchAnalyzeFileDataRemove.at(i)->m_partAnalyz->isStopped )
            {
                delete m_numberOfSearchAnalyzeFileDataRemove.at(i);
                m_numberOfSearchAnalyzeFileDataRemove.removeAt(i);
                i--;
                isAnalyzeRunning = false;
            }
        }
        else if( m_numberOfSearchAnalyzeFileDataRemove.at(i)->m_partSearcher != 0 )
        {
            if( m_numberOfSearchAnalyzeFileDataRemove.at(i)->m_partSearcher->isStopped )
            {
                delete m_numberOfSearchAnalyzeFileDataRemove.at(i);
                m_numberOfSearchAnalyzeFileDataRemove.removeAt(i);
                i--;
            }
        }
    }
}
}