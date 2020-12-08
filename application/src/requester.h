#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;

class Requester : public QObject
{
    Q_OBJECT
public:

    enum ApiUrl {
        SIGN_UP,
        SEND_MESSAGE,
        REQUEST_MESSAGE_LIST,
        REQUEST_USER_LIST,
        /*Add here new API*/
    };

    enum RequestType {
        GET,
        POST,
        PUT,
        DELETE
    };

    explicit Requester(QObject *parent = nullptr);

    void sendRequest(const Requester::RequestType type, const Requester::ApiUrl api, const QVariantMap &jsonData);
    static QString apiUrlToString(Requester::ApiUrl api);
    static ApiUrl stringToApiUrl(const QString &url);

signals:
    void replied(QNetworkReply *reply);

private:
    QNetworkRequest createRequest(const Requester::ApiUrl &api);

    QNetworkAccessManager *m_manager;
};

#endif // REQUEST_H
