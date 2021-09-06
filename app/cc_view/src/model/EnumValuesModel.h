#pragma once

#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QAbstractListModel>

#include "cc_tools/cc_plugin/Field.h"

#include "common_defs.h"

namespace cc_tools
{

namespace cc_view
{

class EnumValuesModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(EnumFieldPtr enumField READ getEnumField WRITE setEnumField NOTIFY sigEnumFieldChanged)

    using Base = QAbstractListModel;
public:
    using EnumFieldPtr = cc_tools::cc_plugin::EnumFieldPtr;

    EnumValuesModel();
    virtual ~EnumValuesModel();

    CC_MEMBER(EnumFieldPtr, EnumField)

signals:
    void sigEnumFieldChanged(EnumFieldPtr value);

protected:
    virtual int rowCount(const QModelIndex &parent) const override final;    
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

private slots:
    void enumFieldUpdated(EnumFieldPtr value);    

private:
    enum Role {
        Role_Name = Qt::UserRole,
        Role_Value,
        NumOfRoles
    };

    QVariant getNameOf(int idx) const;
    QVariant getValueOf(int idx) const;
};

} // namespace cc_view


} // namespace cc_tools
