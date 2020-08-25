#ifndef MESSANGE_H
#define MESSANGE_H

#include <QString>
#include <QDateTime>

struct Message
{
    Message() = default;

    Message(QString authorName, QString authorId, QString timestamp, QString text)
    {
        this->authorName = authorName;
        this->authorId = authorId;
        this->timestamp = QDateTime::fromString(timestamp, Qt::ISODate);
        this->text = text;
    }

    bool isValid() const {
        if (authorId.isEmpty() || timestamp.isNull() || text.isEmpty()) {
            return false;
        }
        return true;
    }

    QString authorName;
    QString authorId;
    QDateTime timestamp;
    QString text;
};

#endif // MESSANGE_H
