#include "AvailableMessagesListModel.h"

#include <algorithm>
#include <map>
#include <cassert>
#include <iostream>

#include "AppMgr.h"

namespace cc_tools
{

namespace cc_view
{

namespace 
{

QVariant getNameFromInfo(const cc_tools::cc_plugin::Protocol::MessageInfo& info)
{
    return info.m_name;
}

QVariant getIdFromInfo(const cc_tools::cc_plugin::Protocol::MessageInfo& info)
{
    return info.m_id;
}

QVariant getIdxFromInfo(const cc_tools::cc_plugin::Protocol::MessageInfo& info)
{
    return info.m_idx;
}


} // namespace 
    

AvailableMessagesListModel::AvailableMessagesListModel()
{
    auto& msgMgr = AppMgr::instance().msgMgr();
    auto protocolPtr = msgMgr.getProtocol();
    if (!protocolPtr) {
        assert(!"Should not happen");
        return;
    }

    m_allInfos = protocolPtr->getSupportedMessages();

    // Modify name to contain full information (including the id), improves the search
    for (auto& info : m_allInfos) {
        info.m_name = protocolPtr->getMessageInfoString(info);
    }

    searchChanged(m_Search);

    connect(
        this, &AvailableMessagesListModel::sigSearchChanged,
        this, &AvailableMessagesListModel::searchChanged);
}

AvailableMessagesListModel::~AvailableMessagesListModel() = default;

QString AvailableMessagesListModel::getNameOf(int idx) const
{
    if (m_availableInfos.size() <= static_cast<unsigned>(idx)) {
        assert(!"Should not happen");
        return QString();
    }

    return m_availableInfos[idx].m_name;
}

long long AvailableMessagesListModel::getIdOf(int idx) const
{
    if (m_availableInfos.size() <= static_cast<unsigned>(idx)) {
        assert(!"Should not happen");
        return -1;
    }

    return m_availableInfos[idx].m_id;
}

int AvailableMessagesListModel::getIdxOf(int idx) const
{
    if (m_availableInfos.size() <= static_cast<unsigned>(idx)) {
        assert(!"Should not happen");
        return -1;
    }

    return m_availableInfos[idx].m_idx;
}

int AvailableMessagesListModel::getCount() const
{
    return static_cast<int>(m_availableInfos.size());
}

int AvailableMessagesListModel::rowCount(const QModelIndex &parent) const
{
    static_cast<void>(parent);
    return static_cast<int>(m_availableInfos.size());
}

QVariant AvailableMessagesListModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    do {
        auto idx = index.row();
        if (m_availableInfos.size() <= static_cast<unsigned>(idx)) {
            break;
        }

        using GetFunc = QVariant (*)(const MessageInfo&);
        static const std::map<int, GetFunc> Map = {
            std::make_pair(Role_Name, &getNameFromInfo),
            std::make_pair(Role_Id, &getIdFromInfo),
            std::make_pair(Role_Idx, &getIdxFromInfo),
        };

        auto iter = Map.find(role);
        if (iter == Map.end()) {
            std::cerr << "ERROR: AvailableMessagesListModel: Bad request of the role: " << role << std::endl;
            break;
        }

        auto& info = m_availableInfos[idx];
        auto func = iter->second;
        result = func(info);
    } while (false);
    return result;
}

QHash<int, QByteArray> AvailableMessagesListModel::roleNames() const
{
    auto names = Base::roleNames();
    names[Role_Name] = "name";
    names[Role_Id] = "id";
    names[Role_Idx] = "idx";
    return names;
}

void AvailableMessagesListModel::searchChanged(const QString& value)
{
    static_cast<void>(value);
    beginResetModel();

    m_availableInfos.clear();
    m_availableInfos.reserve(m_allInfos.size());
    std::copy_if(
        m_allInfos.begin(), m_allInfos.end(), std::back_inserter(m_availableInfos),
        [&value](auto& elem)
        {
            return value.isEmpty() || (elem.m_name.contains(value));
        }
    );

    endResetModel();
    emit sigCountChanged(static_cast<int>(m_availableInfos.size()));
}

} // namespace cc_view

} // namespace cc_tools
