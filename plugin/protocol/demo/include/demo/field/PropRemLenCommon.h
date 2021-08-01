
/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref demo::field::PropRemLen field.

#pragma once

#include <cstdint>

namespace demo
{

namespace field
{

/// @brief Common types and functions for
///     @ref demo::field::PropRemLen field.
struct PropRemLenCommon
{
    /// @brief Re-definition of the value type used by
    ///     demo::field::PropRemLen field.
    using ValueType = std::uint16_t;

    /// @brief Name of the @ref demo::field::PropRemLen field.
    static const char* name()
    {
        return "Length";
    }
    
};

} // namespace field

} // namespace demo


