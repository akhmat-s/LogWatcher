#ifndef STREAMPARTFILEANALYZ_H
#define STREAMPARTFILEANALYZ_H

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
#include <QStandardItemModel>
#include <QTextDocumentWriter>
#include <QTextEdit>

#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QThreadPool>
#include <Future>
#include <QRunnable>
#include <QMutex>
#include <set>

#include "DataBase.h"

namespace LogWatcher {
/* This class manages the tasks of comparing the log file and database.  */
class StreamPartFileAnalyz
{
public:
	StreamPartFileAnalyz();
	StreamPartFileAnalyz(const QString& pathIn, const QStringList& regExpStrIn, const QList<QVariant>& colorStringIn);
	~StreamPartFileAnalyz();

    /* Public objects, interclass communication. */
	QString m_radioTypeLog;
	QListView* m_tabListView;
    bool isStopped;

	/* Open & run file */
	void init();

	/* RegExp for stream file with type log  & Added ModelIndex */
	int updateDataAndModel();
	int updateDataAndModelRun();

    /* Analyze log file with DataBase */
    QString analyzLog(const QString& logIn, const QString& typeIn);

    /* Signal for stop thread */
    void stopThread();

private:
	QFile* m_file;
	QString m_path;
	int m_checkerCount;
	int m_lineItemCount;
	QList<QVariant> m_colorStrCount;
	QStandardItemModel* m_stringListModel;
	QScrollBar* m_scrollBar;
    DataBase m_dataBaseAnalyze;
    QSqlDatabase m_data;
    QStringList m_regExpStrCount;
    QMutex m_cancelMutex;
    int countBlockString;
    bool isAccept;
};
}

#endif // STREAMPARTFILEANALYZ_H