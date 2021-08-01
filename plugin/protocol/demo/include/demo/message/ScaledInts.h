
/// @file
/// @brief Contains definition of <b>"Scaled Ints"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/field/Lat.h"
#include "demo/field/Lon.h"
#include "demo/message/ScaledIntsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref ScaledInts.
/// @tparam TOpt Extra options
/// @see @ref ScaledInts
/// @headerfile "demo/message/ScaledInts.h"
template <typename TOpt = demo::options::DefaultOptions>
struct ScaledIntsFields
{
    /// @brief Definition of <b>"Lat"</b> field.
    using Lat =
        demo::field::Lat<
            TOpt
        >;
    
    /// @brief Definition of <b>"Lon"</b> field.
    using Lon =
        demo::field::Lon<
            TOpt
        >;
    
    /// @brief Definition of <b>"Height"</b> field.
    /// @details
    ///     Height above ellipsoid in mm
    struct Height : public
        comms::field::IntValue<
            demo::field::FieldBase<>,
            std::int32_t,
            comms::option::def::UnitsMillimeters
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::ScaledIntsFieldsCommon::HeightCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Some Scaled Value"</b> field.
    /// @details
    ///     Some scaled value without units.
    struct SomeScaledVal : public
        comms::field::IntValue<
            demo::field::FieldBase<>,
            std::uint32_t,
            comms::option::def::ScalingRatio<1, 100>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::ScaledIntsFieldsCommon::SomeScaledValCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Lat,
        Lon,
        Height,
        SomeScaledVal
    >;
};

/// @brief Definition of <b>"Scaled Ints"</b> message class.
/// @details
///     See @ref ScaledIntsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/ScaledInts.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class ScaledInts : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::ScaledInts,
        comms::option::def::StaticNumIdImpl<demo::MsgId_ScaledInts>,
        comms::option::def::FieldsImpl<typename ScaledIntsFields<TOpt>::All>,
        comms::option::def::MsgType<ScaledInts<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::ScaledInts,
            comms::option::def::StaticNumIdImpl<demo::MsgId_ScaledInts>,
            comms::option::def::FieldsImpl<typename ScaledIntsFields<TOpt>::All>,
            comms::option::def::MsgType<ScaledInts<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_lat type and @b field_lat() access fuction
    ///         for @ref ScaledIntsFields::Lat field.
    ///     @li @b Field_lon type and @b field_lon() access fuction
    ///         for @ref ScaledIntsFields::Lon field.
    ///     @li @b Field_height type and @b field_height() access fuction
    ///         for @ref ScaledIntsFields::Height field.
    ///     @li @b Field_someScaledVal type and @b field_someScaledVal() access fuction
    ///         for @ref ScaledIntsFields::SomeScaledVal field.
    COMMS_MSG_FIELDS_NAMES(
        lat,
        lon,
        height,
        someScaledVal
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 16U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 16U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::ScaledIntsCommon::name();
    }
    
    
};

} // namespace message

} // namespace demo


