
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Floats message and its fields.

#pragma once

#include <limits>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Floats message.
/// @see demo::message::FloatsFields
struct FloatsFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::FloatsFields::Timeout field.
    struct TimeoutCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::FloatsFields::Timeout field.
        using ValueType = float;
    
        /// @brief Name of the @ref demo::message::FloatsFields::Timeout field.
        static const char* name()
        {
            return "Timeout";
        }
        
        /// @brief Special value <b>"Infinite"</b>.
        static constexpr ValueType valueInfinite()
        {
            return static_cast<ValueType>(0.000000);
        }
        
        
        /// @brief Special value <b>"Invalid"</b>.
        static constexpr ValueType valueInvalid()
        {
            return std::numeric_limits<ValueType>::quiet_NaN();
        }
        
        
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::FloatsFields::Distance field.
    struct DistanceCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::FloatsFields::Distance field.
        using ValueType = float;
    
        /// @brief Name of the @ref demo::message::FloatsFields::Distance field.
        static const char* name()
        {
            return "Distance";
        }
        
        /// @brief Special value <b>"Infinite"</b>.
        static constexpr ValueType valueInfinite()
        {
            return std::numeric_limits<ValueType>::infinity();
        }
        
        
        /// @brief Special value <b>"Invalid"</b>.
        static constexpr ValueType valueInvalid()
        {
            return std::numeric_limits<ValueType>::quiet_NaN();
        }
        
        
        
    };
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Floats message.
/// @see demo::message::Floats
struct FloatsCommon
{
    /// @brief Name of the @ref demo::message::Floats message.
    static const char* name()
    {
        return "Floats";
    }
    
};

} // namespace message

} // namespace demo


