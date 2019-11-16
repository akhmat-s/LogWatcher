#ifndef FILEDATA_H
#define FILEDATA_H

#include <qstring.h>
#include <qstringlist.h>
#include <qstringlistmodel.h>
#include <qlistview.h>

#include "StreamPartFileReader.h"
#include "StreamPartFileSearcher.h"
#include "StreamPartFileAnalyz.h"

/* Projection Data Module from GUI
 * Primary storage control
 * */

namespace LogWatcher {
/* Read File TabWidget */
class FileData
{
public:
    FileData();
    ~FileData();

    QString m_path;
    StreamPartFileReader* m_partReader;
};

/* Search & Analyze File TabWidget */
class SearchAnalyzFileData
{
public:
    SearchAnalyzFileData();
    ~SearchAnalyzFileData();

    QString m_path;
    StreamPartFileSearcher* m_partSearcher;
    StreamPartFileAnalyz* m_partAnalyz;
};
}
#endif // FILEDATA_H