#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

#include "requester.h"

class Messenger : public QObject
{
    Q_OBJECT
public:
    static Messenger *instance();

    // public API
    Q_INVOKABLE void signUp(const QString &name);

private slots:
    void handleResponse(QNetworkReply *reply, Requester::ApiType api); // Общий для всех ответов

private:
    explicit Messenger();
    void signUpReply(QNetworkReply *reply);

    Requester *m_requester;
};

#endif // MESSENGER_H
