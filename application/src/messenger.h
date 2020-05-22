#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

#include "requester.h"

class Messenger : public QObject
{
    Q_OBJECT
public:
    explicit Messenger();

    enum MessengerError {
        NoNetWorkConnect,
        NotFound,
        ServerNotAvailable,
    };
    Q_ENUM(MessengerError)

    // public API
    Q_INVOKABLE void signUp(const QString &name);

signals:
    void signUpComplete();
    void error(MessengerError errorType);

private slots:
    void handleResponse(QNetworkReply *reply, Requester::ApiType api); // Общий для всех ответов

private:
    void handleSignupResponse(QNetworkReply *reply);
    void handleError(int code);

    Requester *m_requester;
};

#endif // MESSENGER_H
