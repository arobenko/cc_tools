
/// @file
/// @brief Contains definition of <b>"Strings"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/field/String.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/message/StringsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Strings.
/// @tparam TOpt Extra options
/// @see @ref Strings
/// @headerfile "demo/message/Strings.h"
template <typename TOpt = demo::options::DefaultOptions>
struct StringsFields
{
    /// @brief Definition of <b>"F4Len"</b> field.
    /// @details
    ///     Detached length of F4.
    struct F4Len : public
        comms::field::IntValue<
            demo::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F4LenCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"F1"</b> field.
    /// @details
    ///     Fixed length string
    struct F1 : public
        comms::field::String<
            demo::field::FieldBase<>,
            typename TOpt::message::StringsFields::F1,
            comms::option::def::SequenceFixedSize<5U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref F2 string.
    struct F2Members
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
                return demo::message::StringsFieldsCommon::F2MembersCommon::LengthCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F2"</b> field.
    /// @details
    ///     Length prefixed string
    class F2 : public
        comms::field::String<
            demo::field::FieldBase<>,
            typename TOpt::message::StringsFields::F2,
            comms::option::def::SequenceSerLengthFieldPrefix<typename F2Members::Length>
        >
    {
        using Base = 
            comms::field::String<
                demo::field::FieldBase<>,
                typename TOpt::message::StringsFields::F2,
                comms::option::def::SequenceSerLengthFieldPrefix<typename F2Members::Length>
            >;
    public:
        /// @brief Default constructor
        F2()
        {
            static const char Str[] = "hello";
            static const std::size_t StrSize = std::extent<decltype(Str)>::value;
            Base::value() = typename Base::ValueType(&Str[0], StrSize - 1);
        }
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"F3"</b> field.
    /// @details
    ///     Zero terminated string
    struct F3 : public
        comms::field::String<
            demo::field::FieldBase<>,
            typename TOpt::message::StringsFields::F3,
            comms::option::def::SequenceTerminationFieldSuffix<
                comms::field::IntValue<
                    demo::field::FieldBase<>,
                    std::uint8_t,
                    comms::option::def::ValidNumValueRange<0, 0>
                >
            >
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F3Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"F4"</b> field.
    /// @details
    ///     String with detached length prefix
    struct F4 : public
        comms::field::String<
            demo::field::FieldBase<>,
            typename TOpt::message::StringsFields::F4,
            comms::option::def::SequenceLengthForcingEnabled
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F4Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"F5"</b> field.
    /// @details
    ///     String without length limit
    struct F5 : public
        comms::field::String<
            demo::field::FieldBase<>,
            typename TOpt::message::StringsFields::F5
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::StringsFieldsCommon::F5Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        F4Len,
        F1,
        F2,
        F3,
        F4,
        F5
    >;
};

/// @brief Definition of <b>"Strings"</b> message class.
/// @details
///     See @ref StringsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Strings.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Strings : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Strings,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Strings>,
        comms::option::def::FieldsImpl<typename StringsFields<TOpt>::All>,
        comms::option::def::MsgType<Strings<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Strings,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Strings>,
            comms::option::def::FieldsImpl<typename StringsFields<TOpt>::All>,
            comms::option::def::MsgType<Strings<TMsgBase, TOpt> >,
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
    ///     @li @b Field_f4Len type and @b field_f4Len() access fuction
    ///         for @ref StringsFields::F4Len field.
    ///     @li @b Field_f1 type and @b field_f1() access fuction
    ///         for @ref StringsFields::F1 field.
    ///     @li @b Field_f2 type and @b field_f2() access fuction
    ///         for @ref StringsFields::F2 field.
    ///     @li @b Field_f3 type and @b field_f3() access fuction
    ///         for @ref StringsFields::F3 field.
    ///     @li @b Field_f4 type and @b field_f4() access fuction
    ///         for @ref StringsFields::F4 field.
    ///     @li @b Field_f5 type and @b field_f5() access fuction
    ///         for @ref StringsFields::F5 field.
    COMMS_MSG_FIELDS_NAMES(
        f4Len,
        f1,
        f2,
        f3,
        f4,
        f5
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 8U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::StringsCommon::name();
    }
    
    /// @brief Custom read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::template doReadUntilAndUpdateLen<FieldIdx_f4>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        field_f4().forceReadLength(
            static_cast<std::size_t>(field_f4Len().value()));
        
        es = Base::template doReadFrom<FieldIdx_f4>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        return comms::ErrorStatus::Success;
    }
    
    /// @brief Custom refresh functionality.
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        updated = refresh_f4() || updated;
        return updated;
    }
    
    
private:
    bool refresh_f4()
    {
        auto expectedLength = static_cast<std::size_t>(field_f4Len().value());
        auto realLength = field_f4().value().size();
        if (expectedLength != realLength) {
            using LenValueType = typename std::decay<decltype(field_f4Len().value())>::type;
            field_f4Len().value() = static_cast<LenValueType>(realLength);
            return true;
        }
        
        return false;
    }
    
};

} // namespace message

} // namespace demo


