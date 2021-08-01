
/// @file
/// @brief Contains common template parameters independent functionality of
///    fields used in definition of @ref demo::frame::Frame frame.

#pragma once

#include <cstdint>

namespace demo
{

namespace frame
{

/// @brief Common types and functions of fields using in definition of
///     @ref demo::frame::Frame frame.
/// @see demo::frame::FrameLayers
struct FrameLayersCommon
{
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo::frame::FrameLayers::SyncMembers struct.
    struct SyncMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::frame::FrameLayers::SyncMembers::Sync field.
        struct SyncCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::frame::FrameLayers::SyncMembers::Sync field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo::frame::FrameLayers::SyncMembers::Sync field.
            static const char* name()
            {
                return "Sync";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo::frame::FrameLayers::ChecksumMembers struct.
    struct ChecksumMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::frame::FrameLayers::ChecksumMembers::Checksum field.
        struct ChecksumCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::frame::FrameLayers::ChecksumMembers::Checksum field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo::frame::FrameLayers::ChecksumMembers::Checksum field.
            static const char* name()
            {
                return "Checksum";
            }
            
        };
        
    };
    
    /// @brief Scope for all the common definitions of the fields defined in
    ///     @ref demo::frame::FrameLayers::SizeMembers struct.
    struct SizeMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref demo::frame::FrameLayers::SizeMembers::Size field.
        struct SizeCommon
        {
            /// @brief Re-definition of the value type used by
            ///     demo::frame::FrameLayers::SizeMembers::Size field.
            using ValueType = std::uint16_t;
        
            /// @brief Name of the @ref demo::frame::FrameLayers::SizeMembers::Size field.
            static const char* name()
            {
                return "Size";
            }
            
        };
        
    };
    
};
} // namespace frame

} // namespace demo


