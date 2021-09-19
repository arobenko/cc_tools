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

#include "cc_tools/cc_plugin/Message.h"

#include <cassert>
#include <type_traits>

namespace cc_tools
{

namespace cc_plugin
{

namespace 
{

void forceUpdateReportForFields(Message& msg, Field& origField)
{
    auto& allFields = msg.fields();
    for (auto& f : allFields) {
        if (f.get() == &origField) {
            continue;
        }

        f->reportFieldUpdated();
    }    
}

} // namespace 
    

Message::Message(QObject* p) : 
    Base(p)
{
}

Message::~Message() noexcept = default;

void Message::init()
{
    auto& allFields = fields();
    for (auto& f : allFields) {
        connect(
            f.get(), &Field::sigFieldUpdated,
            this,
            [this]() 
            {
                bool updated = refresh();
                if (updated) {
                    auto* sndr = qobject_cast<Field*>(sender());
                    assert(sndr != nullptr);
                    forceUpdateReportForFields(*this, *sndr);
                }
                emit sigMessageUpdated();
            });
    }
}

const char* Message::propName(PropType value)
{
    static const char* Map[] = {
        /* Type */ "cc.type",
        /* SeqNum */ "cc.seq_num",
        /* Timestamp */ "cc.timestamp",
    };

    static const std::size_t MapSize = std::extent<decltype(Map)>::value;
    static_assert(MapSize == static_cast<unsigned>(PropType::NumOfValues), "Invalid Map");

    auto idx = static_cast<unsigned>(value);
    if (MapSize <= idx) {
        assert(!"Should_not_happen");
        return nullptr;
    }

    return Map[idx];
}

const QString& Message::name() const
{
    return nameImpl();
}

Message::MessageIdType Message::id() const
{
    return idImpl();
}

QString Message::idStr() const
{
    return idStrImpl();
}

QString Message::infoStr() const
{
    return QString("(%1) - %2").arg(idStr()).arg(name());
}

Message::FieldsList& Message::fields()
{
    return fieldsImpl();
}

bool Message::refresh()
{
    return refreshImpl();
}

QString Message::idStrImpl() const
{
    return QString::number(id());
}

}  // namespace cc_plugin

}  // namespace cc_tools
