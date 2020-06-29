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
    User getUser();
    bool openDatabase(const User &user);
    void refreshTable(const QList<Message>);
    QList<Message> getMessageList();
    void closeDatabase();

signals:
    void dataChanged();

private:
    enum MessagePart {
        AuthorName,
        AuthorId,
        Timestamp,
        Text
    };

    bool createDatabase(const User &user);
    void refreshTable(const User &user);
    bool isValid();

    QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
