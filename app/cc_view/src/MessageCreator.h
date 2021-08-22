#pragma once

#include <vector>
#include <map>

#include <QtCore/QObject>

#include "cc_tools/cc_plugin/Message.h"

namespace cc_tools
{

namespace cc_view
{

class MessageCreator : public QObject
{
    Q_OBJECT
    using Base = QObject;

    Q_PROPERTY(MessagePtr msg READ getMsg NOTIFY sigMsgChanged)

public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;
    using MessageIdType = cc_tools::cc_plugin::Message::MessageIdType;

    explicit MessageCreator(QObject* p = nullptr);
    ~MessageCreator();

    Q_INVOKABLE void createMessage(MessageIdType id, unsigned idx);

    MessagePtr getMsg();

signals:
    void sigMsgChanged(MessagePtr value);

private:
    using MessagesList = std::vector<MessagePtr>;
    using MessagesMap = std::map<MessageIdType, MessagesList>;

    void setCreatedMessage(MessagePtr msg);

    MessagesMap m_createdMessages;
    MessagePtr m_createdMsg;
};

} // namespace cc_view

} // namespace cc_tools
