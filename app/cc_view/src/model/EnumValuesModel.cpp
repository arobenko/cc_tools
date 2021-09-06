#include "EnumValuesModel.h"

#include <cassert>
#include <iostream>
#include <map>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

EnumValuesModel::EnumValuesModel()
{
    connect(
        this, &EnumValuesModel::sigEnumFieldChanged,
        this, &EnumValuesModel::enumFieldUpdated);
}

EnumValuesModel::~EnumValuesModel() = default;

int EnumValuesModel::rowCount(const QModelIndex &parent) const
{
    static_cast<void>(parent);
    if (!m_EnumField) {
        return 0;
    }

    auto& valuesMap = m_EnumField->getValueNamesMap();
    return static_cast<int>(valuesMap.size()); 
}

QVariant EnumValuesModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    do {
        auto idx = index.row();
        
        assert(m_EnumField);
        auto& valuesMap = m_EnumField->getValueNamesMap();
        if (valuesMap.size() <= static_cast<unsigned>(idx)) {
            break;
        }

        using GetFunc = QVariant (EnumValuesModel::*)(int) const;
        static const std::map<int, GetFunc> Map = {
            std::make_pair(Role_Name, &EnumValuesModel::getNameOf),
            std::make_pair(Role_Value, &EnumValuesModel::getValueOf),
        };

        auto iter = Map.find(role);
        if (iter == Map.end()) {
            std::cerr << "ERROR: EnumValuesModel: Bad request of the role: " << role << std::endl;
            break;
        }

        auto func = iter->second;
        result = (this->*func)(idx);
    } while (false);
    return result;
}

QHash<int, QByteArray> EnumValuesModel::roleNames() const
{
    auto names = Base::roleNames();
    names[Role_Name] = "dataName";
    names[Role_Value] = "dataValue";
    return names;
}

void EnumValuesModel::enumFieldUpdated(EnumFieldPtr value)
{
    static_cast<void>(value);
    beginResetModel();
    endResetModel();
}

QVariant EnumValuesModel::getNameOf(int idx) const
{
    assert(m_EnumField);
    auto& valuesMap = m_EnumField->getValueNamesMap();
    assert(static_cast<unsigned>(idx) < valuesMap.size());
    return valuesMap[idx].second;
}

QVariant EnumValuesModel::getValueOf(int idx) const
{
    assert(m_EnumField);
    auto& valuesMap = m_EnumField->getValueNamesMap();
    assert(static_cast<unsigned>(idx) < valuesMap.size());
    return valuesMap[idx].first;
}

} // namespace cc_view

} // namespace cc_tools
