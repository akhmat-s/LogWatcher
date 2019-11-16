#ifndef STREAMPARTFILEREADER_H
#define STREAMPARTFILEREADER_H

#include <qfile.h>
#include <qdebug.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qstringlistmodel.h>
#include <qlistview.h>
#include <qregexp.h>
#include <QRegularExpression>
#include <QTextCodec>


#include <qscrollbar.h>


namespace LogWatcher {
/* This class manages the tasks of reading the log file  */
class StreamPartFileReader
{
public:
	StreamPartFileReader();
	StreamPartFileReader(const QString& pathIn);
    ~StreamPartFileReader( );

    /* Public objects, interclass communication. */
	QString m_radioTypeLog;
	QListView * m_tabListView;

	/* Open & run file */
	void init();

	/* RegExp for stream file with type log  & Added ModelIndex */
	int updateDataAndModel();

private:
	QFile* m_file;
	QString m_path;
	QStringListModel* m_stringListModel;
	QScrollBar* m_scrollBar;
    int countBlockString;
    bool isAccept;
};
}
#endif // STREAMPARTFILEREADER_H