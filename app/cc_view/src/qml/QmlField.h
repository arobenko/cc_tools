#pragma once

#include <vector>
#include <map>

#include <QtCore/QObject>

#include "cc_tools/cc_plugin/Message.h"
#include "cc_tools/cc_plugin/Field.h"

#include "common_defs.h"

namespace cc_tools
{

namespace cc_view
{

class QmlField : public QObject
{
    Q_OBJECT
    using Base = QObject;

    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)
    Q_PROPERTY(int idx READ getIdx WRITE setIdx NOTIFY sigIdxChanged)

    Q_PROPERTY(FieldPtr field READ getField NOTIFY sigFieldChanged)
    // Q_PROPERTY(QString name READ getName NOTIFY sigNameChanged)

public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;
    using FieldPtr = cc_tools::cc_plugin::FieldPtr;

    explicit QmlField(QObject* p = nullptr);
    ~QmlField();

    // Config members
    CC_MEMBER(MessagePtr, Msg)
    CC_MEMBER(int, Idx, =-1)

    // Status members
    CC_MEMBER(FieldPtr, Field)
    // CC_MEMBER(QString, Name)

signals:
    void sigMsgChanged(MessagePtr value);
    void sigIdxChanged(int value);
    void sigFieldChanged(FieldPtr value);
    // void sigNameChanged(const QString& value);

private slots:
    void msgUpdated(MessagePtr value);    
    void idxUpdated(int value);    

private:
    void resetStatus();
    void updateStatus();
};

} // namespace cc_view

} // namespace cc_tools
