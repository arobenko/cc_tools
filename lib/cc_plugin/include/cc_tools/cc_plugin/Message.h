//
// Copyright 2021 (C). Alex Robenko. All rights reserved.
//

// This file is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#pragma once

#include <memory>

#include <QtCore/QObject>

#include "cc_tools/cc_plugin/Api.h"

namespace cc_tools
{

namespace cc_plugin
{

/// @brief Main polymorphic interface message objects.
/// @details It is used to provide a common abstraction to message object.
/// @headerfile cc_tools/cc_plugin/Message.h
class CC_PLUGIN_API Message : public QObject
{
    using Base = QObject;
public:

    /// @brief Type of the message
    enum class Type : unsigned
    {
        Invalid, ///< Invalid type
        Received, ///< Message has been received
        Sent, ///< Message has been sent
        NumOfValues ///< Number of available values
    };

    enum class PropType : unsigned
    {
        Type,      // Type above
        SeqNum,    // unsigned long long
        Timestamp, // unsigned long long
        NumOfValues
    };

    /// @brief Constructor
    explicit Message(QObject* p = nullptr);

    /// @brief Destructor
    virtual ~Message() noexcept;

    static const char* propName(PropType value);
};

/// @brief Pointer to @ref Message object.
using MessagePtr = std::shared_ptr<Message>;

} // namespace cc_plugin

}  // namespace cc_tools

