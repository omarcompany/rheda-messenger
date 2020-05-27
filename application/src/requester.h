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
        /*Add here new API*/
    };

    enum RequestType {
        GET,
        POST,
        PUT,
        DELETE
    };

    explicit Requester(QObject *parent = nullptr);

    void sendRequest(const Requester::RequestType type, const Requester::ApiType api, const QVariantMap &jsonData);

signals:
    void replied(QNetworkReply *reply);

private:
    QNetworkRequest createRequest(const Requester::ApiType &api);
    QString getApi(Requester::ApiType api);

    QNetworkAccessManager *m_manager;
};

#endif // REQUEST_H
