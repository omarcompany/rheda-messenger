#ifndef UUIDMANAGER_H
#define UUIDMANAGER_H

#include <QObject>

class UuidManager : public QObject
{
    Q_OBJECT
public:
    explicit UuidManager(QObject *parent = nullptr);

    static void clear();
    static bool exists();
    static QString getId();
    static void create(const QString &id);
};

#endif // UUIDMANAGER_H
