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

#include "cc_tools/cc_plugin/Field.h"

#include <cassert>
#include <type_traits>

namespace cc_tools
{

namespace cc_plugin
{

Field::Field(QObject* p) : 
    Base(p)
{
}

Field::~Field() noexcept = default;

const QString& Field::name() const
{
    return nameImpl();
}

Field::Type Field::type() const
{
    return typeImpl();
}

QString Field::getSerialized() const
{
    QString result;
    auto data = getSerializedImpl();
    for (auto byte : data) {
        auto byteStr = QString("%1").arg(static_cast<unsigned>(static_cast<std::uint8_t>(byte)), 2, 16, QChar('0'));
        result.append(byteStr);
    }

    return result;
}

void Field::setSerialized(const QString& str)
{
    auto strTmp = str;
    if ((strTmp.size() % 2) != 0) {
        strTmp.append('0');
    }

    QByteArray data;
    for (auto idx = 0; idx < strTmp.size(); idx += 2) {
        auto byteStr = strTmp.mid(idx, 2);
        data.append(static_cast<char>(byteStr.toUInt(nullptr, 16)));
    }

    adjustSerializedLengthImpl(data);
    auto prevSer = getSerialized();
    setSerializedImpl(data);

    if (getSerialized() != prevSer) {
        reportFieldUpdated();
    }
}

void Field::reportFieldUpdated()
{
    emit sigFieldUpdated();
}

// ------------------------------------------

EnumField::EnumField(QObject* p) : 
    Base(p)
{
}

EnumField::~EnumField() noexcept = default;

const EnumField::ValueNamesMap& EnumField::getValueNamesMap() const
{
    return getValueNamesMapImpl();
}

EnumField::ValueType EnumField::minAllowedValue() const
{
    return minAllowedValueImpl();
}

EnumField::ValueType EnumField::maxAllowedValue() const
{
    return maxAllowedValueImpl();
}

EnumField::ValueType EnumField::getValue() const
{
    return getValueImpl();
}

void EnumField::setValue(ValueType value)
{
    if (getValue() == value) {
        return;
    }

    setValueImpl(value);
    reportFieldUpdated();
}

EnumField::Type EnumField::typeImpl() const
{
    return Base::Type_Enum;
}

}  // namespace cc_plugin

}  // namespace cc_tools
