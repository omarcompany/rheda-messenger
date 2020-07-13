#include "databaseengine.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <QSql>
#include <QSqlQuery>

#include "message.h"

Q_GLOBAL_STATIC(DatabaseEngine, databaseEngineInstance)

static const QString DATABASE_LOCATION =
        QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/Database";

DatabaseEngine::DatabaseEngine()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseEngine::~DatabaseEngine()
{
}

DatabaseEngine *DatabaseEngine::instance()
{
    return databaseEngineInstance();
}

bool DatabaseEngine::createDatabase(const User &user)
{
    QDir way;
    way.mkpath(DATABASE_LOCATION);
    m_database.setDatabaseName(DATABASE_LOCATION + "/" + user.id + ".db");
    m_database.open();
    QSqlQuery query(m_database);
    QString userTable    = "CREATE TABLE IF NOT EXISTS User(id TEXT, name TEXT)";
    QString messageTable = "CREATE TABLE IF NOT EXISTS Messages"
                           "(authorName TEXT, authorId TEXT, timestamp TEXT, text TEXT)";
    if (query.exec(userTable) && query.exec(messageTable)) {
        refreshTable(user);
        return true;
    }
    m_database.close();
    qDebug() << "Data are not entered";
    return false;
}

User DatabaseEngine::getUser()
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        if (query.exec("SELECT * FROM user")) {
            while (query.next()) {
                User user;
                user.id   = query.value(0).toString();
                user.name = query.value(1).toString();
                return user;
            }
        }
    }
    return User();
}

bool DatabaseEngine::open(const User &user)
{
    if (!user.isValid()) {
        qDebug() << "The User structure is incomplete";
        return false;
    }
    if (open(user.id)) {
        return true;
    }
    if (createDatabase(user)) {
        return true;
    }
    return false;
}

bool DatabaseEngine::open(const QString &userId)
{
    if (m_database.isOpen()) {
        qDebug() << "The database is open";
        return false;
    }
    if (userId.isEmpty()) {
        qDebug() << "The user id is empty";
        return false;
    }
    QString databasePath = DATABASE_LOCATION + "/" + userId + ".db";
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
    return false;
}

QList<Message> DatabaseEngine::getMessageList() const
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        if (query.exec("SELECT * FROM messages")) {
            QList<Message> messageList;
            while (query.next()) {
                Message message;
                message.authorName = query.value(AuthorName).toString();
                message.authorId   = query.value(AuthorId).toString();
                message.timestamp  = QDateTime::fromString(query.value(Timestamp).toString(), Qt::ISODate);
                message.text       = query.value(Text).toString();
                messageList << message;
            }
            return messageList;
        }
    }
    return QList<Message>();
}

void DatabaseEngine::refreshTable(const User &user)
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        query.prepare("INSERT INTO User(id, name) "
                      "VALUES(?, ?);");
        query.addBindValue(user.id);
        query.addBindValue(user.name);
        if (!query.exec()) {
            qDebug() << "The database was not filled";
        }
    }
}

void DatabaseEngine::refreshTable(const QList<Message> messageList)
{
    if (m_database.isOpen()) {
        QSqlQuery query(m_database);
        query.prepare("DELETE FROM Messages");
        if (query.exec()) {
            for (auto message : messageList) {
                if (!message.isValid()) {
                    //To Solve the problem with incomplete filling of the table
                    //To do
                    continue;
                }
                query.prepare("INSERT INTO Messages(authorName, authorId, timestamp, text) "
                              "VALUES(?, ?, ?, ?);");
                query.addBindValue(message.authorName);
                query.addBindValue(message.authorId);
                query.addBindValue(message.timestamp);
                query.addBindValue(message.text);
                if (!query.exec()) {
                    qDebug() << "The database was not filled";
                }
            }
            emit dataChanged();
        } else {
            qDebug() << "The database was not cleaned";
        }
    }
}

void DatabaseEngine::close()
{
    if (m_database.isOpen()) {
        m_database.close();
    }
}

bool DatabaseEngine::isValid()
{
    QStringList tablesList = m_database.tables();
    if (tablesList.contains("User") && tablesList.contains("Messages")) {
        return true;
    }
    return false;
}
