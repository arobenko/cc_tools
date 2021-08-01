
/// @file
/// @brief Contains definition of <b>"Ack"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/field/MsgId.h"
#include "demo/message/AckCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Ack.
/// @tparam TOpt Extra options
/// @see @ref Ack
/// @headerfile "demo/message/Ack.h"
template <typename TOpt = demo::options::DefaultOptions>
struct AckFields
{
    /// @brief Definition of <b>"MsgId"</b> field.
    using MsgId =
        demo::field::MsgId<
            TOpt
        >;
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        MsgId
    >;
};

/// @brief Definition of <b>"Ack"</b> message class.
/// @details
///     See @ref AckFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Ack.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Ack : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Ack,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Ack>,
        comms::option::def::FieldsImpl<typename AckFields<TOpt>::All>,
        comms::option::def::MsgType<Ack<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Ack,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Ack>,
            comms::option::def::FieldsImpl<typename AckFields<TOpt>::All>,
            comms::option::def::MsgType<Ack<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_msgId type and @b field_msgId() access fuction
    ///         for @ref AckFields::MsgId field.
    COMMS_MSG_FIELDS_NAMES(
        msgId
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 1U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 1U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::AckCommon::name();
    }
    
    
};

} // namespace message

} // namespace demo


