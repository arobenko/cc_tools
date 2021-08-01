
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Variants message and its fields.

#pragma once

#include <cstdint>
#include "demo/field/PropRemLenCommon.h"

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Variants message.
/// @see demo::message::VariantsFields
struct VariantsFieldsCommon
{
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::VariantsFields::Props1 list.
    struct Props1MembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref demo::message::VariantsFields::Props1Members::Property bundle.
        struct PropertyMembersCommon
        {
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1 field.
            struct Prop1MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Key field.
                struct KeyCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Key field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Key field.
                    static const char* name()
                    {
                        return "Key";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Val field.
                struct ValCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Val field.
                    using ValueType = std::int16_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1 field.
            struct Prop1Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop1 field.
                static const char* name()
                {
                    return "Prop1";
                }
                
            };
            
            
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2 field.
            struct Prop2MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Key field.
                struct KeyCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Key field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Key field.
                    static const char* name()
                    {
                        return "Key";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Val field.
                struct ValCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Val field.
                    using ValueType = std::uint32_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2 field.
            struct Prop2Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop2 field.
                static const char* name()
                {
                    return "Prop2";
                }
                
            };
            
            
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3 field.
            struct Prop3MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Key field.
                struct KeyCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Key field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Key field.
                    static const char* name()
                    {
                        return "Key";
                    }
                    
                };
                
                /// @brief Scope for all the common definitions of the member fields of
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val field.
                struct ValMembersCommon
                {
                    /// @brief Common types and functions for
                    ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::ValMembers::Length field.
                    struct LengthCommon
                    {
                        /// @brief Re-definition of the value type used by
                        ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::ValMembers::Length field.
                        using ValueType = std::uint8_t;
                    
                        /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::ValMembers::Length field.
                        static const char* name()
                        {
                            return "Length";
                        }
                        
                    };
                    
                };
                
                /// @brief Scope for all the common definitions of the
                ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val field.
                struct ValCommon
                {
                    /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3 field.
            struct Prop3Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3 field.
                static const char* name()
                {
                    return "Prop3";
                }
                
            };
            
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref demo::message::VariantsFields::Props1Members::Property field.
        struct PropertyCommon
        {
            /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::Property field.
            static const char* name()
            {
                return "Property";
            }
            
        };
        
        
        /// @brief Common types and functions for
        ///     @ref demo::message::VariantsFields::Props1Members::Count field.
        struct CountCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::VariantsFields::Props1Members::Count field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::VariantsFields::Props1Members::Count field.
            static const char* name()
            {
                return "Count";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::VariantsFields::Props1 field.
    struct Props1Common
    {
        /// @brief Name of the @ref demo::message::VariantsFields::Props1 field.
        static const char* name()
        {
            return "Props1";
        }
        
    };
    
    
    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref demo::message::VariantsFields::Props2 list.
    struct Props2MembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref demo::message::VariantsFields::Props2Members::Property bundle.
        struct PropertyMembersCommon
        {
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1 field.
            struct Prop1MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Type field.
                struct TypeCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Type field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Type field.
                    static const char* name()
                    {
                        return "Type";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Length field.
                using LengthCommon = demo::field::PropRemLenCommon;
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Val field.
                struct ValCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Val field.
                    using ValueType = std::int16_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1 field.
            struct Prop1Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop1 field.
                static const char* name()
                {
                    return "Prop1";
                }
                
            };
            
            
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2 field.
            struct Prop2MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Type field.
                struct TypeCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Type field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Type field.
                    static const char* name()
                    {
                        return "Type";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Length field.
                using LengthCommon = demo::field::PropRemLenCommon;
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Val field.
                struct ValCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Val field.
                    using ValueType = std::uint32_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2 field.
            struct Prop2Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop2 field.
                static const char* name()
                {
                    return "Prop2";
                }
                
            };
            
            
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3 field.
            struct Prop3MembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Type field.
                struct TypeCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Type field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Type field.
                    static const char* name()
                    {
                        return "Type";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Length field.
                using LengthCommon = demo::field::PropRemLenCommon;
                
                /// @brief Scope for all the common definitions of the
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Val field.
                struct ValCommon
                {
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3 field.
            struct Prop3Common
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3 field.
                static const char* name()
                {
                    return "Prop3";
                }
                
            };
            
            
            /// @brief Scope for all the common definitions of the member fields of
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownProp field.
            struct UnknownPropMembersCommon
            {
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Type field.
                struct TypeCommon
                {
                    /// @brief Re-definition of the value type used by
                    ///     demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Type field.
                    using ValueType = std::uint8_t;
                
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Type field.
                    static const char* name()
                    {
                        return "Type";
                    }
                    
                };
                
                /// @brief Common types and functions for
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Length field.
                using LengthCommon = demo::field::PropRemLenCommon;
                
                /// @brief Scope for all the common definitions of the
                ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Val field.
                struct ValCommon
                {
                    /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Val field.
                    static const char* name()
                    {
                        return "Val";
                    }
                    
                };
                
                
            };
            
            /// @brief Scope for all the common definitions of the
            ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownProp field.
            struct UnknownPropCommon
            {
                /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownProp field.
                static const char* name()
                {
                    return "UnknownProp";
                }
                
            };
            
            
        };
        
        /// @brief Scope for all the common definitions of the
        ///     @ref demo::message::VariantsFields::Props2Members::Property field.
        struct PropertyCommon
        {
            /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::Property field.
            static const char* name()
            {
                return "Property";
            }
            
        };
        
        
        /// @brief Common types and functions for
        ///     @ref demo::message::VariantsFields::Props2Members::Length field.
        struct LengthCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::message::VariantsFields::Props2Members::Length field.
            using ValueType = std::uint8_t;
        
            /// @brief Name of the @ref demo::message::VariantsFields::Props2Members::Length field.
            static const char* name()
            {
                return "Length";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the
    ///     @ref demo::message::VariantsFields::Props2 field.
    struct Props2Common
    {
        /// @brief Name of the @ref demo::message::VariantsFields::Props2 field.
        static const char* name()
        {
            return "Props2";
        }
        
    };
    
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Variants message.
/// @see demo::message::Variants
struct VariantsCommon
{
    /// @brief Name of the @ref demo::message::Variants message.
    static const char* name()
    {
        return "Variants";
    }
    
};

} // namespace message

} // namespace demo


