#include "QmlMessage.h"

#include <iostream>

namespace cc_tools
{

namespace cc_view
{

QmlMessage::QmlMessage(QObject* p) :
    Base(p)
{
}

QmlMessage::~QmlMessage() = default;


QmlMessage::MessagePtr QmlMessage::getMsg()
{
    return m_msg;
}

void QmlMessage::setMsg(MessagePtr msg)
{
    if (!msg) {
        reset();
        return;
    }

    if (msg == m_msg) {
        return;
    }

    setName(msg->name());

    m_msg = std::move(msg);
    emit sigMsgChanged(m_msg);
}

void QmlMessage::reset()
{
    setName(QString());
}
    
} // namespace cc_view

} // namespace cc_tools