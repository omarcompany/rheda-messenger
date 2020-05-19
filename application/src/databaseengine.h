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
    void openDatabase(const User &user);
    void closeDatabase();

private:
    void createDatabase(const User &user);
    bool initTableUser(const User &user);
    bool isValid();

    QSqlDatabase m_database;
};

#endif // DATABASEENGINE_H
