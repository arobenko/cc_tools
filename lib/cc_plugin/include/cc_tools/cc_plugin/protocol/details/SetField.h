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

#include "FieldImpl.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

namespace details
{

template <typename TField>
class SetField : public FieldImpl<TField, cc_tools::cc_plugin::SetField>
{
    using Base = FieldImpl<TField, cc_tools::cc_plugin::SetField>;
public:    
    using FieldValueType = typename TField::ValueType;
    using BitNameInfo = typename Base::BitNameInfo;
    using BitNamesMap = typename Base::BitNamesMap;

    explicit SetField(TField& field) : 
        Base(field)
    {
    }
    
    ~SetField() = default;

protected:
    virtual const BitNamesMap& getBitNamesMapImpl() const override final
    {
        static const BitNamesMap Map = createBitNamesMapInternal();
        return Map;
    }

    virtual bool getBitValueImpl(unsigned idx) const override final
    {
        return Base::field().getBitValue(idx);
    }

    virtual void setBitValueImpl(unsigned idx, bool value) override final
    {
        Base::field().setBitValue(idx, value);
    }


private:
    BitNamesMap createBitNamesMapInternal() const
    {
        static const auto TotalBits = std::numeric_limits<FieldValueType>::digits;
        BitNamesMap result;
        result.reserve(TotalBits);
        for (unsigned idx = 0; idx < TotalBits; ++idx) {
            auto* name = TField::bitName(static_cast<typename TField::BitIdx>(idx));
            if (name == nullptr) {
                continue;
            }

            result.push_back(std::make_pair(idx, name));
        }
        return result;
    }
};

template <typename TField>
FieldPtr createSetField(TField& field)
{
    return FieldPtr(new SetField<TField>(field));
}

} // namespace details

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

