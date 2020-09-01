#ifndef DATABASEENGINE_H
#define DATABASEENGINE_H

#include <QObject>
#include <QSqlDatabase>

#include "user.h"

class Message;
class DatabaseEngine : public QObject
{
    Q_OBJECT
public:
    DatabaseEngine();
    ~DatabaseEngine();

    static DatabaseEngine *instance();

    User getUser();
    QList<User> getUserList();
    bool open(const User &user);
    bool open(const QString &userId);
    void refreshTable(const QList<Message>);
    void refreshTable(const QList<User> &userList);
    QList<Message> getMessageList() const;
    void close();

signals:
    void dataChanged();

private:
    enum class MessagePart {
        AuthorName,
        AuthorId,
        Timestamp,
        Text,
    };

    enum class UserPart {
        Id,
        Name,
    };

    bool createDatabase(const User &user);
    void refreshTable(const User &user);
    bool isValid();

    QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
