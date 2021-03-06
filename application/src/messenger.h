#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

#include "requester.h"

class DatabaseEngine;

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
    Q_INVOKABLE void sendMessage(const QString &recipientId, const QString &text);
    Q_INVOKABLE void requestMessageList(const QString &recipientId) const;
    Q_INVOKABLE void requestUserList();

    QString userId() const;

signals:
    void error(MessengerError errorType);
    void userIdChanged(QString userId);

private slots:
    void handleResponse(QNetworkReply *reply); // Общий для всех ответов

private:
    void handleSignupResponse(QNetworkReply *reply);
    void handleRequestMessageListResponse(QNetworkReply *reply);
    void handleRequestUserListResponse(QNetworkReply *reply);
    void handleError(int code);
    void setUserId(QString userId);

    Requester *m_requester;
    QString m_userId;
};

#endif // MESSENGER_H
