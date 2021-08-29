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

#include "comms/field/IntValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/FloatValue.h"
#include "comms/field/Bitfield.h"
#include "comms/field/Bundle.h"
#include "comms/field/Optional.h"
#include "comms/field/ArrayList.h"
#include "comms/field/String.h"
#include "comms/field/Variant.h"

#include "comms/util/type_traits.h"

#include "cc_tools/cc_plugin/Field.h"

#include "IntField.h"
#include "EnumField.h"
#include "SetField.h"
#include "FloatField.h"
#include "BitfieldField.h"
#include "BundleField.h"
#include "OptionalField.h"
#include "DataField.h"
#include "ListField.h"
#include "StringField.h"
#include "VariantField.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

namespace details
{

class FieldCreator
{
public:    
    template <typename TField>
    static FieldPtr createField(TField& field)
    {
        return createInternal<TField>(field);
    }

private:
    struct DataTag {};
    struct ListTag {};

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::IntValue<TFieldBase, T, TOptions...>& field)
    {
        return createIntField(static_cast<TField&>(field));
    }

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::EnumValue<TFieldBase, T, TOptions...>& field)
    {
        return createEnumField(static_cast<TField&>(field));
    }    

    template <typename TField, typename TFieldBase, typename... TOptions>
    static FieldPtr createInternal(comms::field::BitmaskValue<TFieldBase, TOptions...>& field)
    {
        return createSetField(static_cast<TField&>(field));
    }      

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::FloatValue<TFieldBase, T, TOptions...>& field)
    {
        return createFloatField(static_cast<TField&>(field));
    }   

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::Bitfield<TFieldBase, T, TOptions...>& field)
    {
        return createBitfieldField(static_cast<TField&>(field));
    }

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::Bundle<TFieldBase, T, TOptions...>& field)
    {
        return createBundleField(static_cast<TField&>(field));
    }    

    template <typename TField, typename TMember, typename... TOptions>
    static FieldPtr createInternal(comms::field::Optional<TMember, TOptions...>& field)
    {
        return createOptionalField(static_cast<TField&>(field));
    }     

    template <typename TField, typename TFieldBase, typename TElement, typename... TOptions>
    static FieldPtr createInternal(comms::field::ArrayList<TFieldBase, TElement, TOptions...>& field)
    {
        using Tag = 
            typename comms::util::Conditional<
                std::is_integral<TElement>::value
            >::template Type<
                DataTag,
                ListTag
            >;
                
        return createListInternal<TField>(field, Tag());
    }  

    template <typename TField, typename TFieldBase, typename... TOptions>
    static FieldPtr createInternal(comms::field::String<TFieldBase, TOptions...>& field)
    {
        return createStringField(static_cast<TField&>(field));
    }  

    template <typename TField, typename TFieldBase, typename T, typename... TOptions>
    static FieldPtr createInternal(comms::field::Variant<TFieldBase, T, TOptions...>& field)
    {
        return createVariantField(static_cast<TField&>(field));
    }    

    template <typename TField, typename TFieldBase, typename TElement, typename... TOptions>
    static FieldPtr createListInternal(comms::field::ArrayList<TFieldBase, TElement, TOptions...>& field, DataTag)
    {
        return createDataField(static_cast<TField&>(field));
    }    

    template <typename TField, typename TFieldBase, typename TElement, typename... TOptions>
    static FieldPtr createListInternal(comms::field::ArrayList<TFieldBase, TElement, TOptions...>& field, ListTag)
    {
        return createListField(static_cast<TField&>(field));
    } 
                    
};

} // namespace details

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

