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

void QmlSetField::updateStatus()
{
    assert(m_Field);
    assert(m_Field->type() == Field::Type_Set);
    setSetField(std::static_pointer_cast<SetField>(m_Field));
}

void QmlSetField::resetStatus()
{
    setSetField(SetFieldPtr());
}
    
} // namespace cc_view

} // namespace cc_tools