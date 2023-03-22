cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Release)

project(universal VERSION 0.2.0 DESCRIPTION "a general purpose c++ library")

include(GNUInstallDirs)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(universal STATIC
        src/Math/BoundingBox2D.cpp
        src/Math/Math.cpp
        src/Math/Random.cpp
        src/Math/Vector2.cpp
        src/Math/Vector3.cpp
        src/Profiling/Timer.cpp
        src/Profiling/TimeRegistry.cpp
        )

target_link_libraries(universal PRIVATE nlohmann_json::nlohmann_json)

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