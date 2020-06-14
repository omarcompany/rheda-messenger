#ifndef DATABASEENGINE_H
#define DATABASEENGINE_H

#include <QObject>
#include <QSqlDatabase>

#include "user.h"

class DatabaseEngine
{
public:
    DatabaseEngine();
    User getUser();
    bool openDatabase(const User &user);
    void closeDatabase();

private:
    bool createDatabase(const User &user);
    bool initTableUser(const User &user);
    bool isValid();

    QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
