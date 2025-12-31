cmake_minimum_required(VERSION 3.30)

project(rtlang
    VERSION 0.1.0
    LANGUAGES C
)

add_executable(rtlang src/main.c src/lexer.c)
