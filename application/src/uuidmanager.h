#ifndef UUIDMANAGER_H
#define UUIDMANAGER_H

#include <QObject>

class UUIDManager : public QObject
{
    Q_OBJECT
public:
    explicit UUIDManager(QObject *parent = nullptr);

    Q_INVOKABLE bool exists();
    Q_INVOKABLE void clear();

    static void create(const QString &id);
};

#endif // UUIDMANAGER_H
