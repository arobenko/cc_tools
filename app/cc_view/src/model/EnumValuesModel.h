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

    // Config
    Q_PROPERTY(EnumFieldPtr enumField READ getEnumField WRITE setEnumField NOTIFY sigEnumFieldChanged)
    Q_PROPERTY(int currentIndex READ getCurrentIndex WRITE setCurrentIndex NOTIFY sigCurrentIndexChanged)

    using Base = QAbstractListModel;
public:
    using EnumField = cc_tools::cc_plugin::EnumField;
    using EnumFieldPtr = cc_tools::cc_plugin::EnumFieldPtr;
    using ValueType = EnumField::ValueType;

    EnumValuesModel();
    ~EnumValuesModel();

    // Config
    CC_MEMBER(EnumFieldPtr, EnumField)
    CC_MEMBER(int, CurrentIndex);

signals:
    void sigEnumFieldChanged(EnumFieldPtr value);
    void sigCurrentIndexChanged(int value);

protected:
    virtual int rowCount(const QModelIndex &parent) const override final;    
    virtual QVariant data(const QModelIndex &index, int role) const override final;
    virtual QHash<int, QByteArray> roleNames() const override final;

private slots:
    void enumFieldChanged(EnumFieldPtr value);
    void currentIndexChanged(int value);
    void fieldUpdated();    

private:
    enum Role {
        Role_Name = Qt::UserRole,
        Role_Value,
        NumOfRoles
    };

    QVariant getNameOf(int idx) const;
    QVariant getValueOf(int idx) const;

    ValueType getValueOfInternal(int idx) const;

    void updateConfig();
    int calcCurrentIndex() const;
    void setCurrentIndexInternal(int value);

    int m_unknownValueIdx = -1;
    ValueType m_unknownValue = 0;
    bool m_internalUpdate = false;
};

} // namespace cc_view


} // namespace cc_tools
