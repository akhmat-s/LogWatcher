#include "FileData.h"

namespace LogWatcher {
FileData::FileData()
{
    m_partReader = 0;
}

FileData::~FileData()
{
    delete m_partReader;
}

SearchAnalyzFileData::SearchAnalyzFileData()
{
    m_partSearcher = 0;
    m_partAnalyz = 0;
}

SearchAnalyzFileData::~SearchAnalyzFileData( )
{
    if( m_partSearcher != 0 )
    {
        delete m_partSearcher;
    }
    if( m_partAnalyz != 0 )
    {
        delete m_partAnalyz;
    }
}
}