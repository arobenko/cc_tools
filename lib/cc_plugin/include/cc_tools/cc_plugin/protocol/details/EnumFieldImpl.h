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

#include <algorithm>
#include <limits>

#include "FieldImpl.h"

#include "comms/util/type_traits.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

namespace details
{

template <typename TField>
class EnumFieldImpl : public FieldImpl<TField, cc_tools::cc_plugin::EnumField>
{
    using Base = FieldImpl<TField, cc_tools::cc_plugin::EnumField>;
public:    
    using FieldValueType = typename TField::ValueType;
    using ValueType = typename Base::ValueType;
    using ValueNamesMap = typename Base::ValueNamesMap;
    using UnderlyingType = typename std::underlying_type<typename TField::ValueType>::type;

    explicit EnumFieldImpl(TField& field) : 
        Base(field)
    {
    }
    
    ~EnumFieldImpl() = default;

protected:
    virtual const ValueNamesMap& getValueNamesMapImpl() const override final
    {
        static const ValueNamesMap Map = createValueNamesMapInternal();
        return Map;
    }

    virtual ValueType minAllowedValueImpl() const override final
    {
        return static_cast<ValueType>(std::numeric_limits<UnderlyingType>::min());
    }

    virtual ValueType maxAllowedValueImpl() const override final
    {
        return static_cast<ValueType>(std::numeric_limits<UnderlyingType>::max());
    }

    virtual ValueType getValueImpl() const override final
    {
        return static_cast<ValueType>(Base::field().value());
    }

    virtual void setValueImpl(ValueType value) override final
    {
        Base::field().value() = static_cast<FieldValueType>(value);
    }    

private:
    struct DirectTag {};
    struct BinSearchTag {};

    static ValueNamesMap createValueNamesMapInternal() 
    {
        using Tag = 
            typename comms::util::Conditional<
                std::is_same<typename TField::ValueNameInfo, const char*>::value
            >::template Type<
                DirectTag,
                BinSearchTag
            >;

        return createValueNamesMapInternal(Tag()); 
    }

    static ValueNamesMap createValueNamesMapInternal(DirectTag) 
    {
        auto fieldMap = TField::valueNamesMap();
        ValueNamesMap result;
        result.reserve(fieldMap.second);
        for (auto idx = 0U; idx < fieldMap.second; ++idx) {
            auto* name = fieldMap.first[idx];
            if (name == nullptr) {
                continue;
            }

            result.push_back(std::make_pair(idx, name));
        }
        return result;
    }  

    static ValueNamesMap createValueNamesMapInternal(BinSearchTag) 
    {
        auto fieldMap = TField::valueNamesMap();
        ValueNamesMap result;
        result.reserve(fieldMap.second);
        std::transform(
            fieldMap.first, fieldMap.first + fieldMap.second, std::back_inserter(result),
            [](auto info)
            {
                return std::make_pair(static_cast<typename Base::ValueType>(info.first), info.second);
            });
        return result;
    }         
};

template <typename TField>
FieldPtr createEnumField(TField& field)
{
    return FieldPtr(new EnumFieldImpl<TField>(field));
}

} // namespace details

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

