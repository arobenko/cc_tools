#include "QmlEnumField.h"

#include <iostream>

namespace cc_tools
{

namespace cc_view
{

QmlEnumField::QmlEnumField(QObject* p) :
    Base(p)
{
    connect(
        this, &QmlEnumField::sigMsgChanged,
        this, &QmlEnumField::msgChanged);

    connect(
        this, &QmlEnumField::sigFieldChanged,
        this, &QmlEnumField::fieldChanged);  

    connect(
        this, &QmlEnumField::sigSerStrChanged,
        this, &QmlEnumField::serStrChanged);               
}

QmlEnumField::~QmlEnumField() = default;

void QmlEnumField::msgChanged(MessagePtr value)
{
    if (value) {
        connect(
            value.get(), &Message::sigMessageUpdated,
            this, &QmlEnumField::updateStatus);
    }

    if ((!value) || (!m_Field)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlEnumField::fieldChanged(FieldPtr value)
{
    if ((!m_Msg) || (!value)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlEnumField::serStrChanged(const QString& value)
{
    if (m_internalUpdate) {
        return;
    }

    if (!m_EnumField) {
        return;
    }

    m_EnumField->setSerialized(value);
}

void QmlEnumField::updateStatus()
{
    assert(m_Field);
    assert(m_Field->type() == Field::Type_Enum);
    setEnumField(std::static_pointer_cast<EnumField>(m_Field));
    setName(m_EnumField->name());

    // Writable status
    setSerStrInternal(m_EnumField->getSerialized());
}

void QmlEnumField::resetStatus()
{
    setEnumField(EnumFieldPtr());
    setName(QString());
    setSerStrInternal(QString());
}

void QmlEnumField::setSerStrInternal(const QString& value)
{
    m_internalUpdate = true;
    setSerStr(value);
    m_internalUpdate = false;
}

    
} // namespace cc_view

} // namespace cc_tools