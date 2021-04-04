cmake_minimum_required(VERSION 3.17)
project(Assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment2 dining-room.cpp Camera.cpp Camera.h Parser.h Parser.cpp Floor.h Floor.cpp Room.h Room.cpp Shelf.h Shelf.cpp Chair.h Chair.cpp Table.h Table.cpp Fan.h Fan.cpp Teapot.h Teapot.cpp Objects.h Objects.cpp Toys.h Toys.cpp)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
include_directories(Assignment2 GLM_INCLUDE_DIR)

target_link_libraries(Assignment2 OpenGL::OpenGL OpenGL::GLU GLUT::GLUT GLEW::GLEW)
