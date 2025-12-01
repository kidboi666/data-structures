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
        src/include/singly_list.h
        src/singly_list.c
        src/include/circular_list.h
        src/circular_list.c
        src/include/binary_tree.h
        src/binary_tree.c
)
