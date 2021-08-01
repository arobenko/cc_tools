
/// @file
/// @brief Contains definition of <b>"Variants"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/CompileControl.h"
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Bundle.h"
#include "comms/field/IntValue.h"
#include "comms/field/String.h"
#include "comms/field/Variant.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/field/PropRemLen.h"
#include "demo/message/VariantsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Variants.
/// @tparam TOpt Extra options
/// @see @ref Variants
/// @headerfile "demo/message/Variants.h"
template <typename TOpt = demo::options::DefaultOptions>
struct VariantsFields
{
    /// @brief Scope for all the member fields of
    ///     @ref Props1 list.
    struct Props1Members
    {
        /// @brief Scope for all the member fields of
        ///     @ref Property bitfield.
        struct PropertyMembers
        {
            /// @brief Scope for all the member fields of
            ///     @ref Prop1 bundle.
            struct Prop1Members
            {
                /// @brief Definition of <b>"Key"</b> field.
                struct Key : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<1>,
                        comms::option::def::ValidNumValue<1>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop1MembersCommon::KeyCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::int16_t
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop1MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Key,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop1"</b> field.
            class Prop1 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop1Members::All
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop1Members::All
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_keytype and @b field_key() access function -
                ///         for Prop1Members::Key member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop1Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    key,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop1Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of
            ///     @ref Prop2 bundle.
            struct Prop2Members
            {
                /// @brief Definition of <b>"Key"</b> field.
                struct Key : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<2>,
                        comms::option::def::ValidNumValue<2>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop2MembersCommon::KeyCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint32_t
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop2MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Key,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop2"</b> field.
            class Prop2 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop2Members::All
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop2Members::All
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_keytype and @b field_key() access function -
                ///         for Prop2Members::Key member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop2Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    key,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop2Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of
            ///     @ref Prop3 bundle.
            struct Prop3Members
            {
                /// @brief Definition of <b>"Key"</b> field.
                struct Key : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<3>,
                        comms::option::def::ValidNumValue<3>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop3MembersCommon::KeyCommon::name();
                    }
                    
                };
                
                /// @brief Scope for all the member fields of
                ///     @ref Val string.
                struct ValMembers
                {
                    /// @brief Definition of <b>"Length"</b> field.
                    struct Length : public
                        comms::field::IntValue<
                            demo::field::FieldBase<>,
                            std::uint8_t
                        >
                    {
                        /// @brief Name of the field.
                        static const char* name()
                        {
                            return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop3MembersCommon::ValMembersCommon::LengthCommon::name();
                        }
                        
                    };
                    
                };
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::String<
                        demo::field::FieldBase<>,
                        typename TOpt::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val,
                        comms::option::def::SequenceSerLengthFieldPrefix<typename ValMembers::Length>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop3MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Key,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop3"</b> field.
            class Prop3 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop3Members::All
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop3Members::All
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_keytype and @b field_key() access function -
                ///         for Prop3Members::Key member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop3Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    key,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyMembersCommon::Prop3Common::name();
                }
                
            };
            
            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   Prop1,
                   Prop2,
                   Prop3
                >;
        };
        
        /// @brief Definition of <b>"Property"</b> field.
        class Property : public
            comms::field::Variant<
                demo::field::FieldBase<>,
                typename PropertyMembers::All,
                comms::option::def::HasCustomRead
            >
        {
            using Base = 
                comms::field::Variant<
                    demo::field::FieldBase<>,
                    typename PropertyMembers::All,
                    comms::option::def::HasCustomRead
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_VARIANT_MEMBERS_NAMES macro
            ///     related to @b comms::field::Variant class from COMMS library
            ///     for details.
            ///
            ///     The generated types and access functions are:
            ///     @li @b Field_prop1 type, @b initField_prop1() and @b accessField_prop1() access functions -
            ///     for PropertyMembers::Prop1 member field.
            ///     @li @b Field_prop2 type, @b initField_prop2() and @b accessField_prop2() access functions -
            ///     for PropertyMembers::Prop2 member field.
            ///     @li @b Field_prop3 type, @b initField_prop3() and @b accessField_prop3() access functions -
            ///     for PropertyMembers::Prop3 member field.
            COMMS_VARIANT_MEMBERS_NAMES(
                prop1,
                prop2,
                prop3
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::VariantsFieldsCommon::Props1MembersCommon::PropertyCommon::name();
            }
            
            COMMS_MSVC_WARNING_PUSH
            COMMS_MSVC_WARNING_DISABLE(4702) // Disable unreachable code warning
            /// @brief Optimized read functionality.
            template <typename TIter>
            comms::ErrorStatus read(TIter& iter, std::size_t len)
            {
                using CommonKeyField=
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t
                    >;
                CommonKeyField commonKeyField;
            
                auto origIter = iter;
                auto es = commonKeyField.read(iter, len);
                if (es != comms::ErrorStatus::Success) {
                    return es;
                }
            
                auto consumedLen = static_cast<std::size_t>(std::distance(origIter, iter));
                COMMS_ASSERT(consumedLen <= len);
                len -= consumedLen;
            
                switch (commonKeyField.value()) {
                case 1U: // 0x01U
                    {
                        auto& field_prop1 = initField_prop1();
                        COMMS_ASSERT(field_prop1.field_key().value() == commonKeyField.value());
                        return field_prop1.template readFrom<1>(iter, len);
                    }
                case 2U: // 0x02U
                    {
                        auto& field_prop2 = initField_prop2();
                        COMMS_ASSERT(field_prop2.field_key().value() == commonKeyField.value());
                        return field_prop2.template readFrom<1>(iter, len);
                    }
                case 3U: // 0x03U
                    {
                        auto& field_prop3 = initField_prop3();
                        COMMS_ASSERT(field_prop3.field_key().value() == commonKeyField.value());
                        return field_prop3.template readFrom<1>(iter, len);
                    }
                default:
                    break;
                };
            
                return comms::ErrorStatus::InvalidMsgData;
            }
            COMMS_MSVC_WARNING_POP
            
            /// @brief Optimized currFieldExec functionality.
            /// @details Replaces the currFieldExec() member function defined
            ///    by @b comms::field::Variant.
            template <typename TFunc>
            void currFieldExec(TFunc&& func) 
            {
                switch (Base::currentField()) {
                case FieldIdx_prop1:
                    memFieldDispatch<FieldIdx_prop1>(accessField_prop1(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop2:
                    memFieldDispatch<FieldIdx_prop2>(accessField_prop2(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop3:
                    memFieldDispatch<FieldIdx_prop3>(accessField_prop3(), std::forward<TFunc>(func));
                    break;
                default:
                    static constexpr bool Invalid_field_execution = false;
                    static_cast<void>(Invalid_field_execution);
                    COMMS_ASSERT(Invalid_field_execution);
                    break;
                }
            }
            
            /// @brief Optimized currFieldExec functionality (const variant).
            /// @details Replaces the currFieldExec() member function defined
            ///    by @b comms::field::Variant.
            template <typename TFunc>
            void currFieldExec(TFunc&& func) const
            {
                switch (Base::currentField()) {
                case FieldIdx_prop1:
                    memFieldDispatch<FieldIdx_prop1>(accessField_prop1(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop2:
                    memFieldDispatch<FieldIdx_prop2>(accessField_prop2(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop3:
                    memFieldDispatch<FieldIdx_prop3>(accessField_prop3(), std::forward<TFunc>(func));
                    break;
                default:
                    static constexpr bool Invalid_field_execution = false;
                    static_cast<void>(Invalid_field_execution);
                    COMMS_ASSERT(Invalid_field_execution);
                    break;
                }
            }
            
        private:
            template <std::size_t TIdx, typename TField, typename TFunc>
            static void memFieldDispatch(TField&& f, TFunc&& func)
            {
                #ifdef _MSC_VER
                    func.operator()<TIdx>(std::forward<TField>(f)); // VS compiler
                #else // #ifdef _MSC_VER
                    func.template operator()<TIdx>(std::forward<TField>(f)); // All other compilers
                #endif // #ifdef _MSC_VER
            }
        };
        
        /// @brief Definition of <b>"Count"</b> field.
        struct Count : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint8_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::VariantsFieldsCommon::Props1MembersCommon::CountCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Props1"</b> field.
    struct Props1 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            typename Props1Members::Property,
            typename TOpt::message::VariantsFields::Props1,
            comms::option::def::SequenceSizeFieldPrefix<typename Props1Members::Count>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::VariantsFieldsCommon::Props1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref Props2 list.
    struct Props2Members
    {
        /// @brief Scope for all the member fields of
        ///     @ref Property bitfield.
        struct PropertyMembers
        {
            /// @brief Scope for all the member fields of
            ///     @ref Prop1 bundle.
            struct Prop1Members
            {
                /// @brief Definition of <b>"Type"</b> field.
                struct Type : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<1>,
                        comms::option::def::ValidNumValue<1>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop1MembersCommon::TypeCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Length"</b> field.
                using Length =
                    demo::field::PropRemLen<
                        TOpt
                    >;
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::int16_t
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop1MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Type,
                       Length,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop1"</b> field.
            class Prop1 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop1Members::All,
                    comms::option::def::RemLengthMemberField<1U>
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop1Members::All,
                        comms::option::def::RemLengthMemberField<1U>
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_typetype and @b field_type() access function -
                ///         for Prop1Members::Type member field.
                ///     @li @b Field_lengthtype and @b field_length() access function -
                ///         for Prop1Members::Length member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop1Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    type,
                    length,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop1Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of
            ///     @ref Prop2 bundle.
            struct Prop2Members
            {
                /// @brief Definition of <b>"Type"</b> field.
                struct Type : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<2>,
                        comms::option::def::ValidNumValue<2>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop2MembersCommon::TypeCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Length"</b> field.
                using Length =
                    demo::field::PropRemLen<
                        TOpt
                    >;
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint32_t
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop2MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Type,
                       Length,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop2"</b> field.
            class Prop2 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop2Members::All,
                    comms::option::def::RemLengthMemberField<1U>
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop2Members::All,
                        comms::option::def::RemLengthMemberField<1U>
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_typetype and @b field_type() access function -
                ///         for Prop2Members::Type member field.
                ///     @li @b Field_lengthtype and @b field_length() access function -
                ///         for Prop2Members::Length member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop2Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    type,
                    length,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop2Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of
            ///     @ref Prop3 bundle.
            struct Prop3Members
            {
                /// @brief Definition of <b>"Type"</b> field.
                struct Type : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FailOnInvalid<>,
                        comms::option::def::DefaultNumValue<3>,
                        comms::option::def::ValidNumValue<3>
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop3MembersCommon::TypeCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Length"</b> field.
                using Length =
                    demo::field::PropRemLen<
                        TOpt
                    >;
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::String<
                        demo::field::FieldBase<>,
                        typename TOpt::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Val
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop3MembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Type,
                       Length,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"Prop3"</b> field.
            class Prop3 : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename Prop3Members::All,
                    comms::option::def::RemLengthMemberField<1U>
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename Prop3Members::All,
                        comms::option::def::RemLengthMemberField<1U>
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_typetype and @b field_type() access function -
                ///         for Prop3Members::Type member field.
                ///     @li @b Field_lengthtype and @b field_length() access function -
                ///         for Prop3Members::Length member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for Prop3Members::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    type,
                    length,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::Prop3Common::name();
                }
                
            };
            
            /// @brief Scope for all the member fields of
            ///     @ref UnknownProp bundle.
            struct UnknownPropMembers
            {
                /// @brief Definition of <b>"Type"</b> field.
                struct Type : public
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::UnknownPropMembersCommon::TypeCommon::name();
                    }
                    
                };
                
                /// @brief Definition of <b>"Length"</b> field.
                using Length =
                    demo::field::PropRemLen<
                        TOpt
                    >;
                
                /// @brief Definition of <b>"Val"</b> field.
                struct Val : public
                    comms::field::ArrayList<
                        demo::field::FieldBase<>,
                        std::uint8_t,
                        typename TOpt::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Val
                    >
                {
                    /// @brief Name of the field.
                    static const char* name()
                    {
                        return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::UnknownPropMembersCommon::ValCommon::name();
                    }
                    
                };
                
                /// @brief All members bundled in @b std::tuple.
                using All =
                    std::tuple<
                       Type,
                       Length,
                       Val
                    >;
            };
            
            /// @brief Definition of <b>"UnknownProp"</b> field.
            class UnknownProp : public
                comms::field::Bundle<
                    demo::field::FieldBase<>,
                    typename UnknownPropMembers::All,
                    comms::option::def::RemLengthMemberField<1U>
                >
            {
                using Base = 
                    comms::field::Bundle<
                        demo::field::FieldBase<>,
                        typename UnknownPropMembers::All,
                        comms::option::def::RemLengthMemberField<1U>
                    >;
            public:
                /// @brief Allow access to internal fields.
                /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
                ///     related to @b comms::field::Bundle class from COMMS library
                ///     for details.
                ///
                ///     The generated access types and functions functions are:
                ///     @li @b Field_typetype and @b field_type() access function -
                ///         for UnknownPropMembers::Type member field.
                ///     @li @b Field_lengthtype and @b field_length() access function -
                ///         for UnknownPropMembers::Length member field.
                ///     @li @b Field_valtype and @b field_val() access function -
                ///         for UnknownPropMembers::Val member field.
                COMMS_FIELD_MEMBERS_NAMES(
                    type,
                    length,
                    val
                );
                
                /// @brief Name of the field.
                static const char* name()
                {
                    return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyMembersCommon::UnknownPropCommon::name();
                }
                
            };
            
            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   Prop1,
                   Prop2,
                   Prop3,
                   UnknownProp
                >;
        };
        
        /// @brief Definition of <b>"Property"</b> field.
        class Property : public
            comms::field::Variant<
                demo::field::FieldBase<>,
                typename PropertyMembers::All,
                comms::option::def::HasCustomRead
            >
        {
            using Base = 
                comms::field::Variant<
                    demo::field::FieldBase<>,
                    typename PropertyMembers::All,
                    comms::option::def::HasCustomRead
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_VARIANT_MEMBERS_NAMES macro
            ///     related to @b comms::field::Variant class from COMMS library
            ///     for details.
            ///
            ///     The generated types and access functions are:
            ///     @li @b Field_prop1 type, @b initField_prop1() and @b accessField_prop1() access functions -
            ///     for PropertyMembers::Prop1 member field.
            ///     @li @b Field_prop2 type, @b initField_prop2() and @b accessField_prop2() access functions -
            ///     for PropertyMembers::Prop2 member field.
            ///     @li @b Field_prop3 type, @b initField_prop3() and @b accessField_prop3() access functions -
            ///     for PropertyMembers::Prop3 member field.
            ///     @li @b Field_unknownProp type, @b initField_unknownProp() and @b accessField_unknownProp() access functions -
            ///     for PropertyMembers::UnknownProp member field.
            COMMS_VARIANT_MEMBERS_NAMES(
                prop1,
                prop2,
                prop3,
                unknownProp
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::VariantsFieldsCommon::Props2MembersCommon::PropertyCommon::name();
            }
            
            COMMS_MSVC_WARNING_PUSH
            COMMS_MSVC_WARNING_DISABLE(4702) // Disable unreachable code warning
            /// @brief Optimized read functionality.
            template <typename TIter>
            comms::ErrorStatus read(TIter& iter, std::size_t len)
            {
                using CommonKeyField=
                    comms::field::IntValue<
                        demo::field::FieldBase<>,
                        std::uint8_t
                    >;
                CommonKeyField commonKeyField;
            
                auto origIter = iter;
                auto es = commonKeyField.read(iter, len);
                if (es != comms::ErrorStatus::Success) {
                    return es;
                }
            
                auto consumedLen = static_cast<std::size_t>(std::distance(origIter, iter));
                COMMS_ASSERT(consumedLen <= len);
                len -= consumedLen;
            
                switch (commonKeyField.value()) {
                case 1U: // 0x01U
                    {
                        auto& field_prop1 = initField_prop1();
                        COMMS_ASSERT(field_prop1.field_type().value() == commonKeyField.value());
                        return field_prop1.template readFrom<1>(iter, len);
                    }
                case 2U: // 0x02U
                    {
                        auto& field_prop2 = initField_prop2();
                        COMMS_ASSERT(field_prop2.field_type().value() == commonKeyField.value());
                        return field_prop2.template readFrom<1>(iter, len);
                    }
                case 3U: // 0x03U
                    {
                        auto& field_prop3 = initField_prop3();
                        COMMS_ASSERT(field_prop3.field_type().value() == commonKeyField.value());
                        return field_prop3.template readFrom<1>(iter, len);
                    }
                default:
                    initField_unknownProp().field_type().value() = commonKeyField.value();
                    return accessField_unknownProp().template readFrom<1>(iter, len);
                };
            
                return comms::ErrorStatus::InvalidMsgData;
            }
            COMMS_MSVC_WARNING_POP
            
            /// @brief Optimized currFieldExec functionality.
            /// @details Replaces the currFieldExec() member function defined
            ///    by @b comms::field::Variant.
            template <typename TFunc>
            void currFieldExec(TFunc&& func) 
            {
                switch (Base::currentField()) {
                case FieldIdx_prop1:
                    memFieldDispatch<FieldIdx_prop1>(accessField_prop1(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop2:
                    memFieldDispatch<FieldIdx_prop2>(accessField_prop2(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop3:
                    memFieldDispatch<FieldIdx_prop3>(accessField_prop3(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_unknownProp:
                    memFieldDispatch<FieldIdx_unknownProp>(accessField_unknownProp(), std::forward<TFunc>(func));
                    break;
                default:
                    static constexpr bool Invalid_field_execution = false;
                    static_cast<void>(Invalid_field_execution);
                    COMMS_ASSERT(Invalid_field_execution);
                    break;
                }
            }
            
            /// @brief Optimized currFieldExec functionality (const variant).
            /// @details Replaces the currFieldExec() member function defined
            ///    by @b comms::field::Variant.
            template <typename TFunc>
            void currFieldExec(TFunc&& func) const
            {
                switch (Base::currentField()) {
                case FieldIdx_prop1:
                    memFieldDispatch<FieldIdx_prop1>(accessField_prop1(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop2:
                    memFieldDispatch<FieldIdx_prop2>(accessField_prop2(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_prop3:
                    memFieldDispatch<FieldIdx_prop3>(accessField_prop3(), std::forward<TFunc>(func));
                    break;
                case FieldIdx_unknownProp:
                    memFieldDispatch<FieldIdx_unknownProp>(accessField_unknownProp(), std::forward<TFunc>(func));
                    break;
                default:
                    static constexpr bool Invalid_field_execution = false;
                    static_cast<void>(Invalid_field_execution);
                    COMMS_ASSERT(Invalid_field_execution);
                    break;
                }
            }
            
        private:
            template <std::size_t TIdx, typename TField, typename TFunc>
            static void memFieldDispatch(TField&& f, TFunc&& func)
            {
                #ifdef _MSC_VER
                    func.operator()<TIdx>(std::forward<TField>(f)); // VS compiler
                #else // #ifdef _MSC_VER
                    func.template operator()<TIdx>(std::forward<TField>(f)); // All other compilers
                #endif // #ifdef _MSC_VER
            }
        };
        
        /// @brief Definition of <b>"Length"</b> field.
        struct Length : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint8_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::VariantsFieldsCommon::Props2MembersCommon::LengthCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Props2"</b> field.
    struct Props2 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            typename Props2Members::Property,
            typename TOpt::message::VariantsFields::Props2,
            comms::option::def::SequenceSerLengthFieldPrefix<typename Props2Members::Length>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::VariantsFieldsCommon::Props2Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Props1,
        Props2
    >;
};

/// @brief Definition of <b>"Variants"</b> message class.
/// @details
///     To demonstrate usage of variants fields, this message contains
///     a list of heterogatious values implemented using variant field.
///     Every element is a key-value pair. @n
///     See @ref VariantsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Variants.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Variants : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Variants,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Variants>,
        comms::option::def::FieldsImpl<typename VariantsFields<TOpt>::All>,
        comms::option::def::MsgType<Variants<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Variants,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Variants>,
            comms::option::def::FieldsImpl<typename VariantsFields<TOpt>::All>,
            comms::option::def::MsgType<Variants<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_props1 type and @b field_props1() access fuction
    ///         for @ref VariantsFields::Props1 field.
    ///     @li @b Field_props2 type and @b field_props2() access fuction
    ///         for @ref VariantsFields::Props2 field.
    COMMS_MSG_FIELDS_NAMES(
        props1,
        props2
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::VariantsCommon::name();
    }
    
    
};

} // namespace message

} // namespace demo


