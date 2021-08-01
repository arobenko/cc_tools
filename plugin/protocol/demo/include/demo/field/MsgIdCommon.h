
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::field::MsgId field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "demo/MsgId.h"

namespace demo
{

namespace field
{

/// @brief Common types and functions for
///     @ref demo::field::MsgId field.
struct MsgIdCommon
{
    /// @brief Values enumerator for
    ///     @ref demo::field::MsgId field.
    using ValueType = demo::MsgId;
    
    /// @brief Name of the @ref demo::field::MsgId field.
    static const char* name()
    {
        return "MsgId";
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(demo::MsgId val)
    {
        static const char* Map[] = {
            "Ack",
            "SimpleInts",
            "ScaledInts",
            "Floats",
            "Enums",
            "Sets",
            "Bitfields",
            "Strings",
            "Datas",
            "Lists",
            "Optionals",
            "Variants"
        };
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;
        
        if (MapSize <= static_cast<std::size_t>(val)) {
            return nullptr;
        }
        
        return Map[static_cast<std::size_t>(val)];
    }
    
};

/// @brief Values enumerator for
///     @ref demo::field::MsgId field.
using MsgIdVal = MsgIdCommon::ValueType;

} // namespace field

} // namespace demo


