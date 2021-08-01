
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Lists message and its fields.

#pragma once

#include <cstdint>

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Lists message.
/// @see demo::message::ListsFields
struct ListsFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::ListsFields::F2Count field.
    struct F2CountCommon
    {
        /// @brief Re-definition of the value type used by
        ///     demo::message::ListsFields::F2Count field.
        using ValueType = std::uint8_t;
    
        /// @brief Name of the @ref demo::message::ListsFields::F2Count field.
        static const char* name()
        {
            return "F2Count";
        }
        
    };
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::ListsFields::F1 list.
    struct F1MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F1Members::Elem field.
        struct ElemCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F1Members::Elem field.
            using ValueType = std::uint32_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F1Members::Elem field.
            static const char* name()
            {
                return "Elem";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::ListsFields::F1 field.
    struct F1Common
    {
        /// @brief Name of the @ref demo::message::ListsFields::F1 field.
        static const char* name()
        {
            return "F1";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::ListsFields::F2 list.
    struct F2MembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F2Members::Elem field.
        struct ElemCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F2Members::Elem field.
            using ValueType = std::uint32_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F2Members::Elem field.
            static const char* name()
            {
                return "Elem";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::ListsFields::F2 field.
    struct F2Common
    {
        /// @brief Name of the @ref demo::message::ListsFields::F2 field.
        static const char* name()
        {
            return "F2";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::ListsFields::F3 list.
    struct F3MembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref demo::message::ListsFields::F3Members::Element field.
        struct ElementMembersCommon
        {
            /// @brief Common types and functions for
            ///     @ref demo::message::ListsFields::F3Members::ElementMembers::Mem1 field.
            struct Mem1Common
            {
                /// @brief Re-definition of the value type used by
                ///     demo::message::ListsFields::F3Members::ElementMembers::Mem1 field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref demo::message::ListsFields::F3Members::ElementMembers::Mem1 field.
                static const char* name()
                {
                    return "Mem1";
                }
                
            };
            
            /// @brief Common types and functions for
            ///     @ref demo::message::ListsFields::F3Members::ElementMembers::Mem2 field.
            struct Mem2Common
            {
                /// @brief Re-definition of the value type used by
                ///     demo::message::ListsFields::F3Members::ElementMembers::Mem2 field.
                using ValueType = std::int32_t;
            
                /// @brief Name of the @ref demo::message::ListsFields::F3Members::ElementMembers::Mem2 field.
                static const char* name()
                {
                    return "Mem2";
                }
                
            };
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref demo::message::ListsFields::F3Members::Element field.
        struct ElementCommon
        {
            /// @brief Name of the @ref demo::message::ListsFields::F3Members::Element field.
            static const char* name()
            {
                return "Element";
            }
            
        };
        
        
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F3Members::Count field.
        struct CountCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F3Members::Count field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F3Members::Count field.
            static const char* name()
            {
                return "Count";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::ListsFields::F3 field.
    struct F3Common
    {
        /// @brief Name of the @ref demo::message::ListsFields::F3 field.
        static const char* name()
        {
            return "F3";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::ListsFields::F4 list.
    struct F4MembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref demo::message::ListsFields::F4Members::Element field.
        struct ElementMembersCommon
        {
            /// @brief Common types and functions for
            ///     @ref demo::message::ListsFields::F4Members::ElementMembers::Mem1 field.
            struct Mem1Common
            {
                /// @brief Re-definition of the value type used by
                ///     demo::message::ListsFields::F4Members::ElementMembers::Mem1 field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref demo::message::ListsFields::F4Members::ElementMembers::Mem1 field.
                static const char* name()
                {
                    return "Mem1";
                }
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::ListsFields::F4Members::ElementMembers::Mem2 field.
            struct Mem2Common
            {
                /// @brief Name of the @ref demo::message::ListsFields::F4Members::ElementMembers::Mem2 field.
                static const char* name()
                {
                    return "Mem2";
                }
                
            };
            
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref demo::message::ListsFields::F4Members::Element field.
        struct ElementCommon
        {
            /// @brief Name of the @ref demo::message::ListsFields::F4Members::Element field.
            static const char* name()
            {
                return "Element";
            }
            
        };
        
        
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F4Members::Length field.
        struct LengthCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F4Members::Length field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F4Members::Length field.
            static const char* name()
            {
                return "Length";
            }
            
        };
        
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F4Members::ElemLength field.
        struct ElemLengthCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F4Members::ElemLength field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F4Members::ElemLength field.
            static const char* name()
            {
                return "ElemLength";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::ListsFields::F4 field.
    struct F4Common
    {
        /// @brief Name of the @ref demo::message::ListsFields::F4 field.
        static const char* name()
        {
            return "F4";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::ListsFields::F5 list.
    struct F5MembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref demo::message::ListsFields::F5Members::Element field.
        struct ElementMembersCommon
        {
            /// @brief Common types and functions for
            ///     @ref demo::message::ListsFields::F5Members::ElementMembers::Mem1 field.
            struct Mem1Common
            {
                /// @brief Re-definition of the value type used by
                ///     demo::message::ListsFields::F5Members::ElementMembers::Mem1 field.
                using ValueType = std::uint32_t;
            
                /// @brief Name of the @ref demo::message::ListsFields::F5Members::ElementMembers::Mem1 field.
                static const char* name()
                {
                    return "Mem1";
                }
                
            };
            
            /// @brief Common types and functions for
            ///     @ref demo::message::ListsFields::F5Members::ElementMembers::Mem2 field.
            struct Mem2Common
            {
                /// @brief Re-definition of the value type used by
                ///     demo::message::ListsFields::F5Members::ElementMembers::Mem2 field.
                using ValueType = std::int32_t;
            
                /// @brief Name of the @ref demo::message::ListsFields::F5Members::ElementMembers::Mem2 field.
                static const char* name()
                {
                    return "Mem2";
                }
                
            };
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref demo::message::ListsFields::F5Members::Element field.
        struct ElementCommon
        {
            /// @brief Name of the @ref demo::message::ListsFields::F5Members::Element field.
            static const char* name()
            {
                return "Element";
            }
            
        };
        
        
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F5Members::Count field.
        struct CountCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F5Members::Count field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F5Members::Count field.
            static const char* name()
            {
                return "Count";
            }
            
        };
        
        /// @brief Common types and functions for
        ///     @ref demo::message::ListsFields::F5Members::ElemLength field.
        struct ElemLengthCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::ListsFields::F5Members::ElemLength field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::ListsFields::F5Members::ElemLength field.
            static const char* name()
            {
                return "ElemLength";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::ListsFields::F5 field.
    struct F5Common
    {
        /// @brief Name of the @ref demo::message::ListsFields::F5 field.
        static const char* name()
        {
            return "F5";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Lists message.
/// @see demo::message::Lists
struct ListsCommon
{
    /// @brief Name of the @ref demo::message::Lists message.
    static const char* name()
    {
        return "Lists";
    }
    
};

} // namespace message

} // namespace demo


