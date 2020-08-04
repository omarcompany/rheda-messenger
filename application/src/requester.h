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

    enum ApiType {
        SIGN_UP,
        SEND_MESSAGE,
        REQUEST_MESSAGE_LIST,
        /*Add here new API*/
    };

    enum RequestType {
        GET,
        POST,
        PUT,
        DELETE
    };
    enum MessengerError {
        OtherError,
        NoNetworkConnect,
        NotFound,
        ServerNotAvailable,
    };
    Q_ENUM(MessengerError)

    explicit Requester(QObject *parent = nullptr);

    void sendRequest(const Requester::RequestType type, const Requester::ApiType api, const QVariantMap &jsonData);

signals:
    void replied(ApiType api, const QByteArray &data);
    void error(int errorCode);

private:
    QNetworkRequest createRequest(const Requester::ApiType &api);
    QString apiToString(Requester::ApiType api);
    Requester::ApiType urlToApi(const QUrl &url);

    QNetworkAccessManager *m_manager;
};

#endif // REQUEST_H
