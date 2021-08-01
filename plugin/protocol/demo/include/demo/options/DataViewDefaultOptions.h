
/// @file
/// @brief Contains definition of protocol default options that apply
///     @b comms::option::app::OrigDataView to applicable fields.

#pragma once

#include "demo/options/DefaultOptions.h"

namespace demo
{

namespace options
{

/// @brief Default options for data view on contiguous buffers to avoid
///    unnecessary copy of data.
/// @tparam TBase Options to use as a basis.
template <typename TBase = demo::options::DefaultOptions>
struct DataViewDefaultOptionsT : public TBase
{
    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for
        ///     @ref demo::message::Ack message.
        using Ack = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::Bitfields message.
        using Bitfields = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref demo::message::Datas message.
        struct DatasFields : public TBase::message::DatasFields
        {
            /// @brief Extra options for @ref
            ///     demo::message::DatasFields::F1 field.
            using F1 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::DatasFields::F1
                >;
            /// @brief Extra options for @ref
            ///     demo::message::DatasFields::F2 field.
            using F2 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::DatasFields::F2
                >;
            /// @brief Extra options for @ref
            ///     demo::message::DatasFields::F3 field.
            using F3 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::DatasFields::F3
                >;
            /// @brief Extra options for @ref
            ///     demo::message::DatasFields::F4 field.
            using F4 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::DatasFields::F4
                >;
        }; // struct DatasFields
        
        /// @brief Extra options for
        ///     @ref demo::message::Datas message.
        using Datas = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::Enums message.
        using Enums = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::Floats message.
        using Floats = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref demo::message::Lists message.
        struct ListsFields : public TBase::message::ListsFields
        {
            /// @brief Extra options for all the member fields of
            ///     @ref demo::message::ListsFields::F4 list.
            struct F4Members : public TBase::message::ListsFields::F4Members
            {
                /// @brief Extra options for all the member fields of
                ///     @ref demo::message::ListsFields::F4Members::Element bundle.
                struct ElementMembers : public TBase::message::ListsFields::F4Members::ElementMembers
                {
                    /// @brief Extra options for @ref
                    ///     demo::message::ListsFields::F4Members::ElementMembers::Mem2
                    ///     field.
                    using Mem2 = 
                        std::tuple<
                            comms::option::app::OrigDataView,
                            typename TBase::message::ListsFields::F4Members::ElementMembers::Mem2
                        >;
                };
                
            };
            
        }; // struct ListsFields
        
        /// @brief Extra options for
        ///     @ref demo::message::Lists message.
        using Lists = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::Optionals message.
        using Optionals = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::ScaledInts message.
        using ScaledInts = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::Sets message.
        using Sets = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref demo::message::SimpleInts message.
        using SimpleInts = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref demo::message::Strings message.
        struct StringsFields : public TBase::message::StringsFields
        {
            /// @brief Extra options for @ref
            ///     demo::message::StringsFields::F1 field.
            using F1 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::StringsFields::F1
                >;
            /// @brief Extra options for @ref
            ///     demo::message::StringsFields::F2 field.
            using F2 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::StringsFields::F2
                >;
            /// @brief Extra options for @ref
            ///     demo::message::StringsFields::F3 field.
            using F3 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::StringsFields::F3
                >;
            /// @brief Extra options for @ref
            ///     demo::message::StringsFields::F4 field.
            using F4 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::StringsFields::F4
                >;
            /// @brief Extra options for @ref
            ///     demo::message::StringsFields::F5 field.
            using F5 = 
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::StringsFields::F5
                >;
        }; // struct StringsFields
        
        /// @brief Extra options for
        ///     @ref demo::message::Strings message.
        using Strings = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref demo::message::Variants message.
        struct VariantsFields : public TBase::message::VariantsFields
        {
            /// @brief Extra options for all the member fields of
            ///     @ref demo::message::VariantsFields::Props1 list.
            struct Props1Members : public TBase::message::VariantsFields::Props1Members
            {
                /// @brief Extra options for all the member fields of
                ///     @ref demo::message::VariantsFields::Props1Members::Property bitfield.
                struct PropertyMembers : public TBase::message::VariantsFields::Props1Members::PropertyMembers
                {
                    /// @brief Extra options for all the member fields of
                    ///     @ref demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3 bundle.
                    struct Prop3Members : public TBase::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members
                    {
                        /// @brief Extra options for @ref
                        ///     demo::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val
                        ///     field.
                        using Val = 
                            std::tuple<
                                comms::option::app::OrigDataView,
                                typename TBase::message::VariantsFields::Props1Members::PropertyMembers::Prop3Members::Val
                            >;
                    };
                    
                };
                
            };
            
            /// @brief Extra options for all the member fields of
            ///     @ref demo::message::VariantsFields::Props2 list.
            struct Props2Members : public TBase::message::VariantsFields::Props2Members
            {
                /// @brief Extra options for all the member fields of
                ///     @ref demo::message::VariantsFields::Props2Members::Property bitfield.
                struct PropertyMembers : public TBase::message::VariantsFields::Props2Members::PropertyMembers
                {
                    /// @brief Extra options for all the member fields of
                    ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3 bundle.
                    struct Prop3Members : public TBase::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members
                    {
                        /// @brief Extra options for @ref
                        ///     demo::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Val
                        ///     field.
                        using Val = 
                            std::tuple<
                                comms::option::app::OrigDataView,
                                typename TBase::message::VariantsFields::Props2Members::PropertyMembers::Prop3Members::Val
                            >;
                    };
                    
                    /// @brief Extra options for all the member fields of
                    ///     @ref demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownProp bundle.
                    struct UnknownPropMembers : public TBase::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers
                    {
                        /// @brief Extra options for @ref
                        ///     demo::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Val
                        ///     field.
                        using Val = 
                            std::tuple<
                                comms::option::app::OrigDataView,
                                typename TBase::message::VariantsFields::Props2Members::PropertyMembers::UnknownPropMembers::Val
                            >;
                    };
                    
                };
                
            };
            
        }; // struct VariantsFields
        
        /// @brief Extra options for
        ///     @ref demo::message::Variants message.
        using Variants = comms::option::app::EmptyOption;
        
    }; // struct message
    
    /// @brief Extra options for frames.
    struct frame : public TBase::frame
    {
        /// @brief Extra options for Layers of
        ///     @ref demo::frame::Frame frame.
        struct FrameLayers : public TBase::frame::FrameLayers
        {
            /// @brief Extra options for @ref
            ///     demo::frame::FrameLayers::Data layer.
            using Data = std::tuple<
                comms::option::app::OrigDataView,
                typename TBase::frame::FrameLayers::Data
            >;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

/// @brief Alias to @ref DataViewDefaultOptionsT with default template parameter.
using DataViewDefaultOptions = DataViewDefaultOptionsT<>;

} // namespace options

} // namespace demo


