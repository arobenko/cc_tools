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

void QmlField::resetStatus()
{
    setField(FieldPtr());
    //setName(QString());
}

void QmlField::updateStatus()
{
    assert(m_Msg);

    auto& fields = m_Msg->fields();
    assert(static_cast<unsigned>(m_Idx) < fields.size());
    setField(fields[m_Idx]);
    // setName(m_Field->name());
}
    
} // namespace cc_view

} // namespace cc_tools