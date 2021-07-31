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


#pragma once

#include <memory>
#include <vector>

#include "cc_tools/cc_app/Api.h"
#include "cc_tools/cc_plugin/Message.h"
#include "cc_tools/cc_plugin/Protocol.h"
#include "cc_tools/cc_plugin/Socket.h"
#include "cc_tools/cc_plugin/Filter.h"

namespace cc_tools
{

namespace cc_app
{

class MsgMgrImpl;
class CC_APP_API MsgMgr
{
public:
    using Message = cc_plugin::Message;
    using MessagePtr = cc_plugin::MessagePtr;
    using AllMessages = std::vector<MessagePtr>;
    using MessagesList = cc_plugin::Protocol::MessagesList;
    using MsgType = cc_plugin::Message::Type;
    using SocketPtr = cc_plugin::SocketPtr;
    using ProtocolPtr = cc_plugin::ProtocolPtr;
    using FilterPtr = cc_plugin::FilterPtr;

    MsgMgr();
    ~MsgMgr() noexcept;

    void start();
    void stop();
    void clear();

    SocketPtr getSocket() const;
    ProtocolPtr getProtocol() const;
    void setRecvEnabled(bool enabled);

    void deleteMsg(MessagePtr msg);
    void deleteAllMsgs();

    void sendMsgs(MessagesList&& msgs);

    void addMsgs(const MessagesList& msgs, bool reportAdded = true);

    void setSocket(SocketPtr socket);
    void setProtocol(ProtocolPtr protocol);
    void addFilter(FilterPtr filter);

    using MsgAddedCallbackFunc = std::function<void (MessagePtr msg)>;
    using ErrorReportCallbackFunc = std::function<void (const QString& error)>;
    using SocketDisconnectedReportCallbackFunc = std::function<void ()>;

    void setMsgAddedCallbackFunc(MsgAddedCallbackFunc&& func);
    void setErrorReportCallbackFunc(ErrorReportCallbackFunc&& func);
    void setSocketDisconnectReportCallbackFunc(SocketDisconnectedReportCallbackFunc&& func);

private:
    std::unique_ptr<MsgMgrImpl> m_impl;
};

} // namespace cc_app

}  // namespace cc_tools

