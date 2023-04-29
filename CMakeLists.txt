cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 20)

project(universal VERSION 0.3.0 DESCRIPTION "a general purpose c++ library")

include(GNUInstallDirs)

find_package(nlohmann_json 3.2.0 REQUIRED)

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_library(universal STATIC
        Code/Source/Universal/Algorithm/Noise/PerlinNoiseGenerator2D.cpp
        Code/Source/Universal/Algorithm/Noise/VectorGrid2D.cpp
        Code/Source/Universal/Algorithm/Noise/FloatMap2D.cpp
        Code/Source/Universal/Math/BoundingBox2D.cpp
        Code/Source/Universal/Math/Math.cpp
        Code/Source/Universal/Math/Vector/Vector2f.cpp
        Code/Source/Universal/Math/Vector/Vector3f.cpp
        Code/Source/Universal/Math/Random/Generator.cpp
        Code/Source/Universal/Profiling/Timer.cpp
        Code/Source/Universal/Profiling/TimeRegistry.cpp
        Code/Source/Universal/Graphics/Bitmap.cpp
        Code/Source/Universal/Graphics/GraphicsUtils.cpp
        Code/Include/Universal/Algorithm/Noise/PerlinNoiseGenerator2D.h
        Code/Include/Universal/Algorithm/Noise/VectorGrid2D.h
        Code/Include/Universal/Algorithm/Noise/FloatMap2D.h
        Code/Include/Universal/Math/BoundingBox2D.h
        Code/Include/Universal/Math/Math.h
        Code/Include/Universal/Math/Vector/Vector2f.h
        Code/Include/Universal/Math/Vector/Vector3f.h
        Code/Include/Universal/Math/Random/Generator.h
        Code/Include/Universal/Math/Random/RandomUtils.h
        Code/Include/Universal/Profiling/Timer.h
        Code/Include/Universal/Profiling/TimeRegistry.h
        Code/Include/Universal/Graphics/Channel.h
        Code/Include/Universal/Graphics/Bitmap.h
        Code/Include/Universal/Graphics/Buffer.h
        Code/Include/Universal/Graphics/GraphicsUtils.h
        Code/Include/Universal/Graphics/Color.h
        Code/Source/Universal/Graphics/Color.cpp
        Code/Include/Universal/Math/Matrix/Matrix2x3f.h
        Code/Source/Universal/Math/Matrix/Matrix2x3f.cpp
        3rdParty/Include/stb/stb_image.h
        Code/Source/Universal/System/Clock.cpp Code/Include/Universal/System/Clock.h Code/Source/Universal/Math/Vector/Vector4f.cpp Code/Include/Universal/Math/Vector/Vector4f.h Code/Source/Universal/Math/Matrix/Matrix3x4f.cpp Code/Include/Universal/Math/Matrix/Matrix3x4f.h)

target_include_directories(universal
        PUBLIC Code/Include
        PRIVATE Code/Source 3rdParty/Include
        )

target_link_libraries(universal PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(universal PROPERTIES VERSION ${PROJECT_VERSION})

configure_file(tools/universal.pc.in tools/universal.pc @ONLY)

install(DIRECTORY Code/Include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS universal
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

install(FILES ${CMAKE_BINARY_DIR}/tools/universal.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

if(BUILD_TESTS)
    add_subdirectory(Code/Tests)
endif()
