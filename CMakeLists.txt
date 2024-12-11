cmake_minimum_required(VERSION 3.12)

project(AdventOfCode LANGUAGES C CXX)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED ON)

add_subdirectory(Day1)
add_subdirectory(Day2)
