#ifndef CORE_H
#define CORE_H

#include <qlist.h>
#include <qstring.h>
#include <QListView>
#include <QThread>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>

#include "FileData.h"

namespace LogWatcher {
/* Class responsible for creating and distributing tasks */
class Core
{
public:
    Core();
    ~Core();

    /* Length check */
    bool isFileExist(const QString& pathIn);

    /* Add data to ListView */
    QListView* addFileData(const QString& pathIn);
    QListView* addFileSearchData(const QString& pathIn, const QStringList& stringSearchIn, const QList<QVariant>& colorStringIn);
    QListView* addFileAnalyzData(const QString& pathIn, const QStringList& stringSearchIn, const QList<QVariant>& colorStringIn);

    /* We take out the original log by position */
    QListView* getFileDataListView(const int indexIn);

    /* Update data from ModelIndex */
    int updateTabDataAndModel(int pathIn);
    int updateTabSearchAndModel(int pathIn);
    int updateTabAnalyzAndModel(int pathIn);

    /* RadioButton set type */
    int setRadioTypeLog(const QString& typeIn);

    /* Clear data after close tab */
    int removeFileData(int indx);
    int removeSearchAnalyzeFileData(int indx);

    /* Clearing streaming memory after closing tabs */
    void garbageRemove();

private:
    QString m_radioTypeLog;
    QList<FileData *> m_numberOfFileData;
    QList<SearchAnalyzFileData *> m_numberOfSearchAnalyzeFileData;
    QList<SearchAnalyzFileData *> m_numberOfSearchAnalyzeFileDataRemove;
    int m_threadCount;
};
}
#endif // CORE_H
