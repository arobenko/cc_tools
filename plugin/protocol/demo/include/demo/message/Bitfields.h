
/// @file
/// @brief Contains definition of <b>"Bitfields"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include "comms/MessageBase.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/message/BitfieldsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Bitfields.
/// @tparam TOpt Extra options
/// @see @ref Bitfields
/// @headerfile "demo/message/Bitfields.h"
template <typename TOpt = demo::options::DefaultOptions>
struct BitfieldsFields
{
    /// @brief Scope for all the member fields of
    ///     @ref F1 bitfield.
    struct F1Members
    {
        /// @brief Definition of <b>"Mem1"</b> field.
        struct Mem1 : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::FixedBitLength<3U>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem1Common::name();
            }
            
        };
        
        /// @brief Definition of <b>"Mem2"</b> field.
        class Mem2 : public
            comms::field::BitmaskValue<
                demo::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    demo::field::FieldBase<>,
                    comms::option::def::FixedBitLength<3U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_Bit0, @b getBitValue_Bit0() and @b setBitValue_Bit0().
            ///      @li @b BitIdx_Bit1, @b getBitValue_Bit1() and @b setBitValue_Bit1().
            ///      @li @b BitIdx_Bit2, @b getBitValue_Bit2() and @b setBitValue_Bit2().
            COMMS_BITMASK_BITS_SEQ(
                Bit0,
                Bit1,
                Bit2
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem2Common::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem2Common::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"Mem3"</b> field.
        /// @see @ref demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem3Val
        class Mem3 : public
            comms::field::EnumValue<
                demo::field::FieldBase<>,
                demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem3Val,
                comms::option::def::FixedBitLength<2U>,
                comms::option::def::ValidNumValue<0>,
                comms::option::def::ValidNumValue<3>
            >
        {
            using Base = 
                comms::field::EnumValue<
                    demo::field::FieldBase<>,
                    demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem3Val,
                    comms::option::def::FixedBitLength<2U>,
                    comms::option::def::ValidNumValue<0>,
                    comms::option::def::ValidNumValue<3>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;
        
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem3Common::name();
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                return demo::message::BitfieldsFieldsCommon::F1MembersCommon::Mem3Common::valueName(val);
            }
            
            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::value());
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               Mem1,
               Mem2,
               Mem3
            >;
    };
    
    /// @brief Definition of <b>"F1"</b> field.
    class F1 : public
        comms::field::Bitfield<
            demo::field::FieldBase<>,
            typename F1Members::All
        >
    {
        using Base = 
            comms::field::Bitfield<
                demo::field::FieldBase<>,
                typename F1Members::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///     The generated types and access functions are:
        ///     @li @b Field_mem1 type and @b field_mem1() access function -
        ///         for F1Members::Mem1 member field.
        ///     @li @b Field_mem2 type and @b field_mem2() access function -
        ///         for F1Members::Mem2 member field.
        ///     @li @b Field_mem3 type and @b field_mem3() access function -
        ///         for F1Members::Mem3 member field.
        COMMS_FIELD_MEMBERS_NAMES(
            mem1,
            mem2,
            mem3
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::BitfieldsFieldsCommon::F1Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        F1
    >;
};

/// @brief Definition of <b>"Bitfields"</b> message class.
/// @details
///     See @ref BitfieldsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Bitfields.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Bitfields : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Bitfields,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Bitfields>,
        comms::option::def::FieldsImpl<typename BitfieldsFields<TOpt>::All>,
        comms::option::def::MsgType<Bitfields<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Bitfields,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Bitfields>,
            comms::option::def::FieldsImpl<typename BitfieldsFields<TOpt>::All>,
            comms::option::def::MsgType<Bitfields<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_f1 type and @b field_f1() access fuction
    ///         for @ref BitfieldsFields::F1 field.
    COMMS_MSG_FIELDS_NAMES(
        f1
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 1U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::BitfieldsCommon::name();
    }
    
    
};

} // namespace message

} // namespace demo


