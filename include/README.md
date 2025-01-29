# Substring_lib Header-Only Installation
Copy the `include` directory to your project and add it to your include path

1. Copy `include` to your project.
2. Before compiling, add the directory to your include path.
    ```CMake
    include_directories(include include/algorithms)
    ```
3. Include the graaf header in your sources.
    ```c++
    #include <substring_lib.h>
    ```