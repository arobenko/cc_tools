#include <QtWidgets/QApplication>
#include <QtGui/QIcon>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "cc_tools/cc_plugin/PluginIntegration.h"

#include "model/AvailableMessagesListModel.h"
#include "model/EnumValuesModel.h"
#include "model/MessageFieldsListModel.h"

#include "qml/QmlEnumField.h"
#include "qml/QmlField.h"
#include "qml/QmlMessage.h"

#include "GuiState.h"
#include "AppMgr.h"
#include "PluginListModel.h"
#include "MessageCreator.h"


namespace 
{

QObject *getPluginIntegration(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    auto* obj = cc_tools::cc_plugin::PluginIntegration::instancePtr();
    QQmlEngine::setObjectOwnership(obj, QQmlEngine::CppOwnership);
    return obj;
}

QObject *getGuiState(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    auto* st = cc_tools::cc_view::GuiState::instancePtr();
    QQmlEngine::setObjectOwnership(st, QQmlEngine::CppOwnership);
    return st;
}

QObject *getAppMgr(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    auto* mgr = &cc_tools::cc_view::AppMgr::instance();
    QQmlEngine::setObjectOwnership(mgr, QQmlEngine::CppOwnership);
    return mgr;
}

void metaTypesRegisterAll()
{
    qRegisterMetaType<cc_tools::cc_plugin::Message::MessageIdType>("MessageIdType");
    qRegisterMetaType<cc_tools::cc_plugin::MessagePtr>("MessagePtr");
    qRegisterMetaType<cc_tools::cc_plugin::FieldPtr>("FieldPtr");
    qRegisterMetaType<cc_tools::cc_plugin::EnumFieldPtr>("EnumFieldPtr");
}

void qmlRegisterTypes()
{
    qmlRegisterSingletonType<cc_tools::cc_plugin::PluginIntegration>("CC", 1, 0, "CC_PluginIntegration", &getPluginIntegration);
    qmlRegisterSingletonType<cc_tools::cc_view::GuiState>("CC", 1, 0, "CC_GuiState", &getGuiState);
    qmlRegisterSingletonType<cc_tools::cc_view::AppMgr>("CC", 1, 0, "CC_AppMgr", &getAppMgr);

    qmlRegisterType<cc_tools::cc_view::PluginListModel>("CC", 1, 0, "CC_PluginListModel");
    qmlRegisterType<cc_tools::cc_view::AvailableMessagesListModel>("CC", 1, 0, "CC_AvailableMessagesListModel");
    qmlRegisterType<cc_tools::cc_view::EnumValuesModel>("CC", 1, 0, "CC_EnumValuesModel");
    qmlRegisterType<cc_tools::cc_view::MessageFieldsListModel>("CC", 1, 0, "CC_MessageFieldsListModel");
    qmlRegisterType<cc_tools::cc_view::MessageCreator>("CC", 1, 0, "CC_MessageCreator");
    qmlRegisterType<cc_tools::cc_view::QmlEnumField>("CC", 1, 0, "CC_QmlEnumField");
    qmlRegisterType<cc_tools::cc_view::QmlField>("CC", 1, 0, "CC_QmlField");
    qmlRegisterType<cc_tools::cc_view::QmlMessage>("CC", 1, 0, "CC_QmlMessage");
}

} // namespace 


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/image/app_icon.png"));

    metaTypesRegisterAll();
    qmlRegisterTypes();
    //QQuickStyle::setStyle("Breeze");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
