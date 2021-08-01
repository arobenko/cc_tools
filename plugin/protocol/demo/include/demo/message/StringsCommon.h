
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Strings message and its fields.

#pragma once

#include <cstdint>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Strings message.
/// @see demo::message::StringsFields
struct StringsFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::StringsFields::F4Len field.
    struct F4LenCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::StringsFields::F4Len field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo::message::StringsFields::F4Len field.
        static const char* name()
        {
            return "F4Len";
        }
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::StringsFields::F1 field.
    struct F1Common
    {
        /// @brief Name of the @ref demo::message::StringsFields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::StringsFields::F2 field.
    struct F2MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::StringsFields::F2Members::Length field.
        struct LengthCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::StringsFields::F2Members::Length field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::StringsFields::F2Members::Length field.
            static const char* name()
            {
                return "Length";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::StringsFields::F2 field.
    struct F2Common
    {
        /// @brief Name of the @ref demo::message::StringsFields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::StringsFields::F3 field.
    struct F3Common
    {
        /// @brief Name of the @ref demo::message::StringsFields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::StringsFields::F4 field.
    struct F4Common
    {
        /// @brief Name of the @ref demo::message::StringsFields::F4 field.
        static const char* name()
        {
            return "F4";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::StringsFields::F5 field.
    struct F5Common
    {
        /// @brief Name of the @ref demo::message::StringsFields::F5 field.
        static const char* name()
        {
            return "F5";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Strings message.
/// @see demo::message::Strings
struct StringsCommon
{
    /// @brief Name of the @ref demo::message::Strings message.
    static const char* name()
    {
        return "Strings";
    }
    
};

} // namespace message

} // namespace demo


