
/// @file
/// @brief Contains definition of all client input messages bundle.

#pragma once

#include <tuple>
#include "demo/message/Ack.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = demo::options::DefaultOptions>
using ClientInputMessages =
    std::tuple<
        demo::message::Ack<TBase, TOpt>
    >;

} // namespace input

} // namespace demo


