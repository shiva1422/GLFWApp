cmake_minimum_required(VERSION 3.22)
project(GLFWApp)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(GLFW_DIR "/opt/homebrew/Cellar/glfw/3.3.8")
set(GLFW_DIR "/opt/homebrew/Cellar/glfw/3.3.8")

include_directories( ${GLFW_DIR}/include glloader/include)
link_directories(${GLFW_DIR}/lib)
set(GLFW_LIBRARIES ${GLFW_DIR}/lib/libglfw.3.3.dylib )

add_subdirectory(CV mycv)
add_subdirectory(./Graphics ksgraphics)

add_executable(glfwapp main.cpp GLFWApplication.cpp GLFWApplication.h Application.cpp glloader/src/glad.c CV/cv_main.cpp KSIO/KSFileStream.cpp KSIO/KSFileStream.h)
target_link_libraries(glfwapp ${GLFW_LIBRARIES} mycv ksgraphics)



