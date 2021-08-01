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

#include "cc_tools/cc_plugin/Protocol.h"

#include "comms/util/Tuple.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

template <typename TFrame>
class ProtocolImpl : public cc_tools::cc_plugin::Protocol
{
    using Base = cc_tools::cc_plugin::Protocol;
public:    
    using Frame = TFrame;
    using AllMessages = typename Frame::AllMessages;
    using MessageInfosList = Base::MessageInfosList;

protected:
    virtual MessageInfosList getSupportedMessagesImpl() const override
    {
        MessageInfosList result;
        result.resize(std::tuple_size<AllMessages>::value);
        comms::util::tupleForEachType<AllMessages>(MessageInfosListFiller(result));
        return result;
    }

private:
    class MessageInfosListFiller
    {
    public:
        using MessageInfosList = ProtocolImpl::MessageInfosList;
        explicit MessageInfosListFiller(MessageInfosList& list) : m_list(list) {}

        template <typename TMsg>
        void operator()()
        {
            m_list[m_idx].m_name = TMsg::doName();
            m_list[m_idx].m_id = static_cast<decltype(m_list[m_idx].m_id)>(TMsg::doGetId());

            if (m_idx == 0) {
                ++m_idx;
                return;
            }

            auto prevIdx = m_idx - 1U;
            if (m_list[prevIdx].m_id != m_list[m_idx].m_id) {
                ++m_idx;
                return;
            }

            m_list[m_idx].m_idx = m_list[prevIdx].m_idx + 1U;
            ++m_idx;
        }        

    private: 
        MessageInfosList& m_list;  
        unsigned m_idx = 0;
    };
};

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

