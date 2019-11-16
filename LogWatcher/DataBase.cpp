#include "DataBase.h"

namespace LogWatcher {
DataBase::DataBase(QObject* parent) : QObject(parent)
{
}

DataBase::~DataBase()
{
}

void DataBase::connectToDataBase()
{
	/* Before connecting to the database, we check for its existence.
	 * Depending on the result, we open the database or restore it
	 * */
	if( !QFile(QDir::toNativeSeparators(QApplication::applicationDirPath()) + "\\LogData\\" + DATABASE_NAME).exists() )
	{
		this->restoreDataBase();
	}
	else 
    {
		this->openDataBase();
	}
}

/* Database Recovery Methods
 * */
bool DataBase::restoreDataBase()
{
	if( this->openDataBase() )
	{
		if( !this->createDeviceTable() )
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		qDebug() << "Failed to restore database";
		return false;
	}
	return false;
}

/* Method for opening a database
 * */
bool DataBase::openDataBase()
{
    /* The database opens at a given path
     * and database name if it exists
     * */
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setHostName(DATABASE_HOSTNAME);
    m_db.setDatabaseName(QDir::toNativeSeparators(QApplication::applicationDirPath()) + "\\LogData\\" + DATABASE_NAME);

	if( m_db.open() )
    {
		return true;
	}
	else 
    {
		return false;
	}
}

/* Database Closing Methods
 * */
void DataBase::closeDataBase()
{
    m_db.close();
}

/* Method for creating a device table in a database
 * */
bool DataBase::createDeviceTable()
{
	/* In this case, the raw SQL query is used.
     * with its subsequent implementation.
     * */
	QSqlQuery query;
	if (!query.exec("CREATE TABLE " DEVICE " ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT, "
		DEVICE_LOG  " VARCHAR(3000)    NOT NULL,"
		DEVICE_COMMENT      " VARCHAR(800)     NOT NULL,"
		DEVICE_TYPE      " VARCHAR(18)     NOT NULL"
		" )"
	)) 
    {
		qDebug() << "DataBase: error of create " << DEVICE;
		qDebug() << query.lastError().text();
		return false;
	}
	else 
    {
		return true;
	}
	return false;
}
}