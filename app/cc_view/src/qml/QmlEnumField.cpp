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
        this, &QmlEnumField::sigFieldChanged,
        this, &QmlEnumField::fieldChanged);  
}

QmlEnumField::~QmlEnumField() = default;

void QmlEnumField::fieldChanged(FieldPtr value)
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

void QmlEnumField::updateStatus()
{
    assert(m_Field);
    assert(m_Field->type() == Field::Type_Enum);
    setEnumField(std::static_pointer_cast<EnumField>(m_Field));
}

void QmlEnumField::resetStatus()
{
    setEnumField(EnumFieldPtr());
}

    
} // namespace cc_view

} // namespace cc_tools