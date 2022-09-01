cmake_minimum_required(VERSION 3.19)

project(Clog VERSION 0.1 DESCRIPTION "My blog, in C++" LANGUAGES CXX)

SET(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory(Clog/lib)
add_subdirectory(Clog/bin)
