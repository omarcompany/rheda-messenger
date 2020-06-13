#ifndef UUIDMANAGER_H
#define UUIDMANAGER_H

#include <QObject>

class UuidManager : public QObject
{
    Q_OBJECT
public:
    explicit UuidManager(QObject *parent = nullptr);

    Q_INVOKABLE bool exists();
    Q_INVOKABLE void clear();

    static QString getId();

    static void create(const QString &id);
};

#endif // UUIDMANAGER_H
