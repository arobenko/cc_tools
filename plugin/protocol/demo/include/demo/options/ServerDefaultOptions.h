
/// @file
/// @brief Contains definition of protocol default options for a server.

#pragma once

#include "DefaultOptions.h"

namespace demo
{

namespace options
{

/// @brief Default options of the protocol for a server.
/// @tparam TBase Options to use as a basis.
template <typename TBase = demo::options::DefaultOptions>
struct ServerDefaultOptionsT : public TBase
{
    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for
        ///     @ref demo::message::Ack message.
        using Ack =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Ack
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Bitfields message.
        using Bitfields =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Bitfields
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Datas message.
        using Datas =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Datas
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Enums message.
        using Enums =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Enums
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Floats message.
        using Floats =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Floats
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Lists message.
        using Lists =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Lists
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Optionals message.
        using Optionals =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Optionals
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::ScaledInts message.
        using ScaledInts =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::ScaledInts
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Sets message.
        using Sets =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Sets
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::SimpleInts message.
        using SimpleInts =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::SimpleInts
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Strings message.
        using Strings =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Strings
            >;
        
        /// @brief Extra options for
        ///     @ref demo::message::Variants message.
        using Variants =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Variants
            >;
        
    };
    
};

/// @brief Alias to @ref ServerDefaultOptionsT with default template parameter.
using ServerDefaultOptions = ServerDefaultOptionsT<>;

} // namespace options

} // namespace demo


