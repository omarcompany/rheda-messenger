#ifndef UUIDMANAGER_H
#define UUIDMANAGER_H

#include <QObject>

class UUIDManager : public QObject
{
    Q_OBJECT
public:
    explicit UUIDManager(QObject *parent = nullptr);

    static bool exists();
    static void create(const QString &id);
    static void clear();
};

#endif // UUIDMANAGER_H
