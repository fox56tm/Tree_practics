cmake_minimum_required(VERSION 3.25)
project(example C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ExampleLib src/bstHeight.c src/bstMax.c src/bstMin.c src/bstSize.c)

add_executable(main src/main.c)
target_link_libraries(main PRIVATE ExampleLib)
