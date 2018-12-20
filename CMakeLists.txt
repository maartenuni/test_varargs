cmake_minimum_required(VERSION 3.5)

project (var_args
        VERSION     "0.0"
        LANGUAGES   C CXX
        )

set(HEADERS "init.h")
set(SOURCES init.c program.c)

add_executable(program ${SOURCES} ${HEADERS})
