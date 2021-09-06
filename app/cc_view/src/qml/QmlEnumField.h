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

class QmlEnumField : public QObject
{
    Q_OBJECT
    using Base = QObject;

    // Config
    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)
    Q_PROPERTY(FieldPtr field READ getField WRITE setField NOTIFY sigFieldChanged)

    // Status
    Q_PROPERTY(EnumFieldPtr enumField READ getEnumField NOTIFY sigEnumFieldChanged)
    Q_PROPERTY(QString name READ getName NOTIFY sigNameChanged)

public:
    using Message = cc_tools::cc_plugin::Message;
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;
    using Field = cc_tools::cc_plugin::Field;
    using FieldPtr = cc_tools::cc_plugin::FieldPtr;
    using EnumField = cc_tools::cc_plugin::EnumField;
    using EnumFieldPtr = cc_tools::cc_plugin::EnumFieldPtr;

    explicit QmlEnumField(QObject* p = nullptr);
    ~QmlEnumField();

    // Config members
    CC_MEMBER(MessagePtr, Msg)
    CC_MEMBER(FieldPtr, Field)

    // Status members
    CC_MEMBER(EnumFieldPtr, EnumField)
    CC_MEMBER(QString, Name)

signals:
    void sigMsgChanged(MessagePtr value);
    void sigFieldChanged(FieldPtr value);
    void sigEnumFieldChanged(FieldPtr value);
    void sigNameChanged(const QString& value);

private slots:
    void msgUpdated(MessagePtr value);    
    void fieldUpdated(FieldPtr value);    
    void updateStatus();

private:
    void resetStatus();
};

} // namespace cc_view

} // namespace cc_tools
