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
        this, &QmlEnumField::msgUpdated);

    connect(
        this, &QmlEnumField::sigFieldChanged,
        this, &QmlEnumField::fieldUpdated);        
}

QmlEnumField::~QmlEnumField() = default;

void QmlEnumField::msgUpdated(MessagePtr value)
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

void QmlEnumField::fieldUpdated(FieldPtr value)
{
    if ((!m_Msg) || (!value)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlEnumField::updateStatus()
{
    assert(m_Field);
    assert(m_Field->type() == Field::Type_Enum);
    setEnumField(std::static_pointer_cast<EnumField>(m_Field));
    setName(m_EnumField->name());
}

void QmlEnumField::resetStatus()
{
    setEnumField(EnumFieldPtr());
    setName(QString());
}

    
} // namespace cc_view

} // namespace cc_tools