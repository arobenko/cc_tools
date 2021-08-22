#include "MessageCreator.h"

#include <iostream>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

MessageCreator::MessageCreator(QObject* p) :
    Base(p)
{
}

MessageCreator::~MessageCreator()
{
    setCreatedMessage(nullptr);
}

void MessageCreator::createMessage(MessageIdType id, unsigned idx)
{
    auto& list = m_createdMessages[id];
    if (list.size() <= idx) {
        list.resize(idx + 1);
    }

    auto& msg = list[idx];
    if (!msg) {
        auto protocolPtr = AppMgr::instance().msgMgr().getProtocol();
        msg = protocolPtr->createMessage(id, idx);
    }

    assert(msg);
    setCreatedMessage(msg);
}

MessageCreator::MessagePtr MessageCreator::getMsg()
{
    return m_createdMsg;
}

void MessageCreator::setCreatedMessage(MessagePtr msg)
{
    if (m_createdMsg == msg) {
        return;
    }

    m_createdMsg = std::move(msg);
    emit sigMsgChanged(m_createdMsg);
}
    
} // namespace cc_view

} // namespace cc_tools