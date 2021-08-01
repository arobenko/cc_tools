
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Optionals message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Optionals message.
/// @see demo::message::OptionalsFields
struct OptionalsFieldsCommon
{
    /// @brief Common functions for
    ///     @ref demo::message::OptionalsFields::Flags field.
    struct FlagsCommon
    {
        /// @brief Name of the @ref demo::message::OptionalsFields::Flags field.
        static const char* name()
        {
            return "Flags";
        }
        
        /// @brief Retrieve name of the bit of
        ///     @ref demo::message::OptionalsFields::Flags field.
        static const char* bitName(std::size_t idx)
        {
            static const char* Map[] = {
                "F2Exists",
                "F3Missing"
            };
        
            static const std::size_t MapSize = std::extent<decltype(Map)>::value;
            if (MapSize <= idx) {
                return nullptr;
            }
        
            return Map[idx];
        }
        
    };
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::OptionalsFields::F2 field.
    struct F2MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::OptionalsFields::F2Members::F2 field.
        struct F2Common
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::OptionalsFields::F2Members::F2 field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo::message::OptionalsFields::F2Members::F2 field.
            static const char* name()
            {
                return "F2";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::OptionalsFields::F2 field.
    struct F2Common
    {
        /// @brief Name of the @ref demo::message::OptionalsFields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::OptionalsFields::F3 field.
    struct F3MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::OptionalsFields::F3Members::F3 field.
        struct F3Common
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::OptionalsFields::F3Members::F3 field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo::message::OptionalsFields::F3Members::F3 field.
            static const char* name()
            {
                return "F3";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::OptionalsFields::F3 field.
    struct F3Common
    {
        /// @brief Name of the @ref demo::message::OptionalsFields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Optionals message.
/// @see demo::message::Optionals
struct OptionalsCommon
{
    /// @brief Name of the @ref demo::message::Optionals message.
    static const char* name()
    {
        return "Optionals";
    }
    
};

} // namespace message

} // namespace demo


