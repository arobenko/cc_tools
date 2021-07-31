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

#include <vector>

#include "cc_tools/cc_app/MsgMgr.h"

namespace cc_tools
{

namespace cc_app
{
    
class MsgMgrImpl
{
public:
    using AllMessages = MsgMgr::AllMessages;
    using MessagesList = MsgMgr::MessagesList;
    using MsgType = MsgMgr::MsgType;
    using Message = MsgMgr::Message;
    using MessagePtr = MsgMgr::MessagePtr;
    using SocketPtr = MsgMgr::SocketPtr;
    using ProtocolPtr = MsgMgr::ProtocolPtr;
    using FilterPtr = MsgMgr::FilterPtr;
    

    MsgMgrImpl();
    ~MsgMgrImpl() noexcept;

    void start();
    void stop();
    void clear();

    SocketPtr getSocket() const;
    ProtocolPtr getProtocol() const;
    void setRecvEnabled(bool enabled);

    void deleteMsg(MessagePtr msg);
    void deleteAllMsgs()
    {
        m_allMsgs.clear();
    }

    void sendMsgs(MessagesList&& msgs);

    const AllMessages& getAllMsgs() const
    {
        return m_allMsgs;
    }

    void addMsgs(const MessagesList& msgs, bool reportAdded);

    void setSocket(SocketPtr socket);
    void setProtocol(ProtocolPtr protocol);
    void addFilter(FilterPtr filter);

    using MsgAddedCallbackFunc = MsgMgr::MsgAddedCallbackFunc;
    using ErrorReportCallbackFunc = MsgMgr::ErrorReportCallbackFunc;
    using SocketDisconnectedReportCallbackFunc = MsgMgr::SocketDisconnectedReportCallbackFunc;

    template <typename TFunc>
    void setMsgAddedCallbackFunc(TFunc&& func)
    {
        m_msgAddedCallback = std::forward<TFunc>(func);
    }

    template <typename TFunc>
    void setErrorReportCallbackFunc(TFunc&& func)
    {
        m_errorReportCallback = std::forward<TFunc>(func);
    }

    template <typename TFunc>
    void setSocketDisconnectReportCallbackFunc(TFunc&& func)
    {
        m_socketDisconnectReportCallback = std::forward<TFunc>(func);
    }

private:
    using DataInfoPtr = cc_plugin::DataInfoPtr;
    using MsgNumberType = unsigned long long;
    using FiltersList = std::vector<FilterPtr>;

    void socketDataReceived(DataInfoPtr dataInfoPtr);
    void updateInternalId(Message& msg);
    void reportMsgAdded(MessagePtr msg);
    void reportError(const QString& error);
    void reportSocketDisconnected();

    AllMessages m_allMsgs;
    bool m_recvEnabled = false;

    SocketPtr m_socket;
    ProtocolPtr m_protocol;
    FiltersList m_filters;
    MsgNumberType m_nextMsgNum = 1;
    bool m_running = false;

    MsgAddedCallbackFunc m_msgAddedCallback;
    ErrorReportCallbackFunc m_errorReportCallback;
    SocketDisconnectedReportCallbackFunc m_socketDisconnectReportCallback;
};

} // namespace cc_app

} // namespace cc_tools
