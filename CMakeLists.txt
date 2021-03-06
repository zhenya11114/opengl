cmake_minimum_required(VERSION 3.5)

project(ogl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

set(CMAKE_FIND_LIBRARY_PREFIXES "")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll" ".a")

add_executable(ogl main.cpp)

target_compile_options(ogl PRIVATE -Wall -Wextra -pedantic)
target_include_directories(ogl PRIVATE engine/ GL_H/ GLFW/ SOIL2/ glm/ libs/)

find_library(GLEW32 glew32 libs)
find_library(GLFW3 glfw3 libs)
find_library(SOIL libsoil2 libs)
find_library(OGL opengl32 libs)

#find_package(OpenGL REQUIRED)

target_link_libraries(ogl LINK_PUBLIC ${OGL} ${SOIL} ${GLEW32} ${GLFW3})
