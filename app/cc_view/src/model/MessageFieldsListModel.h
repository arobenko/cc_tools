#pragma once

#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QAbstractListModel>

#include "cc_tools/cc_plugin/Message.h"

#include "common_defs.h"

namespace cc_tools
{

namespace cc_view
{

class MessageFieldsListModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)

    using Base = QAbstractListModel;
public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;

    MessageFieldsListModel();
    virtual ~MessageFieldsListModel();

    CC_MEMBER(MessagePtr, Msg)

signals:
    void sigMsgChanged(MessagePtr value);

protected:
    virtual int rowCount(const QModelIndex &parent) const override final;    
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

private slots:
    void msgUpdated(MessagePtr value);    

private:
    enum Role {
        Role_FieldQml = Qt::UserRole,
        NumOfRoles
    };

    QVariant getFieldQmlOf(int idx) const;
};

} // namespace cc_view


} // namespace cc_tools
