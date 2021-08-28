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
    Q_PROPERTY(QString infoString READ getInfoString WRITE setInfoString NOTIFY sigInfoStringChanged)

public:
    using MessagePtr = cc_tools::cc_plugin::MessagePtr;

    explicit QmlMessage(QObject* p = nullptr);
    ~QmlMessage();

    // Config members
    CC_MEMBER(MessagePtr, Msg)

    // Status members
    CC_MEMBER(QString, Name)
    CC_MEMBER(QString, InfoString)

signals:
    void sigMsgChanged(MessagePtr value);
    void sigNameChanged(const QString& value);
    void sigInfoStringChanged(const QString& value);

private slots:
    void msgUpdated(MessagePtr value);    

private:
    void resetStatus();
    void updateStatus();

};

} // namespace cc_view

} // namespace cc_tools
