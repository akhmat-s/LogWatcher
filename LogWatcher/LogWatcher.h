#ifndef LOGWATCHER_H
#define LOGWATCHER_H

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <qstringlistmodel.h>
#include <QMessagebox>
#include <qfileinfo.h>
#include <QWidgetAction>
#include <QAction>
#include <QSplitter>
#include <QSlider>
#include <QToolButton>
#include <QDialog>
#include <QColor>
#include <QThread>
#include <QFuture>
#include <QCoreApplication>
#include <iostream>
#include <QtCore>
#include <QtConcurrent/QtConcurrent>
#include <QMenu>
#include <QAction>
#include <QTextCodec>
#include <QStandardItemModel>
#include <QStyleFactory>
#include <QPointer>
#include <set>

#include "ui_logwatcher.h"
#include "SrchDlg.h"
#include "Core.h"
#include "MyStringListModel.h"
#include "DataWidgetMapper.h"
#include "DataBase.h"

namespace LogWatcher {
/* GUI CLASS */
class LogWatcher : public QMainWindow
{
	Q_OBJECT
public:
	LogWatcher(QWidget* parent = Q_NULLPTR);
    ~LogWatcher( );

private slots:
	/* Open file */
	void on_pushButtonOpen_clicked();

	/* Append data from file, scroll */
	void appendFileData(int);

	/* Close tabs button */
	void on_tabWidget_tabCloseReguested(int index);
	void on_tabWidget_tabCloseReguestedSearch(int index);

	/* RadioButtons: type logs */
	void on_pushButtonNext_clicked();
	void on_pushButtonIntellect_clicked();

	/* Search */
	void on_pushButtonOpenSearch_clicked();

	/* Edit DataBase */
	void on_pushButtonEditData_clicked();

	/* Analyze */
	void on_pushButtonAnalyz_clicked();

	/* Context Menu */
	void slotCreateRecord();
	void slotFindRecord();
	void slotCustomMenuRequested(const QPoint& pos);

private:
    Ui::LogWatcherClass ui;
	Core m_core;
	DataWidgetMapper m_dwm;
	QListView* m_tabListViewRead;
	QStringList m_filePathsCount;
	QList<QVariant> m_analyzClrCount;
	QString m_logOrig;
    DataBase m_db;
};
}
#endif // LOGWATCHER_H