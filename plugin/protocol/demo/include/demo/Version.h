
/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol specification.
#define DEMO_SPEC_VERSION (0U)

/// @brief Major version of the protocol library.
#define DEMO_MAJOR_VERSION (0U)

/// @brief Minor version of the protocol library.
#define DEMO_MINOR_VERSION (20U)

/// @brief Patch version of the protocol library.
#define DEMO_PATCH_VERSION (1U)

/// @brief Full version of the protocol library as single number.
#define DEMO_VERSION (COMMS_MAKE_VERSION(DEMO_MAJOR_VERSION, DEMO_MINOR_VERSION, DEMO_PATCH_VERSION))


namespace demo
{

/// @brief Version of the protocol specification.
inline constexpr unsigned specVersion()
{
    return DEMO_SPEC_VERSION;
}

/// @brief Major version of the protocol library
inline constexpr unsigned versionMajor()
{
    return DEMO_MAJOR_VERSION;
}

/// @brief Minor version of the protocol library
inline constexpr unsigned versionMinor()
{
    return DEMO_MINOR_VERSION;
}

/// @brief Patch version of the protocol library
inline constexpr unsigned versionPatch()
{
    return DEMO_PATCH_VERSION;
}

/// @brief Full version of the protocol library as single number
inline constexpr unsigned version()
{
    return DEMO_VERSION;
}


} // namespace demo


// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(3, 2, 0) <= comms::version(),
    "The version of COMMS library is too old");

