#include "modelprovider.h"
#include "messagemodel.h"
#include "contactmodel.h"

ModelProvider::ModelProvider(QObject *parent)
    : QObject(parent)
    , m_messageModel(nullptr)
    , m_contactModel(nullptr)
{
    m_contactModel = new ContactModel(this);
    m_messageModel = new MessageModel(this);
}

ModelProvider::~ModelProvider()
{
}

MessageModel *ModelProvider::messageList() const
{
    return m_messageModel;
}

ContactModel *ModelProvider::contactModel() const
{
    return m_contactModel;
}
