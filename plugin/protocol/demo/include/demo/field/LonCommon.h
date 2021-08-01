
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::field::Lon field.

#pragma once

#include <cstdint>

namespace demo
{

namespace field
{

/// @brief Common types and functions for
///     @ref demo::field::Lon field.
struct LonCommon
{
    /// @brief Re-definition of the value type used by
    ///     demo::field::Lon field.
    using ValueType = std::int32_t;

    /// @brief Name of the @ref demo::field::Lon field.
    static const char* name()
    {
        return "Lon";
    }
    
};

} // namespace field

} // namespace demo


