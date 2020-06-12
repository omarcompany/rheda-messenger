#include "databaseengine.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <QSql>
#include <QSqlQuery>

static const QString DATABASE_LOCATION = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) +
        "/Database";

DatabaseEngine::DatabaseEngine()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
}

bool DatabaseEngine::createDatabase(const User &user)
{
    QDir way;
    way.mkpath(DATABASE_LOCATION);
    m_database.setDatabaseName(DATABASE_LOCATION + "/" + user.id + ".db");
    m_database.open();
    if (!initTableUser(user)) {
        qDebug() << "Data are not entered";
        return false;
    }
    return true;
}

User DatabaseEngine::getUser()
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        if (query.exec("SELECT * FROM user")) {
            while (query.next()) {
                QString currentId = query.value(0).toString();
                QString currentLogin = query.value(1).toString();
                return User(currentId, currentLogin);
            }
        }
    }
    return User();
}

bool DatabaseEngine::openDatabase(const User &user)
{
    if (!user.isValid()) {
        qDebug() << "The User structure is incomplete";
        return false;
    }
    if (m_database.isOpen()) {
        qDebug() << "The database is open";
        return false;
    }
    QString databasePath = DATABASE_LOCATION + "/" + user.id + ".db";
    if (QFile::exists(databasePath)) {
        m_database.setDatabaseName(databasePath);
        if (m_database.isValid()) {
            m_database.open();
            if (isValid()) {
                return true;
            }
            m_database.close();
        }
        QFile::remove(databasePath);
    }
    if (createDatabase(user)) {
        return true;
    }
    return false;
}

void DatabaseEngine::closeDatabase()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

bool DatabaseEngine::initTableUser(const User &user)
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        QString newTable = "CREATE TABLE IF NOT EXISTS User(id TEXT, name TEXT)";
        if (query.exec(newTable)) {
            query.prepare("INSERT INTO User(id, name) "
                          "VALUES(?, ?);");
            query.addBindValue(user.id);
            query.addBindValue(user.name);
            if (query.exec()) {
                return true;
            }
        }
    }
    return false;
}

bool DatabaseEngine::isValid()
{
    QStringList tablesList = m_database.tables();
    if (tablesList.contains("User")) {
        return true;
    }
    return false;
}
