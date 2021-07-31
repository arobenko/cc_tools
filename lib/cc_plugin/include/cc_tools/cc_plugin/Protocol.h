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

#include <cstdint>
#include <cstddef>
#include <vector>
#include <functional>
#include <list>

#include <QtCore/QString>

#include "cc_tools/cc_plugin/Api.h"
#include "cc_tools/cc_plugin/DataInfo.h"
#include "cc_tools/cc_plugin/PluginObject.h"
#include "cc_tools/cc_plugin/Message.h"

namespace cc_tools
{

namespace cc_plugin
{

/// @brief Main polymorphic interface class for protocols.
/// @details It is used to create selected protocol messages.
/// @headerfile cc_tools/cc_plugin/Protocol.h
class CC_PLUGIN_API Protocol : public PluginObject
{
    using Base = PluginObject;
public:
    /// @brief List of messages
    using MessagesList = std::list<MessagePtr>;

    /// @brief Constructor
    explicit Protocol(QObject* p = nullptr);

    /// @brief Destructor
    virtual ~Protocol() noexcept;

    /// @brief Read the received data input.
    /// @details Invokes virtual readImpl().
    /// @param[in] dataInfo Received data information
    /// @param[in] final Final input indication, if @b true no more data is expected
    /// @return List of created messages
    MessagesList read(const DataInfo& dataInfo, bool final = false);    

    /// @brief Serialse message.
    /// @details Invokes writeImpl().
    /// @param[in] msg Reference to message object, passed by non-const reference
    ///     to allow update of the message properties.
    /// @return Serialised data.
    DataInfoPtr write(Message& msg);    

protected:
    virtual Type getTypeImpl() const override final;

    /// @brief Polymorphic read functionality.
    /// @details Invoked by read().
    virtual MessagesList readImpl(const DataInfo& dataInfo, bool final) = 0;    

    /// @brief Polymorphic write functionality.
    /// @details invoked by write().
    virtual DataInfoPtr writeImpl(Message& msg) = 0;    
    
private:
};

/// @brief Pointer to @ref Protocol object.
using ProtocolPtr = std::shared_ptr<Protocol>;

} // namespace cc_plugin

}  // namespace cc_tools

