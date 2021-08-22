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
#include <QtCore/QString>

#include "cc_tools/cc_plugin/Api.h"

namespace cc_tools
{

namespace cc_plugin
{

class CC_PLUGIN_API Field : public QObject
{
    using Base = QObject;
public:

    enum Type : unsigned
    {
        Type_Int,
        Type_Enum,
        Type_Set,
        Type_Bitfield,
        Type_Bundle,
        Type_String,
        Type_Data,
        Type_List,
        Type_Float,
        Type_Optional,
        Type_Variant,
        Type_NumOfValues
    };

    /// @brief Constructor
    explicit Field(QObject* p = nullptr);

    /// @brief Destructor
    virtual ~Field() noexcept;

    const QString& name() const;

    Type type() const;

protected:
    virtual const QString& nameImpl() const = 0;    
    virtual Type typeImpl() const = 0;
};

/// @brief Pointer to @ref Field object.
using FieldPtr = std::shared_ptr<Field>;

} // namespace cc_plugin

}  // namespace cc_tools

Q_DECLARE_METATYPE(cc_tools::cc_plugin::FieldPtr);
