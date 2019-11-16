#ifndef STREAMPARTFILESEARCHER_H
#define STREAMPARTFILESEARCHER_H

#include <qfile.h>
#include <qdebug.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qstringlistmodel.h>
#include <qlistview.h>
#include <qregexp.h>
#include <qscrollbar.h>
#include <iostream>
#include <sstream>
#include <string>
#include <QBrush>
#include <QColor>
#include <QMap>
#include <QVariant>
#include <QTextCodec>

#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QThreadPool>
#include <Future>
#include <QRunnable>
#include <set>

#include "MyStringListModel.h"

namespace LogWatcher {

class StreamPartFileSearcher 
{
/* This class manages the tasks of searching by the log file.  */
public:
	StreamPartFileSearcher();
	StreamPartFileSearcher(const QString& pathIn, const QStringList& regExpStrIn, const QList<QVariant>& colorStringIn);
    ~StreamPartFileSearcher( );

    /* Public objects, interclass communication. */
	QString m_radioTypeLog;
	QListView* m_tabListView;
    bool isStopped;

	/* Open & run file */
	void init();

	/* RegExp for stream file with type log  & Added ModelIndex */
	int updateDataAndModel();
	int updateDataAndModelRun();

    /* Signal for stop thread */
    void stopThread();

private:
	QFile* m_file;
	QString m_path;
	int m_checkerCount;
	QStringList m_regExpStrCount;
	QList<QVariant> m_colorStrCount;
	QStringList m_stringCount;
	MyStringListModel* m_stringListModel;
	QScrollBar* m_scrollBar;
    int countBlockString;
    bool isAccept;
};
}
#endif // STREAMPARTFILESEARCHER_H