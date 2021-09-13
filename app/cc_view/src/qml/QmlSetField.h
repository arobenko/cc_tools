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

class QmlSetField : public QObject
{
    Q_OBJECT
    using Base = QObject;

    // Config
    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)
    Q_PROPERTY(FieldPtr field READ getField WRITE setField NOTIFY sigFieldChanged)

    // Status
    Q_PROPERTY(SetFieldPtr setField READ getSetField NOTIFY sigSetFieldChanged)
    Q_PROPERTY(QString name READ getName NOTIFY sigNameChanged)

    // Writable Status
    Q_PROPERTY(QString serStr READ getSerStr WRITE setSerStr NOTIFY sigSerStrChanged)

public:
    using Message = cc_tools::cc_plugin::Message;
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;
    using Field = cc_tools::cc_plugin::Field;
    using FieldPtr = cc_tools::cc_plugin::FieldPtr;
    using SetField = cc_tools::cc_plugin::SetField;
    using SetFieldPtr = cc_tools::cc_plugin::SetFieldPtr;

    explicit QmlSetField(QObject* p = nullptr);
    ~QmlSetField();

    // Config members
    CC_MEMBER(MessagePtr, Msg)
    CC_MEMBER(FieldPtr, Field)

    // Status members
    CC_MEMBER(SetFieldPtr, SetField)
    CC_MEMBER(QString, Name)

    // Writable Status members
    CC_MEMBER(QString, SerStr)

signals:
    void sigMsgChanged(MessagePtr value);
    void sigFieldChanged(FieldPtr value);
    void sigSetFieldChanged(FieldPtr value);
    void sigNameChanged(const QString& value);
    void sigSerStrChanged(const QString& value);

private slots:
    void msgChanged(MessagePtr value);    
    void fieldChanged(FieldPtr value);  
    void serStrChanged(const QString& value);  
    void updateStatus();

private:
    void resetStatus();
    void setSerStrInternal(const QString& value);

    bool m_internalUpdate = false;
};

} // namespace cc_view

} // namespace cc_tools
