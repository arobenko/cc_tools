find_package(Qt5 ${CC_MIN_QT_VERSION} COMPONENTS Quick Widgets REQUIRED)

set (name "cc_view")
set (src
    src/model/AvailableMessagesListModel.cpp
    src/model/MessageFieldsListModel.cpp
    src/qml/QmlMessage.cpp
    src/AppMgr.cpp
    src/GuiState.cpp
    src/main.cpp
    src/MessageCreator.cpp
    src/PluginListModel.cpp
    resources.qrc
)

add_executable (${name} ${src})

target_compile_definitions(${name}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${name} PRIVATE cc::app cc::plugin Qt5::Quick Qt5::Widgets Qt5::Core)
target_include_directories(${name} PRIVATE src)

install(
    TARGETS ${name}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if (UNIX)
    install(
        PROGRAMS script/cc_view.sh
        DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endif ()  