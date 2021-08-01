
/// @file
/// @brief Contains definition of <b>"Lon"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo/field/FieldBase.h"
#include "demo/field/LonCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace field
{

/// @brief Definition of <b>"Lon"</b> field.
/// @details
///     Longitude in 1/10^7 of the degrees
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = demo::options::DefaultOptions, typename... TExtraOpts>
struct Lon : public
    comms::field::IntValue<
        demo::field::FieldBase<>,
        std::int32_t,
        TExtraOpts...,
        comms::option::def::ScalingRatio<1, 10000000L>,
        comms::option::def::UnitsDegrees
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return demo::field::LonCommon::name();
    }
    
};

} // namespace field

} // namespace demo


