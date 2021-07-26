cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER /usr/bin/g++-10)

project(DartsPi)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory("src")
add_subdirectory("tests")
