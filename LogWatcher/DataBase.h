#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QApplication>
#include <QMutex>
#include <QMutexLocker>

/* Directives for table names, table fields, and database */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"

#define DEVICE              "DeviceTable"
#define DEVICE_LOG          "Log"
#define DEVICE_COMMENT      "Comment"
#define DEVICE_TYPE         "Type"

namespace LogWatcher {
/* DataBase Class*/
class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject* parent = 0);
    ~DataBase();

    /* Methods for working directly with the class
     * Connect to a database and insert records into a table
     * */
    void connectToDataBase();
    void closeDataBase();

    /* The database object itself with which the work will be performed */
    QSqlDatabase m_db;

private:
    QMutex m_mutex;

    /* Internal methods for working with the database */
    bool openDataBase();
    bool restoreDataBase();
    bool createDeviceTable();
};
}
#endif // DATABASE_H
