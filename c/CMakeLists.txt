cmake_minimum_required(VERSION 4.0)
project(c C)

set(CMAKE_C_STANDARD 11)

add_executable(c main.c
        src/array.c
        src/stack.c
        src/include/stack.h
        src/include/array.h
        src/include/queue.h
        src/queue.c
)
