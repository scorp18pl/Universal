# Universal

Universal is a multipurpose C++ shared library used in my Projects.

## Library installation

1. Clone the repository.
    ```bash
    git clone https://github.com/scorp18pl/universal.git
    cd universal
    ```
2. Create and proceed to the build directory.
    ```bash
    mkdir build && cd build
    ```
3. Install the library.
    ```bash
    cmake ..
    sudo make install
    ```

## Using the library (CMake)

In your project's CMakeLists.txt file:
1. Find the library.
    ```CMake
    find_library(UNIVERSAL universal)
    ```
2. Link the found library with your target.
    ```CMake
    target_link_libraries(<target_name> ${UNIVERSAL})
    ```