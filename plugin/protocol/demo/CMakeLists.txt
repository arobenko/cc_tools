if (NOT CC_BUILD_DEMO_PROTOCOL)
    return ()
endif ()

set (cc_source_dir ${CC_EXTERNALS_DIR}/comms_champion)
set (cc_install_dir ${CMAKE_CURRENT_BINARY_DIR}/comms_champion/install)

set (tag_opt)
if (NOT "${CC_TAG}" STREQUAL "")
    set (tag_opt TAG ${CC_TAG})
endif ()

set (repo_opt)
if (NOT "${CC_REPO}" STREQUAL "")
    set (repo_opt TAG ${CC_REPO})
endif ()

cc_prefetch(SRC_DIR ${cc_source_dir} ${tag_opt} ${repo_opt})

include (${cc_source_dir}/cmake/CC_External.cmake)
cc_build_during_config(
    SRC_DIR ${cc_source_dir}
    ${tag_opt} ${repo_opt}
    CMAKE_ARGS
        -DCC_BUILD_TOOLS_LIBRARY=OFF
        -DCC_BUILD_UNIT_TESTS=OFF
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