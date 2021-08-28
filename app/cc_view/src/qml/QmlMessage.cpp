#include "QmlMessage.h"

#include <iostream>

namespace cc_tools
{

namespace cc_view
{

QmlMessage::QmlMessage(QObject* p) :
    Base(p)
{
    connect(
        this, &QmlMessage::sigMsgChanged,
        this, &QmlMessage::msgUpdated);
}

QmlMessage::~QmlMessage() = default;


void QmlMessage::msgUpdated(MessagePtr value)
{
    if (!value) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlMessage::resetStatus()
{
    setName(QString());
    setInfoString(QString());
}

void QmlMessage::updateStatus()
{
    setName(m_Msg->name());
    setInfoString(m_Msg->infoStr());
}
    
} // namespace cc_view

} // namespace cc_tools