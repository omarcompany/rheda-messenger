#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QObject>

struct Message;

class Serializer : public QObject
{
public:
    Serializer() = delete;

    static QString getId(const QByteArray &jsonData);
    static QList<Message> deserializeToMessageList(const QByteArray &jsonData);
};

#endif // SERIALIZER_H
