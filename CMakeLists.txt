cmake_minimum_required(VERSION 3.24)
project(RotatingCubeSDL2)

set(CMAKE_CXX_STANDARD 17)


find_package(SDL2 REQUIRED COMPONENTS SDL2)

add_executable(RotatingCubeSDL2 main.cpp screen.h)
target_link_libraries(RotatingCubeSDL2 PRIVATE SDL2::SDL2)

