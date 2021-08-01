
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::field::Lat field.

#pragma once

#include <cstdint>

namespace demo
{

namespace field
{

/// @brief Common types and functions for
///     @ref demo::field::Lat field.
struct LatCommon
{
    /// @brief Re-definition of the value type used by
    ///     demo::field::Lat field.
    using ValueType = std::int32_t;

    /// @brief Name of the @ref demo::field::Lat field.
    static const char* name()
    {
        return "Lat";
    }
    
};

} // namespace field

} // namespace demo


