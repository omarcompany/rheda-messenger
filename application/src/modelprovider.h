#ifndef MODELPROVIDER_H
#define MODELPROVIDER_H

#include <QObject>

class MessageModel;
class ModelProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MessageModel* messageList READ messageList NOTIFY messageListChanged)
public:
    explicit ModelProvider(QObject *parent = nullptr);
    ~ModelProvider();

    MessageModel *messageList() const;
signals:
    void messageListChanged();
private:
    MessageModel *m_messageModel;
};

#endif // MODELPROVIDER_H
