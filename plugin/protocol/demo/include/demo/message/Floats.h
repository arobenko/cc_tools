
/// @file
/// @brief Contains definition of <b>"Floats"</b> message and its fields.

#pragma once

#include <cmath>
#include <limits>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/FloatValue.h"
#include "comms/options.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/message/FloatsCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Floats.
/// @tparam TOpt Extra options
/// @see @ref Floats
/// @headerfile "demo/message/Floats.h"
template <typename TOpt = demo::options::DefaultOptions>
struct FloatsFields
{
    /// @brief Definition of <b>"Timeout"</b> field.
    class Timeout : public
        comms::field::FloatValue<
            demo::field::FieldBase<>,
            float,
            comms::option::def::UnitsSeconds
        >
    {
        using Base = 
            comms::field::FloatValue<
                demo::field::FieldBase<>,
                float,
                comms::option::def::UnitsSeconds
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Special value <b>"Infinite"</b>.
        static constexpr ValueType valueInfinite()
        {
            return demo::message::FloatsFieldsCommon::TimeoutCommon::valueInfinite();
        }
        
        /// @brief Check the value is equal to special @ref valueInfinite().
        bool isInfinite() const
        {
            return (std::abs(Base::value() - static_cast<ValueType>(0.000000)) < std::numeric_limits<ValueType>::epsilon());
        }
        
        /// @brief Assign special value @ref valueInfinite() to the field.
        void setInfinite()
        {
            Base::value() = valueInfinite();
        }
        
        /// @brief Special value <b>"Invalid"</b>.
        static constexpr ValueType valueInvalid()
        {
            return demo::message::FloatsFieldsCommon::TimeoutCommon::valueInvalid();
        }
        
        /// @brief Check the value is equal to special @ref valueInvalid().
        bool isInvalid() const
        {
            return (std::isnan(Base::value()));
        }
        
        /// @brief Assign special value @ref valueInvalid() to the field.
        void setInvalid()
        {
            Base::value() = valueInvalid();
        }
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::FloatsFieldsCommon::TimeoutCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Distance"</b> field.
    class Distance : public
        comms::field::FloatValue<
            demo::field::FieldBase<>,
            float,
            comms::option::def::UnitsMeters
        >
    {
        using Base = 
            comms::field::FloatValue<
                demo::field::FieldBase<>,
                float,
                comms::option::def::UnitsMeters
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;
    
        /// @brief Default constructor.
        Distance()
        {
            Base::value() = std::numeric_limits<ValueType>::quiet_NaN();
        }
        
        /// @brief Special value <b>"Infinite"</b>.
        static constexpr ValueType valueInfinite()
        {
            return demo::message::FloatsFieldsCommon::DistanceCommon::valueInfinite();
        }
        
        /// @brief Check the value is equal to special @ref valueInfinite().
        bool isInfinite() const
        {
            return ((0 < Base::value()) &&
                    (std::isinf(Base::value())));
        }
        
        /// @brief Assign special value @ref valueInfinite() to the field.
        void setInfinite()
        {
            Base::value() = valueInfinite();
        }
        
        /// @brief Special value <b>"Invalid"</b>.
        static constexpr ValueType valueInvalid()
        {
            return demo::message::FloatsFieldsCommon::DistanceCommon::valueInvalid();
        }
        
        /// @brief Check the value is equal to special @ref valueInvalid().
        bool isInvalid() const
        {
            return (std::isnan(Base::value()));
        }
        
        /// @brief Assign special value @ref valueInvalid() to the field.
        void setInvalid()
        {
            Base::value() = valueInvalid();
        }
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::FloatsFieldsCommon::DistanceCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Timeout,
        Distance
    >;
};

/// @brief Definition of <b>"Floats"</b> message class.
/// @details
///     See @ref FloatsFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Floats.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Floats : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Floats,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Floats>,
        comms::option::def::FieldsImpl<typename FloatsFields<TOpt>::All>,
        comms::option::def::MsgType<Floats<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Floats,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Floats>,
            comms::option::def::FieldsImpl<typename FloatsFields<TOpt>::All>,
            comms::option::def::MsgType<Floats<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_timeout type and @b field_timeout() access fuction
    ///         for @ref FloatsFields::Timeout field.
    ///     @li @b Field_distance type and @b field_distance() access fuction
    ///         for @ref FloatsFields::Distance field.
    COMMS_MSG_FIELDS_NAMES(
        timeout,
        distance
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 8U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 8U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::FloatsCommon::name();
    }
    
    
};

} // namespace message

} // namespace demo


