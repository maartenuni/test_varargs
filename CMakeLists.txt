cmake_minimum_required(VERSION 3.5)

project (var_args
        VERSION     "0.0"
        LANGUAGES   C CXX
        )

set(HEADERS "init.h")
set(SOURCES init.c program.c)

add_executable(program ${SOURCES} ${HEADERS})

if (NOT MSVC)
    target_compile_options(program PRIVATE -W -Wall -Wextra -pedantic)
else()
    target_compile_options(program PRIVATE /W4)
endif()
