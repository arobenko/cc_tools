#pragma once

#include <vector>
#include <map>

#include <QtCore/QObject>

#include "cc_tools/cc_plugin/Message.h"

#include "common_defs.h"

namespace cc_tools
{

namespace cc_view
{

class QmlMessage : public QObject
{
    Q_OBJECT
    using Base = QObject;

    Q_PROPERTY(MessagePtr msg READ getMsg WRITE setMsg NOTIFY sigMsgChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY sigNameChanged)

public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;

    explicit QmlMessage(QObject* p = nullptr);
    ~QmlMessage();

    MessagePtr getMsg();
    void setMsg(MessagePtr value);

    CC_MEMBER(QString, Name)

signals:
    void sigMsgChanged(MessagePtr value);
    void sigNameChanged(const QString& value);

private:
    void reset();
    
    MessagePtr m_msg;
};

} // namespace cc_view

} // namespace cc_tools
