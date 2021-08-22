//
// Copyright 2021 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "cc_tools/cc_plugin/Protocol.h"

#include <iostream>

namespace cc_tools
{

namespace cc_plugin
{

Protocol::Protocol(QObject* p) : 
    Base(p)
{
}

Protocol::~Protocol() noexcept = default;

Protocol::MessagesList Protocol::read(const DataInfo& dataInfo, bool final)
{
    return readImpl(dataInfo, final);
}

DataInfoPtr Protocol::write(Message& msg)
{
    return writeImpl(msg);
}

Protocol::MessageInfosList Protocol::getSupportedMessages() const
{
    return getSupportedMessagesImpl();
}

QString Protocol::getMessageInfoString(const MessageInfo& info) const
{
    return getMessageInfoStringImpl(info);
}

QString Protocol::getMessageIdString(const MessageInfo& info) const
{
    return getMessageIdStringImpl(info);
}

MessagePtr Protocol::createMessage(const MessageInfo& info)
{
    return createMessage(info.m_id, info.m_idx);
}

MessagePtr Protocol::createMessage(MessageIdType id, unsigned idx)
{
    return createMessageImpl(id, idx);
}

Protocol::Type Protocol::getTypeImpl() const
{
    return Type::Protocol;
}

QString Protocol::getMessageInfoStringImpl(const MessageInfo& info) const
{
    return QString("(%1) %2").arg(getMessageIdString(info)).arg(info.m_name);
}

QString Protocol::getMessageIdStringImpl(const MessageInfo& info) const
{
    return QString::number(info.m_id);
}

MessagePtr Protocol::createMessageImpl(MessageIdType id, unsigned idx)
{
    static_cast<void>(id);
    static_cast<void>(idx);
    assert(!"Should not happen");
    return MessagePtr();
}

}  // namespace cc_plugin

}  // namespace cc_tools
