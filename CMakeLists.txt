cmake_minimum_required(VERSION 3.30)

project(rtlang
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)

include_directories(include)

add_executable(rtlang
    src/main.c
    src/error.c
    src/lexer.c
    src/utils.c
)
