# substring-lib
![Build Status](https://github.com/lilyreber/substring-lib/actions/workflows/cmake-single-platform.yml/badge.svg)
![License](https://img.shields.io/badge/License-MIT-blue.svg)

This C++ Library provides tools for solving common problems,
such as substring search and pattern matching for different
purposes


## Algorithms

Algorithms implemented in the substring-lib include the following. For more information on individual algorithms please take a look at the [docs](docs/Algo-description.pdf).
1. Knuth-Morris-Pratt (KMP) Algorithm
2. Boyer-Moore Algorithm
3. Rabin-Karp Algorithm
4. Suffix Array Construction
5. Z-Algorithm
6. Aho-Corasick Algorithm
7. Not So Naive Algorithm
8. Max Common Substring
9. Kasai Algorithm
10. Quick Search Algorithm

## Build

### For Linux

1. **Build the project:**
```sh
    mkdir build
    cd build
    cmake ..
    make
```

2. **Run the tests:**
```sh
    ctest
```

### For Windows (MSVC)

1. **Build the project:**
```sh
    mkdir build
    cd build
    cmake .. -G "Visual Studio 16 2019" # Change generator if using another version of Visual Studio
    cmake --build . --config Release
```

2. **Run the tests:**
```sh
    ctest --build . --config Release
```

### For macOS

1. **Build the project:**
```sh
    mkdir build
    cd build
    cmake ..
    make
```


2. **Run the tests:**
```sh
    ctest
```

## Installation Header-only
Substring-lib can be included as a header-only library.
Download the `include` directory from our repository and add it to your include path.

You can now use Graaf in your source files:
```c++
#include <substring_lib.h>
```

[Installation](lib/include/README.md)

## Contributing

```substring-lib``` - is HSE university project.
Therefore, we welcome your comments and advice. For any questions (including bugreports and recommendations), please contact our developers

## License

This project is licensed under the [MIT license](LICENSE)

## Contributors

* [Залилова Диана](https://www.github.com/mediana105)
* [Иванова Арина](https://www.github.com/Arishkamu)
* [Имамутдинова Лилия](https://www.github.com/lilyreber)
* [Исаева Екатерина](https://www.github.com/karambo3a)
* [Мухаметлиева Алина](https://www.github.com/Alina-Muha)

HSE SPB, AMIS-3
