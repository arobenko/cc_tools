#include "MessageFieldsListModel.h"

#include <cassert>
#include <iostream>
#include <map>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

MessageFieldsListModel::MessageFieldsListModel()
{
    connect(
        this, &MessageFieldsListModel::sigMsgChanged,
        this, &MessageFieldsListModel::msgUpdated);
}

MessageFieldsListModel::~MessageFieldsListModel() = default;

int MessageFieldsListModel::rowCount(const QModelIndex &parent) const
{
    static_cast<void>(parent);
    if (!m_Msg) {
        return 0;
    }

    return static_cast<int>(m_Msg->fields().size()); 
}

QVariant MessageFieldsListModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    do {
        auto idx = index.row();
        
        assert(m_Msg);
        auto& fields = m_Msg->fields();
        if (fields.size() <= static_cast<unsigned>(idx)) {
            break;
        }

        using GetFunc = QVariant (MessageFieldsListModel::*)(int) const;
        static const std::map<int, GetFunc> Map = {
            std::make_pair(Role_FieldQml, &MessageFieldsListModel::getFieldQmlOf),
        };

        auto iter = Map.find(role);
        if (iter == Map.end()) {
            std::cerr << "ERROR: MessageFieldsListModel: Bad request of the role: " << role << std::endl;
            break;
        }

        auto func = iter->second;
        result = (this->*func)(idx);
    } while (false);
    return result;
}

QHash<int, QByteArray> MessageFieldsListModel::roleNames() const
{
    auto names = Base::roleNames();
    names[Role_FieldQml] = "dataFieldQml";
    return names;
}

void MessageFieldsListModel::msgUpdated(MessagePtr value)
{
    static_cast<void>(value);
    beginResetModel();
    endResetModel();
}

QVariant MessageFieldsListModel::getFieldQmlOf(int idx) const
{
    assert(m_Msg);
    auto& fields = m_Msg->fields();
    assert(static_cast<unsigned>(idx) < fields.size());
    auto& fieldPtr = fields[idx];
    assert(fieldPtr);
    auto mapIdx = static_cast<unsigned>(fieldPtr->type());
    
    static const QString Map[] = {
        /* Type_Int */ "qrc:/qml/elem/field/CC_ElemFieldInt.qml",
        /* Type_Enum */ "qrc:/qml/elem/field/CC_ElemFieldEnum.qml",
        /* Type_Set */ "qrc:/qml/elem/field/CC_ElemFieldSet.qml",
        /* Type_Bitfield */ "qrc:/qml/elem/field/CC_ElemFieldBitfield.qml",
        /* Type_Bundle */ "qrc:/qml/elem/field/CC_ElemFieldBundle.qml",
        /* Type_String */ "qrc:/qml/elem/field/CC_ElemFieldString.qml",
        /* Type_Data */ "qrc:/qml/elem/field/CC_ElemFieldData.qml",
        /* Type_List */ "qrc:/qml/elem/field/CC_ElemFieldList.qml",
        /* Type_Float */ "qrc:/qml/elem/field/CC_ElemFieldFloat.qml",
        /* Type_Optional */ "qrc:/qml/elem/field/CC_ElemFieldOptional.qml",
        /* Type_Variant */ "qrc:/qml/elem/field/CC_ElemFieldVariant.qml",
    };
    static const std::size_t MapSize = std::extent<decltype(Map)>::value;
    static_assert(MapSize == cc_tools::cc_plugin::Field::Type_NumOfValues, "Invalid map");

    if (MapSize <= mapIdx) {
        assert(!"Should not happen");
        return QString();
    }

    return Map[mapIdx];
}

} // namespace cc_view

} // namespace cc_tools
