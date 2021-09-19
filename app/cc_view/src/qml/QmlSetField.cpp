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
        this, &QmlSetField::sigFieldChanged,
        this, &QmlSetField::fieldChanged);  

    connect(
        this, &QmlSetField::sigSerStrChanged,
        this, &QmlSetField::serStrChanged);               
}

QmlSetField::~QmlSetField() = default;

void QmlSetField::fieldChanged(FieldPtr value)
{
    if (!value) {
        resetStatus();
        return;
    }

    connect(
        value.get(), &Field::sigFieldUpdated,
        this,
        [this]()
        {
            auto* sndr = sender();
            assert(sndr != nullptr);
            if (sndr != m_Field.get()) {
                disconnect(sndr, nullptr, this, nullptr);
                return;
            }

            updateStatus();
        });

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