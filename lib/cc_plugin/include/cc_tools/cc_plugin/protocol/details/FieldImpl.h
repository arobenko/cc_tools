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

#include "cc_tools/cc_plugin/Field.h"

namespace cc_tools
{

namespace cc_plugin
{

namespace protocol
{

namespace details
{

template <typename TField, typename TBase = cc_tools::cc_plugin::Field>
class FieldImpl : public TBase
{
    using Base = TBase;
public:    
    explicit FieldImpl(TField& field) : 
        m_field(field)
    {
    }
    
    ~FieldImpl() = default;

    TField& field()
    {
        return m_field;
    }

    const TField& field() const
    {
        return m_field;
    }

protected:
    virtual const QString& nameImpl() const override
    {
        static const QString Str(m_field.name());
        return Str;
    }

    virtual QByteArray getSerializedImpl() const override
    {
        QByteArray result;
        result.resize(static_cast<int>(m_field.length()));
        if (!result.isEmpty()) {
            auto writeIter = result.begin();
            auto es = m_field.write(writeIter, result.size());
            assert(es == comms::ErrorStatus::Success);
            static_cast<void>(es);
        }
        return result;
    }

    virtual void setSerializedImpl(const QByteArray& data) override
    {
        auto readIter = data.begin();
        auto es = m_field.read(readIter, data.size());
        static_cast<void>(es);
    }

    virtual void adjustSerializedLengthImpl(QByteArray& data) const override
    {
        static const int MaxCount = 256;
        for (auto count = 0; count < MaxCount; ++count) {
            TField fieldTmp;
            auto readIter = data.begin();
            auto es = fieldTmp.read(readIter, data.size());
            if (es != comms::ErrorStatus::NotEnoughData) {
                return;
            }

            data.resize(data.size() + 1);
        }
    }

    virtual bool validImpl() const
    {
        return m_field.valid();
    }
    
private:
    TField& m_field;
};

} // namespace details

} // namespace protocol

} // namespace cc_plugin

} // namespace cc_tools

