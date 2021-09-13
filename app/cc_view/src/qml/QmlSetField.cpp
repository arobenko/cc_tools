#include "QmlSetField.h"

#include <iostream>

namespace cc_tools
{

namespace cc_view
{

QmlSetField::QmlSetField(QObject* p) :
    Base(p)
{
    connect(
        this, &QmlSetField::sigMsgChanged,
        this, &QmlSetField::msgChanged);

    connect(
        this, &QmlSetField::sigFieldChanged,
        this, &QmlSetField::fieldChanged);  

    connect(
        this, &QmlSetField::sigSerStrChanged,
        this, &QmlSetField::serStrChanged);               
}

QmlSetField::~QmlSetField() = default;

void QmlSetField::msgChanged(MessagePtr value)
{
    if (value) {
        connect(
            value.get(), &Message::sigMessageUpdated,
            this, &QmlSetField::updateStatus);
    }

    if ((!value) || (!m_Field)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlSetField::fieldChanged(FieldPtr value)
{
    if ((!m_Msg) || (!value)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlSetField::serStrChanged(const QString& value)
{
    if (m_internalUpdate) {
        return;
    }

    if (!m_SetField) {
        return;
    }

    m_SetField->setSerialized(value);
}

void QmlSetField::updateStatus()
{
    assert(m_Field);
    assert(m_Field->type() == Field::Type_Set);
    setSetField(std::static_pointer_cast<SetField>(m_Field));
    setName(m_SetField->name());

    // Writable status
    setSerStrInternal(m_SetField->getSerialized());
}

void QmlSetField::resetStatus()
{
    setSetField(SetFieldPtr());
    setName(QString());
    setSerStrInternal(QString());
}

void QmlSetField::setSerStrInternal(const QString& value)
{
    m_internalUpdate = true;
    setSerStr(value);
    m_internalUpdate = false;
}

    
} // namespace cc_view

} // namespace cc_tools