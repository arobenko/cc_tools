if (NOT CC_BUILD_DEMO_PROTOCOL)
    return ()
endif ()

set (cc_source_dir ${CC_EXTERNALS_DIR}/comms_champion)
set (cc_install_dir ${CMAKE_CURRENT_BINARY_DIR}/comms_champion/install)

cc_prefetch(SRC_DIR ${cc_source_dir})

include (${cc_source_dir}/cmake/CC_External.cmake)
cc_build_during_config(
    SRC_DIR ${cc_source_dir}
    CMAKE_ARGS
        -DCC_COMMS_LIB_ONLY=ON
        -DCC_NO_UNIT_TESTS=ON
        -DCMAKE_INSTALL_PREFIX=${cc_install_dir}
)

list (APPEND CMAKE_PREFIX_PATH ${cc_install_dir})
find_package(LibComms REQUIRED)

set (name "cc_demo_protocol")
set (src
    DemoProtocol.cpp
    DemoProtocolPlugin.cpp
)

add_library (${name} MODULE ${src})

target_link_libraries(${name} PRIVATE cc::comms cc::plugin Qt5::Core)
target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(
    TARGETS ${name}
    DESTINATION ${CC_PLUGIN_INSTALL_DIR}
)