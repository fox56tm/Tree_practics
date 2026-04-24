cmake_minimum_required(VERSION 3.25)
project(bst)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(bstlib src/bst.c)

add_executable(main src/main.c)

target_link_libraries(main PRIVATE bstlib)