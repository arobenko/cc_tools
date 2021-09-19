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

    // Config
    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)
    Q_PROPERTY(int idx READ getIdx WRITE setIdx NOTIFY sigIdxChanged)

    // Status
    Q_PROPERTY(FieldPtr field READ getField NOTIFY sigFieldChanged)
    Q_PROPERTY(QString name READ getName NOTIFY sigNameChanged)
    Q_PROPERTY(bool valid READ getValid NOTIFY sigValidChanged)

    // Writable Status
    Q_PROPERTY(QString serStr READ getSerStr WRITE setSerStr NOTIFY sigSerStrChanged)    

public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;
    using FieldPtr = cc_tools::cc_plugin::FieldPtr;
    using Field = cc_tools::cc_plugin::Field;

    explicit QmlField(QObject* p = nullptr);
    ~QmlField();

    // Config members
    CC_MEMBER(MessagePtr, Msg)
    CC_MEMBER(int, Idx, =-1)

    // Status members
    CC_MEMBER(FieldPtr, Field)
    CC_MEMBER(QString, Name)
    CC_MEMBER(bool, Valid, =false)

    // Writable Status members
    CC_MEMBER(QString, SerStr)    

signals:
    void sigMsgChanged(MessagePtr value);
    void sigIdxChanged(int value);
    void sigFieldChanged(FieldPtr value);
    void sigNameChanged(const QString& value);
    void sigValidChanged(bool value);
    void sigSerStrChanged(const QString& value);

private slots:
    void msgUpdated(MessagePtr value);    
    void idxUpdated(int value); 
    void serStrChanged(const QString& value);   
    void updateFieldDependentStatus();

private:
    void resetStatus();
    void updateStatus();

    void setFieldInternal(FieldPtr value);
    void setSerStrInternal(const QString& value);

    bool m_internalUpdate = false;
};

} // namespace cc_view

} // namespace cc_tools
