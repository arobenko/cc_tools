
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::SimpleInts message and its fields.

#pragma once

#include <cstdint>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::SimpleInts message.
/// @see demo::message::SimpleIntsFields
struct SimpleIntsFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F1 field.
    struct F1Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F1 field.
        using ValueType = std::int8_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F2 field.
    struct F2Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F2 field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F3 field.
    struct F3Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F3 field.
        using ValueType = std::int16_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F4 field.
    struct F4Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F4 field.
        using ValueType = std::uint16_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F4 field.
        static const char* name()
        {
            return "F4";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F5 field.
    struct F5Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F5 field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F5 field.
        static const char* name()
        {
            return "F5";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F6 field.
    struct F6Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F6 field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F6 field.
        static const char* name()
        {
            return "F6";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F7 field.
    struct F7Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F7 field.
        using ValueType = std::int64_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F7 field.
        static const char* name()
        {
            return "F7";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F8 field.
    struct F8Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F8 field.
        using ValueType = std::uint64_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F8 field.
        static const char* name()
        {
            return "F8";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F9 field.
    struct F9Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F9 field.
        using ValueType = std::int32_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F9 field.
        static const char* name()
        {
            return "F9";
        }
        
    };
    
    /// @brief Common types and functions for
    ///     @ref demo::message::SimpleIntsFields::F10 field.
    struct F10Common
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::SimpleIntsFields::F10 field.
        using ValueType = std::uint32_t;
    
        /// @brief Name of the @ref demo::message::SimpleIntsFields::F10 field.
        static const char* name()
        {
            return "F10";
        }
        
    };
    
};

/// @brief Common types and functions of 
///     @ref demo::message::SimpleInts message.
/// @see demo::message::SimpleInts
struct SimpleIntsCommon
{
    /// @brief Name of the @ref demo::message::SimpleInts message.
    static const char* name()
    {
        return "Simple Ints";
    }
    
};

} // namespace message

} // namespace demo


