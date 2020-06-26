#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

#include "requester.h"

class Messenger : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userId READ userId NOTIFY userIdChanged)

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
    Q_INVOKABLE void signOut();

    QString userId() const;

signals:
    void error(MessengerError errorType);
    void userIdChanged(QString userId);

private slots:
    void handleResponse(QNetworkReply *reply); // Общий для всех ответов

private:
    void handleSignupResponse(QNetworkReply *reply);
    Requester::ApiType getApiType(const QUrl &url);
    void handleError(int code);
    void setUserId(QString userId);

    Requester *m_requester;
    QString m_userId;
};

#endif // MESSENGER_H
