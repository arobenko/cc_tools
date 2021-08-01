
/// @file
/// @brief Contains definition of <b>"Optionals"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/message/OptionalsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Optionals.
/// @tparam TOpt Extra options
/// @see @ref Optionals
/// @headerfile "demo/message/Optionals.h"
template <typename TOpt = demo::options::DefaultOptions>
struct OptionalsFields
{
    /// @brief Definition of <b>"Flags"</b> field.
    /// @details
    ///     Flags indicating existence of the fields to follow
    class Flags : public
        comms::field::BitmaskValue<
            demo::field::FieldBase<>,
            comms::option::def::FixedLength<1U>,
            comms::option::def::BitmaskReservedBits<0xFCU, 0x0U>
        >
    {
        using Base = 
            comms::field::BitmaskValue<
                demo::field::FieldBase<>,
                comms::option::def::FixedLength<1U>,
                comms::option::def::BitmaskReservedBits<0xFCU, 0x0U>
            >;
    public:
        /// @brief Provides names and generates access functions for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///      The generated enum values and functions are:
        ///      @li @b BitIdx_F2Exists, @b getBitValue_F2Exists() and @b setBitValue_F2Exists().
        ///      @li @b BitIdx_F3Missing, @b getBitValue_F3Missing() and @b setBitValue_F3Missing().
        COMMS_BITMASK_BITS_SEQ(
            F2Exists,
            F3Missing
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::OptionalsFieldsCommon::FlagsCommon::name();
        }
        
        /// @brief Retrieve name of the bit.
        static const char* bitName(BitIdx idx)
        {
            return
                demo::message::OptionalsFieldsCommon::FlagsCommon::bitName(
                    static_cast<std::size_t>(idx));
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref F2 optional.
    struct F2Members
    {
        /// @brief Definition of <b>"F2"</b> field.
        struct F2 : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::DefaultNumValue<4369>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::OptionalsFieldsCommon::F2MembersCommon::F2Common::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F2"</b> field.
    struct F2 : public
        comms::field::Optional<
            typename F2Members::F2,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::OptionalsFieldsCommon::F2Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref F3 optional.
    struct F3Members
    {
        /// @brief Definition of <b>"F3"</b> field.
        struct F3 : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint16_t,
                comms::option::def::DefaultNumValue<8738>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::OptionalsFieldsCommon::F3MembersCommon::F3Common::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F3"</b> field.
    struct F3 : public
        comms::field::Optional<
            typename F3Members::F3,
            comms::option::def::ExistsByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::OptionalsFieldsCommon::F3Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags,
        F2,
        F3
    >;
};

/// @brief Definition of <b>"Optionals"</b> message class.
/// @details
///     See @ref OptionalsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Optionals.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Optionals : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Optionals,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Optionals>,
        comms::option::def::FieldsImpl<typename OptionalsFields<TOpt>::All>,
        comms::option::def::MsgType<Optionals<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Optionals,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Optionals>,
            comms::option::def::FieldsImpl<typename OptionalsFields<TOpt>::All>,
            comms::option::def::MsgType<Optionals<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_flags type and @b field_flags() access fuction
    ///         for @ref OptionalsFields::Flags field.
    ///     @li @b Field_f2 type and @b field_f2() access fuction
    ///         for @ref OptionalsFields::F2 field.
    ///     @li @b Field_f3 type and @b field_f3() access fuction
    ///         for @ref OptionalsFields::F3 field.
    COMMS_MSG_FIELDS_NAMES(
        flags,
        f2,
        f3
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 5U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::OptionalsCommon::name();
    }
    
    /// @brief Custom read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::template doReadUntilAndUpdateLen<FieldIdx_f2>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        refresh_f2();
        
        es = Base::template doReadFromUntilAndUpdateLen<FieldIdx_f2, FieldIdx_f3>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        refresh_f3();
        
        es = Base::template doReadFrom<FieldIdx_f3>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        return comms::ErrorStatus::Success;
    }
    
    /// @brief Custom refresh functionality.
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        updated = refresh_f2() || updated;
        updated = refresh_f3() || updated;
        return updated;
    }
    
    
private:
    bool refresh_f2()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (field_flags().getBitValue_F2Exists()) {
            mode = comms::field::OptionalMode::Exists;
        }
        
        if (field_f2().getMode() == mode) {
            return false;
        }
        
        field_f2().setMode(mode);
        return true;
        
    }
    
    bool refresh_f3()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (!field_flags().getBitValue_F3Missing()) {
            mode = comms::field::OptionalMode::Exists;
        }
        
        if (field_f3().getMode() == mode) {
            return false;
        }
        
        field_f3().setMode(mode);
        return true;
        
    }
    
};

} // namespace message

} // namespace demo


