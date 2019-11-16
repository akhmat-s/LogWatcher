#ifndef DATAWIDGETMAPPER_H
#define DATAWIDGETMAPPER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QPoint>
#include <QMenu>
#include <QAction>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QWidget>
#include <QPointer>

#include "DataBase.h"
#include "DlgComment.h"
#include "DlgEdit.h"
#include "ui_DataWidgetMapper.h"

namespace LogWatcher {
/* The class is responsible for managing database interaction processes. */
class DataWidgetMapper : public QWidget
{
    Q_OBJECT

public:
    explicit DataWidgetMapper(QWidget* parent = Q_NULLPTR);
    ~DataWidgetMapper();

    /* Add new log in DataBase */
    void addLog(const QString& logIn);

    /* Find log in DataBase */
    void findLog(const QString& logIn);

private slots:
    void slotUpdateModels();
    void slotEditRecord();
    void slotRemoveRecord();
    void slotCustomMenuRequested(const QPoint& pos);

private:
    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();

    Ui::DataWidgetMapper ui;
    DataBase m_db;
    QSqlTableModel* m_modelDevice;
};
}
#endif // DATAWIDGETMAPPER_H
