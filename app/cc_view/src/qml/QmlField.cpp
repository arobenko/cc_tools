#include "QmlField.h"

#include <iostream>

namespace cc_tools
{

namespace cc_view
{

QmlField::QmlField(QObject* p) :
    Base(p)
{
    connect(
        this, &QmlField::sigMsgChanged,
        this, &QmlField::msgUpdated);

    connect(
        this, &QmlField::sigIdxChanged,
        this, &QmlField::idxUpdated);   

    connect(
        this, &QmlField::sigSerStrChanged,
        this, &QmlField::serStrChanged);                  
}

QmlField::~QmlField() = default;

void QmlField::msgUpdated(MessagePtr value)
{
    if ((!value) || (m_Idx < 0)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlField::idxUpdated(int value)
{
    if ((!m_Msg) || (value < 0)) {
        resetStatus();
        return;
    }

    updateStatus();
}

void QmlField::serStrChanged(const QString& value)
{
    if (m_internalUpdate) {
        return;
    }

    if (!m_Field) {
        return;
    }

    m_Field->setSerialized(value);
}

void QmlField::updateFieldDependentStatus()
{
    assert(m_Field);
    setName(m_Field->name());
    setValid(m_Field->valid());
    setSerStrInternal(m_Field->getSerialized());
}

void QmlField::resetStatus()
{
    setFieldInternal(FieldPtr());
    setName(QString());
    setValid(false);
    setSerStrInternal(QString());
}

void QmlField::updateStatus()
{
    assert(m_Msg);

    auto& fields = m_Msg->fields();
    assert(static_cast<unsigned>(m_Idx) < fields.size());
    setFieldInternal(fields[m_Idx]);
    updateFieldDependentStatus();
}

void QmlField::setFieldInternal(FieldPtr value)
{
    if (m_Field) {
        disconnect(m_Field.get(), nullptr, this, nullptr);
    }

    if (!value) {
        return;
    }

    connect(
        value.get(), &Field::sigFieldUpdated,
        this, &QmlField::updateFieldDependentStatus);

    setField(std::move(value));
}

void QmlField::setSerStrInternal(const QString& value)
{
    m_internalUpdate = true;
    setSerStr(value);
    m_internalUpdate = false;
}
    
} // namespace cc_view

} // namespace cc_tools