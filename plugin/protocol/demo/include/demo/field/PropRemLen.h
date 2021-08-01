
/// @file
/// @brief Contains definition of <b>"Length"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo/field/FieldBase.h"
#include "demo/field/PropRemLenCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace field
{

/// @brief Definition of <b>"Length"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = demo::options::DefaultOptions, typename... TExtraOpts>
struct PropRemLen : public
    comms::field::IntValue<
        demo::field::FieldBase<>,
        std::uint16_t,
        TExtraOpts...
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return demo::field::PropRemLenCommon::name();
    }
    
};

} // namespace field

} // namespace demo


