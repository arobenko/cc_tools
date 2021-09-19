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

class SetBitsModel : public QAbstractListModel
{
    Q_OBJECT

    // Config
    Q_PROPERTY(SetFieldPtr setField READ getSetField WRITE setSetField NOTIFY sigSetFieldChanged)

    using Base = QAbstractListModel;
public:
    using SetField = cc_tools::cc_plugin::SetField;
    using SetFieldPtr = cc_tools::cc_plugin::SetFieldPtr;

    SetBitsModel();
    ~SetBitsModel();

    // Config
    CC_MEMBER(SetFieldPtr, SetField)

signals:
    void sigSetFieldChanged(SetFieldPtr value);

protected:
    virtual int rowCount(const QModelIndex &parent) const override final;    
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual bool setData(const QModelIndex &index, const QVariant& value, int role) override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

private slots:
    void setFieldChanged(SetFieldPtr value);
    void fieldUpdated();    

private:
    enum Role {
        Role_Name = Qt::UserRole,
        Role_State,
        NumOfRoles
    };

    QVariant getNameOf(int idx) const;
    QVariant getStateOf(int idx) const;

    void setStateOf(int idx, const QVariant& value);
};

} // namespace cc_view


} // namespace cc_tools
