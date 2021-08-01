
/// @file
/// @brief Contains definition of <b>"Datas"</b> message and its fields.

#pragma once

#include <cstdint>
#include <iterator>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "comms/util/assign.h"
#include "demo/MsgId.h"
#include "demo/field/FieldBase.h"
#include "demo/message/DatasCommon.h"
#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace message
{

/// @brief Fields of @ref Datas.
/// @tparam TOpt Extra options
/// @see @ref Datas
/// @headerfile "demo/message/Datas.h"
template <typename TOpt = demo::options::DefaultOptions>
struct DatasFields
{
    /// @brief Definition of <b>"F3Len"</b> field.
    /// @details
    ///     Detached length of F3.
    struct F3Len : public
        comms::field::IntValue<
            demo::field::FieldBase<>,
            std::uint8_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::DatasFieldsCommon::F3LenCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"F1"</b> field.
    /// @details
    ///     Fixed length raw data
    struct F1 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::DatasFields::F1,
            comms::option::def::SequenceFixedSize<5U>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::DatasFieldsCommon::F1Common::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref F2 list.
    struct F2Members
    {
        /// @brief Definition of <b>"Length"</b> field.
        struct Length : public
            comms::field::IntValue<
                demo::field::FieldBase<>,
                std::uint8_t
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return demo::message::DatasFieldsCommon::F2MembersCommon::LengthCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"F2"</b> field.
    /// @details
    ///     Length prefixed raw data
    class F2 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::DatasFields::F2,
            comms::option::def::SequenceSerLengthFieldPrefix<typename F2Members::Length>
        >
    {
        using Base = 
            comms::field::ArrayList<
                demo::field::FieldBase<>,
                std::uint8_t,
                typename TOpt::message::DatasFields::F2,
                comms::option::def::SequenceSerLengthFieldPrefix<typename F2Members::Length>
            >;
    public:
        /// @brief Default constructor
        F2()
        {
            static const std::uint8_t Data[] = {
                0xab, 0xcd, 0xef
            };
            comms::util::assign(Base::value(), std::begin(Data), std::end(Data));
        }
        
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::DatasFieldsCommon::F2Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"F3"</b> field.
    /// @details
    ///     Data with detached length prefix
    struct F3 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::DatasFields::F3,
            comms::option::def::SequenceLengthForcingEnabled
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::DatasFieldsCommon::F3Common::name();
        }
        
    };
    
    /// @brief Definition of <b>"F4"</b> field.
    /// @details
    ///     Data without length limit
    struct F4 : public
        comms::field::ArrayList<
            demo::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::DatasFields::F4
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return demo::message::DatasFieldsCommon::F4Common::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        F3Len,
        F1,
        F2,
        F3,
        F4
    >;
};

/// @brief Definition of <b>"Datas"</b> message class.
/// @details
///     See @ref DatasFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "demo/message/Datas.h"
template <typename TMsgBase, typename TOpt = demo::options::DefaultOptions>
class Datas : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Datas,
        comms::option::def::StaticNumIdImpl<demo::MsgId_Datas>,
        comms::option::def::FieldsImpl<typename DatasFields<TOpt>::All>,
        comms::option::def::MsgType<Datas<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Datas,
            comms::option::def::StaticNumIdImpl<demo::MsgId_Datas>,
            comms::option::def::FieldsImpl<typename DatasFields<TOpt>::All>,
            comms::option::def::MsgType<Datas<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_f3Len type and @b field_f3Len() access fuction
    ///         for @ref DatasFields::F3Len field.
    ///     @li @b Field_f1 type and @b field_f1() access fuction
    ///         for @ref DatasFields::F1 field.
    ///     @li @b Field_f2 type and @b field_f2() access fuction
    ///         for @ref DatasFields::F2 field.
    ///     @li @b Field_f3 type and @b field_f3() access fuction
    ///         for @ref DatasFields::F3 field.
    ///     @li @b Field_f4 type and @b field_f4() access fuction
    ///         for @ref DatasFields::F4 field.
    COMMS_MSG_FIELDS_NAMES(
        f3Len,
        f1,
        f2,
        f3,
        f4
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 7U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return demo::message::DatasCommon::name();
    }
    
    /// @brief Custom read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::template doReadUntilAndUpdateLen<FieldIdx_f3>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        field_f3().forceReadLength(
            static_cast<std::size_t>(field_f3Len().value()));
        
        es = Base::template doReadFrom<FieldIdx_f3>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        return comms::ErrorStatus::Success;
    }
    
    /// @brief Custom refresh functionality.
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        updated = refresh_f3() || updated;
        return updated;
    }
    
    
private:
    bool refresh_f3()
    {
        auto expectedLength = static_cast<std::size_t>(field_f3Len().value());
        auto realLength = field_f3().value().size();
        if (expectedLength != realLength) {
            using LenValueType = typename std::decay<decltype(field_f3Len().value())>::type;
            field_f3Len().value() = static_cast<LenValueType>(realLength);
            return true;
        }
        
        return false;
    }
    
};

} // namespace message

} // namespace demo


