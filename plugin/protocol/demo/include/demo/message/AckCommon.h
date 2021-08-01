
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::message::Ack message and its fields.

#pragma once

#include "demo/field/MsgIdCommon.h"

namespace demo
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref demo::message::Ack message.
/// @see demo::message::AckFields
struct AckFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref demo::message::AckFields::MsgId field.
    using MsgIdCommon = demo::field::MsgIdCommon;
    
};

/// @brief Common types and functions of 
///     @ref demo::message::Ack message.
/// @see demo::message::Ack
struct AckCommon
{
    /// @brief Name of the @ref demo::message::Ack message.
    static const char* name()
    {
        return "Ack";
    }
    
};

} // namespace message

} // namespace demo


