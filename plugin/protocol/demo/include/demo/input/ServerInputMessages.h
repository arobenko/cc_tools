
/// @file
/// @brief Contains definition of all server input messages bundle.

#pragma once

#include <tuple>
#include "demo/message/Bitfields.h"
#include "demo/message/Datas.h"
#include "demo/message/Enums.h"
#include "demo/message/Floats.h"
#include "demo/message/Lists.h"
#include "demo/message/Optionals.h"
#include "demo/message/ScaledInts.h"
#include "demo/message/Sets.h"
#include "demo/message/SimpleInts.h"
#include "demo/message/Strings.h"
#include "demo/message/Variants.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = demo::options::DefaultOptions>
using ServerInputMessages =
    std::tuple<
        demo::message::SimpleInts<TBase, TOpt>,
        demo::message::ScaledInts<TBase, TOpt>,
        demo::message::Floats<TBase, TOpt>,
        demo::message::Enums<TBase, TOpt>,
        demo::message::Sets<TBase, TOpt>,
        demo::message::Bitfields<TBase, TOpt>,
        demo::message::Strings<TBase, TOpt>,
        demo::message::Datas<TBase, TOpt>,
        demo::message::Lists<TBase, TOpt>,
        demo::message::Optionals<TBase, TOpt>,
        demo::message::Variants<TBase, TOpt>
    >;

} // namespace input

} // namespace demo


