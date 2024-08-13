cmake_minimum_required(VERSION 3.22)
project(CV)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CV_LIB_DIR "/Users/shivaaz/Projects/cv/buildopencv/modules")
set(CV_HEADER_DIR "/Users/shivaaz/Projects/cv/opencv/modules")


include_directories(${CV_HEADER_DIR})

link_directories(${GLFW_DIR}/lib)
set(CV_LIBS)

add_library(mycv cv_main.cpp)
target_link_libraries(mycv ${CV_LIBS})
