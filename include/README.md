# Substring_lib Header-Only Installation
Для установки заголовков скопируйте `include` директорию в ваш проект и добавьте ее содержимое в ваш include path

1. Скопируйте `include` в ваш проект
2. Перед компиляцией добавьте содержимое в include
    ```CMake
    include_directories(include include/algorithms)
    ```
3.  Добавьте заголовочный файл substring-lib в ваш исходник
    ```c++
    #include <substring_lib.h>
    ```