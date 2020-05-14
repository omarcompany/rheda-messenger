#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

#include "requester.h"

class Messenger : public QObject
{
    Q_OBJECT
public:
    explicit Messenger();

    // public API
    Q_INVOKABLE void signUp(const QString &name);

signals:
    void signUpComplete();

private slots:
    void handleResponse(QNetworkReply *reply, Requester::ApiType api); // Общий для всех ответов

private:
    void handleSignupResponse(QNetworkReply *reply);

    Requester *m_requester;
};

#endif // MESSENGER_H
