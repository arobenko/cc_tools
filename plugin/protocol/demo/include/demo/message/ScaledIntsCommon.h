
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::ScaledInts message and its fields.

#pragma once

#include <cstdint>
#include "demo/field/LatCommon.h"
#include "demo/field/LonCommon.h"

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::ScaledInts message.
/// @see demo::message::ScaledIntsFields
struct ScaledIntsFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::ScaledIntsFields::Lat field.
    using LatCommon = demo::field::LatCommon;
    
    /// @brief Common types and functions for
    ///     @ref demo::message::ScaledIntsFields::Lon field.
    using LonCommon = demo::field::LonCommon;
    
    /// @brief Common types and functions for
    ///     @ref demo::message::ScaledIntsFields::Height field.
    struct HeightCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::ScaledIntsFields::Height field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref demo::message::ScaledIntsFields::Height field.
        static const char* name()
        {
            return "Height";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::ScaledIntsFields::SomeScaledVal field.
    struct SomeScaledValCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::ScaledIntsFields::SomeScaledVal field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref demo::message::ScaledIntsFields::SomeScaledVal field.
        static const char* name()
        {
            return "Some Scaled Value";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref demo::message::ScaledInts message.
/// @see demo::message::ScaledInts
struct ScaledIntsCommon
{
    /// @brief Name of the @ref demo::message::ScaledInts message.
    static const char* name()
    {
        return "Scaled Ints";
    }
    
};

} // namespace message

} // namespace demo


