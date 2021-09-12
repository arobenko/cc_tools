#include "EnumValuesModel.h"

#include <cassert>
#include <iostream>
#include <map>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

namespace 
{

const QString& UnknownValueStr("???");

template <typename T, typename TMap>
T getUnknownValue(T minVal, T maxVal, const TMap& valuesMap, bool& updated)
{
    updated = true;
    auto& lastValue = valuesMap.back();    

    // Return the value of one past last if possible
    if (static_cast<T>(lastValue.first) < maxVal) {
        return static_cast<T>(lastValue.first + 1);
    }

    // Find a hole in the values range
    for (auto idx = 0U; idx < (valuesMap.size() - 1U); ++idx) {
        auto val = static_cast<T>(valuesMap[idx].first);
        auto nextVal = static_cast<T>(valuesMap[idx + 1].first);

        auto selectedVal = static_cast<T>(val + 1);
        if (selectedVal < nextVal) {
            return selectedVal;
        }
    }

    // The values are packed at the end of possible range,
    // check if there one below the first is possible
    auto& firstValue = valuesMap.front();
    auto firstVal = static_cast<T>(firstValue.first);
    if (minVal < firstVal) {
        return static_cast<T>(firstVal - 1);
    }

    // The whole range of values is full, no unknown value is possible
    updated = false;
    return static_cast<T>(0);
}

} // namespace 
    

EnumValuesModel::EnumValuesModel()
{
    connect(
        this, &EnumValuesModel::sigEnumFieldChanged,
        this, &EnumValuesModel::enumFieldChanged);

    connect(
        this, &EnumValuesModel::sigCurrentIndexChanged,
        this, &EnumValuesModel::currentIndexChanged);        
}

EnumValuesModel::~EnumValuesModel() = default;

int EnumValuesModel::rowCount(const QModelIndex &parent) const
{
    static_cast<void>(parent);
    if (!m_EnumField) {
        return 0;
    }

    auto& valuesMap = m_EnumField->getValueNamesMap();
    auto result = static_cast<int>(valuesMap.size()); 
    if (0 <= m_unknownValueIdx) {
        ++result;
    }
    return result;
}

QVariant EnumValuesModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    do {
        auto idx = index.row();
        
        assert(m_EnumField);
        // auto& valuesMap = m_EnumField->getValueNamesMap();
        // if (valuesMap.size() <= static_cast<unsigned>(idx)) {
        //     break;
        // }

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

void EnumValuesModel::enumFieldChanged(EnumFieldPtr value)
{
    static_cast<void>(value);
    beginResetModel();
    m_unknownValueIdx = -1;
    m_unknownValue = 0;    
    if (value) {
        updateConfig();

        connect(
            value.get(), &cc_tools::cc_plugin::Field::sigFieldUpdated,
            this, &EnumValuesModel::fieldUpdated);

        auto& valuesMap = m_EnumField->getValueNamesMap();
        assert(!valuesMap.empty());
        auto maxAllowedValue = m_EnumField->maxAllowedValue();
        auto minAllowedValue = m_EnumField->minAllowedValue();
        bool unsignedValue = (minAllowedValue == 0);
        bool hasUnknownValue = false;
        if (unsignedValue) {
            using UnsignedValueType = typename std::make_unsigned<ValueType>::type;
            m_unknownValue = 
                static_cast<ValueType>(
                    getUnknownValue(
                        static_cast<UnsignedValueType>(minAllowedValue),
                        static_cast<UnsignedValueType>(maxAllowedValue),
                        valuesMap,
                        hasUnknownValue));
        }
        else {
            m_unknownValue = getUnknownValue(minAllowedValue, maxAllowedValue, valuesMap, hasUnknownValue);
        }

        if (hasUnknownValue) {
            m_unknownValueIdx = static_cast<int>(valuesMap.size());
        }

    }
    endResetModel();
}

void EnumValuesModel::currentIndexChanged(int value)
{
    if (m_internalUpdate) {
        return;
    }

    if (m_EnumField && (0 <= value)) {
        m_EnumField->setValue(getValueOfInternal(value));
    }
}

void EnumValuesModel::fieldUpdated()
{
    auto* sndr = sender();
    assert(sndr != nullptr);
    if (sndr != m_EnumField.get()) {
        disconnect(sndr, nullptr, this, nullptr);
        return;
    }

    updateConfig();
}

QVariant EnumValuesModel::getNameOf(int idx) const
{
    assert(m_EnumField);
    auto& valuesMap = m_EnumField->getValueNamesMap();
    if(static_cast<unsigned>(idx) < valuesMap.size()) {
        return valuesMap[idx].second;
    }
    
    assert(0 <= m_unknownValueIdx);
    return UnknownValueStr;
}

QVariant EnumValuesModel::getValueOf(int idx) const
{
    return getValueOfInternal(idx);
}

EnumValuesModel::ValueType EnumValuesModel::getValueOfInternal(int idx) const
{
    assert(m_EnumField);
    auto& valuesMap = m_EnumField->getValueNamesMap();
    if (static_cast<unsigned>(idx) < valuesMap.size()) {
        return valuesMap[idx].first;
    }
    
    return m_unknownValue;
}

void EnumValuesModel::updateConfig()
{
    setCurrentIndex(calcCurrentIndex());
}

int EnumValuesModel::calcCurrentIndex() const
{
    if (!m_EnumField) {
        return -1;
    }

    auto currValue = m_EnumField->getValue();
    auto& valuesMap = m_EnumField->getValueNamesMap();
    auto iter = 
        std::lower_bound(
            valuesMap.begin(), valuesMap.end(), currValue,
            [](auto elem, ValueType val)
            {
                return elem.first < val;
            });

    if ((iter == valuesMap.end()) || (iter->first != currValue)) {
        return static_cast<int>(valuesMap.size());
    }

    return static_cast<int>(std::distance(valuesMap.begin(), iter));
}

void EnumValuesModel::setCurrentIndexInternal(int value)
{
    m_internalUpdate = true;
    setCurrentIndex(value);
    m_internalUpdate = false;
}

} // namespace cc_view

} // namespace cc_tools
