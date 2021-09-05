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

QmlMessage::FieldPtr QmlMessage::field(int idx)
{
    if (!m_Msg) {
        return FieldPtr();
    }

    assert(0 <= idx);
    auto& fields = m_Msg->fields();
    assert(static_cast<unsigned>(idx) < fields.size());
    return fields[idx];
}

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