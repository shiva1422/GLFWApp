cmake_minimum_required(VERSION 3.22)
project(ksgraphics)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_library(ksgraphics STATIC Shader.cpp)