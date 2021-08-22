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

#include "comms/util/Tuple.h"

#include "cc_tools/cc_plugin/Message.h"

#include "cc_tools/cc_plugin/protocol/details/FieldCreator.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

template <typename TMsg>
class MessageImpl : public cc_tools::cc_plugin::Message
{
    using Base = cc_tools::cc_plugin::Message;
public:    
    MessageImpl()
    {
        updateFields();
    }
    ~MessageImpl() = default;
    
    TMsg& msg()
    {
        return m_msg;
    }

protected:

    virtual const QString& nameImpl() const override
    {
        static const QString Str(m_msg.doName());
        return Str;
    }

private:
    using FieldsList = std::vector<FieldPtr>;
    class FieldCreateHandler
    {
    public:
        FieldCreateHandler(FieldsList& list) : m_list(list) {}

        template <typename TField>
        void operator()(TField& field)
        {
            m_list.push_back(details::FieldCreator::createField(field));
        }

    private:
        FieldsList& m_list;
    };

    void updateFields()
    {
        m_fields.clear();
        comms::util::tupleForEach(m_msg.fields(), FieldCreateHandler(m_fields));
        assert(m_fields.size() == std::tuple_size<typename TMsg::AllFields>::value);
    }

    TMsg m_msg;
    std::vector<FieldPtr> m_fields;
};

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

