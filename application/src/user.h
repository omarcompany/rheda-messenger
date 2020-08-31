#ifndef USER_H
#define USER_H

#include <QString>

struct User {
    User() = default;
    User(const QString &id, const QString &name)
    {
        this->id = id;
        this->name = name;
    }

    bool isValid() const {
        if (id.isEmpty() || name.isEmpty())
            return false;
        return true;
    }

    QString id;
    QString name;
};

#endif // USER_H
