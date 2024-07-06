cmake_minimum_required(VERSION 3.15)
project(test_universal)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        Universal/MainTest.cpp
        Universal/Algorithm/Noise/FloatMap2DTest.cpp
        Universal/Algorithm/Noise/PerlinNoiseGenerator2DTest.cpp
        Universal/Algorithm/Noise/VectorGrid2DTest.cpp
        Universal/Math/Vector/Vector2fTest.cpp
        Universal/Math/Vector/Vector3fTest.cpp
        Universal/Math/Aabb2DTest.cpp
        Universal/Math/MathTest.cpp
        Universal/Math/Random/Generator.cpp
        Universal/Graphics/BitmapTest.cpp
        Universal/Graphics/BufferTest.cpp
        Universal/Math/Matrix/Matrix2x3fTest.cpp
        Universal/System/ClockTest.cpp
        Universal/Math/Vector/Vector4Test.cpp
        Universal/Math/Matrix/Matrix3x4fTest.cpp
        Universal/Math/TransformTest.cpp
        Universal/Graphics/ColorTest.cpp
        Universal/Math/QuaternionTest.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE universal gtest gtest_main)
