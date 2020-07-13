#include "modelprovider.h"
#include <QAbstractItemModel>
#include "messagemodel.h"

ModelProvider::ModelProvider(QObject *parent)
    : QObject(parent)
    , m_messageModel(nullptr)
{
    m_messageModel = new MessageModel(this);
}

ModelProvider::~ModelProvider()
{
}

MessageModel *ModelProvider::messageList() const
{
    return m_messageModel;
}
