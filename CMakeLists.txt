cmake_minimum_required(VERSION 3.2)

project(opengl_demo)

#find_package(OpenCV REQUIRED)

#use c++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#debug mode, use gdb to debug
#SET(CMAKE_BUILD_TYPE "Debug") 
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

set(OpenGL_INCLUDE_DIRS /usr/include/GL)
set(OpenGL_LIBS GL GLU GLEW glut)

include_directories(
 include
 /usr/local/include
 ${OpenGL_INCLUDE_DIRS}
)


#all source put here
#set(exSrcList
#    src/example.cpp)


add_executable(example src/example.cpp)
add_executable(dot src/dot.cpp)
add_executable(triangle src/triangle.cpp)
add_executable(triColor src/triColor.cpp)

target_link_libraries(example ${OpenGL_LIBS})
target_link_libraries(dot ${OpenGL_LIBS})
target_link_libraries(triangle ${OpenGL_LIBS})
target_link_libraries(triColor ${OpenGL_LIBS})
