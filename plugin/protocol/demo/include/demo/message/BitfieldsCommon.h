
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Bitfields message and its fields.

#pragma once

#include <cstdint>
#include <type_traits>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Bitfields message.
/// @see demo::message::BitfieldsFields
struct BitfieldsFieldsCommon
{
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::BitfieldsFields::F1 field.
    struct F1MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::BitfieldsFields::F1Members::Mem1 field.
        struct Mem1Common
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::BitfieldsFields::F1Members::Mem1 field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::BitfieldsFields::F1Members::Mem1 field.
            static const char* name()
            {
                return "Mem1";
            }
            
        };
        
        /// @brief Common functions for
        ///     @ref demo::message::BitfieldsFields::F1Members::Mem2 field.
        struct Mem2Common
        {
            /// @brief Name of the @ref demo::message::BitfieldsFields::F1Members::Mem2 field.
            static const char* name()
            {
                return "Mem2";
            }
            
            /// @brief Retrieve name of the bit of
            ///     @ref demo::message::BitfieldsFields::F1Members::Mem2 field.
            static const char* bitName(std::size_t idx)
            {
                static const char* Map[] = {
                    "Bit0",
                    "Bit1",
                    "Bit2"
                };
            
                static const std::size_t MapSize = std::extent<decltype(Map)>::value;
                if (MapSize <= idx) {
                    return nullptr;
                }
            
                return Map[idx];
            }
            
        };
        
        /// @brief Common types and functions for
        ///     @ref demo::message::BitfieldsFields::F1Members::Mem3 field.
        struct Mem3Common
        {
            /// @brief Values enumerator for
            ///     @ref demo::message::BitfieldsFields::F1Members::Mem3 field.
            enum class ValueType : std::uint8_t
            {
                V1 = 0, ///< value @b V1.
                V2 = 3, ///< value @b V2.
                
                // --- Extra values generated for convenience ---
                FirstValue = 0, ///< First defined value.
                LastValue = 3, ///< Last defined value.
                ValuesLimit = 4, ///< Upper limit for defined values.
                
            };
            
            /// @brief Name of the @ref demo::message::BitfieldsFields::F1Members::Mem3 field.
            static const char* name()
            {
                return "Mem3";
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                static const char* Map[] = {
                    "V1",
                    nullptr,
                    nullptr,
                    "V2"
                };
                static const std::size_t MapSize = std::extent<decltype(Map)>::value;
                
                if (MapSize <= static_cast<std::size_t>(val)) {
                    return nullptr;
                }
                
                return Map[static_cast<std::size_t>(val)];
            }
            
        };
        
        /// @brief Values enumerator for
        ///     @ref demo::message::BitfieldsFields::F1Members::Mem3 field.
        using Mem3Val = Mem3Common::ValueType;
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::BitfieldsFields::F1 field.
    struct F1Common
    {
        /// @brief Name of the @ref demo::message::BitfieldsFields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Bitfields message.
/// @see demo::message::Bitfields
struct BitfieldsCommon
{
    /// @brief Name of the @ref demo::message::Bitfields message.
    static const char* name()
    {
        return "Bitfields";
    }
    
};

} // namespace message

} // namespace demo


