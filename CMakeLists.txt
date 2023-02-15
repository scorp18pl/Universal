cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)

project(universal VERSION 0.1.0 DESCRIPTION "a general purpose c++ library")

include(GNUInstallDirs)

add_library(universal SHARED
        src/Math/Math.cpp
        src/Math/Vector2.cpp
        src/Profiling/Timer.cpp
        src/Profiling/TimeRegistry.cpp include/Profiling/TimeRegistry.h)

set_target_properties(universal PROPERTIES VERSION ${PROJECT_VERSION})

configure_file(tools/universal.pc.in tools/universal.pc @ONLY)

target_include_directories(universal
    PUBLIC include
    PRIVATE source
)

install(TARGETS universal
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Universal)

install(FILES ${CMAKE_BINARY_DIR}/tools/universal.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)