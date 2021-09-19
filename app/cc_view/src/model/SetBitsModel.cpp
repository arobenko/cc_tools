#include "SetBitsModel.h"

#include <cassert>
#include <iostream>
#include <map>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

SetBitsModel::SetBitsModel()
{
    connect(
        this, &SetBitsModel::sigSetFieldChanged,
        this, &SetBitsModel::setFieldChanged);
}

SetBitsModel::~SetBitsModel() = default;

int SetBitsModel::rowCount(const QModelIndex &parent) const
{
    static_cast<void>(parent);
    if (!m_SetField) {
        return 0;
    }

    auto& bitNamesMap = m_SetField->getBitNamesMap();
    return static_cast<int>(bitNamesMap.size()); 
}

QVariant SetBitsModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    do {
        auto idx = index.row();
        
        assert(m_SetField);
        auto& bitNamesMap = m_SetField->getBitNamesMap();
        if (bitNamesMap.size() <= static_cast<unsigned>(idx)) {
            break;
        }

        using GetFunc = QVariant (SetBitsModel::*)(int) const;
        static const std::map<int, GetFunc> Map = {
            std::make_pair(Role_Name, &SetBitsModel::getNameOf),
            std::make_pair(Role_State, &SetBitsModel::getStateOf),
        };

        auto iter = Map.find(role);
        if (iter == Map.end()) {
            std::cerr << "ERROR: SetBitsModel: Bad request of the role: " << role << std::endl;
            break;
        }

        auto func = iter->second;
        result = (this->*func)(idx);
    } while (false);
    return result;
}

bool SetBitsModel::setData(const QModelIndex &index, const QVariant& value, int role)
{
    if (!value.isValid()) {
        return false;
    }

    auto idx = index.row();
    
    assert(m_SetField);
    auto& bitNamesMap = m_SetField->getBitNamesMap();
    if (bitNamesMap.size() <= static_cast<unsigned>(idx)) {
        return false;
    }

    using SetFunc = void (SetBitsModel::*)(int idx, const QVariant&);
    static const std::map<int, SetFunc> Map = {
        std::make_pair(Role_State, &SetBitsModel::setStateOf),
    };

    auto iter = Map.find(role);
    if (iter == Map.end()) {
        std::cerr << "ERROR: SetBitsModel: Bad request of the role: " << role << std::endl;
        return false;
    }

    auto func = iter->second;
    (this->*func)(idx, value);
    return false; // The field update signal should be emitted, resulting in model reset
}

QHash<int, QByteArray> SetBitsModel::roleNames() const
{
    auto names = Base::roleNames();
    names[Role_Name] = "dataName";
    names[Role_State] = "dataState";
    return names;
}

void SetBitsModel::setFieldChanged(SetFieldPtr value)
{
    static_cast<void>(value);
    beginResetModel();
    if (value) {
        connect(
            value.get(), &cc_tools::cc_plugin::Field::sigFieldUpdated,
            this, &SetBitsModel::fieldUpdated);
    }
    endResetModel();
}

void SetBitsModel::fieldUpdated()
{
    auto* sndr = sender();
    assert(sndr != nullptr);
    if (sndr != m_SetField.get()) {
        disconnect(sndr, nullptr, this, nullptr);
        return;
    }

    beginResetModel();
    endResetModel();
}

QVariant SetBitsModel::getNameOf(int idx) const
{
    assert(m_SetField);
    auto& bitNamesMap = m_SetField->getBitNamesMap();
    if(static_cast<unsigned>(idx) < bitNamesMap.size()) {
        return bitNamesMap[idx].second;
    }

    assert(!"Should not happen");   
    return QString();
}

QVariant SetBitsModel::getStateOf(int idx) const
{
    auto& bitNamesMap = m_SetField->getBitNamesMap();
    assert (static_cast<unsigned>(idx) < bitNamesMap.size());

    return m_SetField->getBitValue(bitNamesMap[idx].first);
}

void SetBitsModel::setStateOf(int idx, const QVariant& value)
{
    assert(value.isValid() && value.canConvert<bool>());
    auto& bitNamesMap = m_SetField->getBitNamesMap();
    assert (static_cast<unsigned>(idx) < bitNamesMap.size());    
    m_SetField->setBitValue(bitNamesMap[idx].first, value.value<bool>());
}

} // namespace cc_view

} // namespace cc_tools
