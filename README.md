# Universal

<h1 align="center">
  <img src="static/universal-logo-name-high-res.png" alt="Universal">
</h1>

Universal is a multipurpose C++ library used in my Projects.

## Features
### C++
The Universal library delivers a set of utilities for C++ code development: 
1. **Math**
   - **2D Bounding Box**
   - **2D, 3D, 4D Vectors**
   - **2x3, 3x4 Matrices**
   - **Random Number Generator**
   - Math Utility functions
2. **Profiling**
   - **Timer**
   - **TimeRegistry**
3. **Algorithm**
   - **Noise** 
        - **PerlinNoiseGenerator2D**
4. **Graphics**
   - **Bitmap** class with associated utilities
   - **Color**
### Python Tools
All the python tool files are located under `python/tools`.
1. **Time Registry Plotter** - Tool for plotting data generated by the TimeRegistry.

***Note:*** For more information on how to use the tools please refer to each tool's `--help` argument output.

## Installation prerequisites
The Universal library depends on these libraries and python packages:

 - [nlohmann/json](https://github.com/nlohmann/json)
 - [numpy](https://numpy.org/)
 - [matplotlib](https://matplotlib.org/)

You can install them with the following bash commands:
```Bash
sudo apt-get -y install nlohmann-json3-dev # Required by the C++ library
pip install numpy matplotlib # Required by python tools
```
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
    cmake .. -DCMAKE_BUILD_TYPE=Release
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
