#ifndef MODELPROVIDER_H
#define MODELPROVIDER_H

#include <QObject>

class MessageModel;
class ContactModel;
class ModelProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MessageModel* messageList READ messageList NOTIFY messageListChanged)
    Q_PROPERTY(ContactModel* contactModel READ contactModel NOTIFY contactModelChanged)
public:
    explicit ModelProvider(QObject *parent = nullptr);
    ~ModelProvider();

    MessageModel *messageList() const;
    ContactModel *contactModel() const;

signals:
    void messageListChanged();
    void contactModelChanged();

private:
    MessageModel *m_messageModel;
    ContactModel *m_contactModel;
};

#endif // MODELPROVIDER_H
