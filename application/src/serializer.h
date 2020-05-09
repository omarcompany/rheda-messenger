#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QObject>

class Serializer : public QObject
{
public:
    Serializer(QObject *parent = nullptr);

    static QString getId(const QByteArray &jsonData);
};

#endif // SERIALIZER_H
