#pragma once

#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QAbstractListModel>

#include "cc_tools/cc_plugin/Protocol.h"

#include "common_defs.h"

namespace cc_tools
{

namespace cc_view
{

class AvailableMessagesListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QString search READ getSearch WRITE setSearch NOTIFY sigSearchChanged)
    Q_PROPERTY(int count READ getCount NOTIFY sigCountChanged)

    using Base = QAbstractListModel;
public:
    AvailableMessagesListModel();
    virtual ~AvailableMessagesListModel();

    Q_INVOKABLE QString getNameOf(int idx) const;
    Q_INVOKABLE long long getIdOf(int idx) const;
    Q_INVOKABLE int getIdxOf(int idx) const;

    CC_MEMBER(QString, Search)

    int getCount() const;

signals:
    void sigSearchChanged(const QString& value);
    void sigCountChanged(int value);

protected:
    virtual int rowCount(const QModelIndex &parent) const override final;    
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

private slots:
    void searchChanged(const QString& value);    

private:
    enum Role {
        Role_Name = Qt::UserRole,
        Role_Id,
        Role_Idx,
        NumOfRoles
    };

    using MessageInfo = cc_tools::cc_plugin::Protocol::MessageInfo;
    using MessageInfosList = cc_tools::cc_plugin::Protocol::MessageInfosList;

    MessageInfosList m_availableInfos;
    MessageInfosList m_allInfos;
};

} // namespace cc_view


} // namespace cc_tools
