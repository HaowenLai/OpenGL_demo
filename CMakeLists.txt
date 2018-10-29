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


# add_executable(example src/example.cpp)
# add_executable(dot src/dot.cpp)
# add_executable(triangle src/triangle.cpp)
# add_executable(triColor src/triColor.cpp)
add_executable(2_4_rectangle src/2_4_rectangle.cpp)
add_executable(2_5_rectMove src/2_5_rectMove.cpp)
add_executable(3_4_3dPaintPad src/3_4_3dPaintPad.cpp)
add_executable(3_4_3dRotate src/3_4_3dRotate.cpp)
add_executable(3_6_lines src/3_6_lines.cpp)
add_executable(3_7_polygons src/3_7_polygons.cpp)
add_executable(3_8_solidObject src/3_8_solidObject.cpp)
add_executable(rubikCube src/rubikCube.cpp)



# target_link_libraries(example ${OpenGL_LIBS})
# target_link_libraries(dot ${OpenGL_LIBS})
# target_link_libraries(triangle ${OpenGL_LIBS})
# target_link_libraries(triColor ${OpenGL_LIBS})
target_link_libraries(2_4_rectangle ${OpenGL_LIBS})
target_link_libraries(2_5_rectMove ${OpenGL_LIBS})
target_link_libraries(3_4_3dPaintPad ${OpenGL_LIBS})
target_link_libraries(3_4_3dRotate ${OpenGL_LIBS})
target_link_libraries(3_6_lines ${OpenGL_LIBS})
target_link_libraries(3_7_polygons ${OpenGL_LIBS})
target_link_libraries(3_8_solidObject ${OpenGL_LIBS})
target_link_libraries(rubikCube ${OpenGL_LIBS})
