cmake_minimum_required(VERSION 3.8)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp triangle.cpp triangle.h base.h camera.cpp camera.h scene.cpp scene.h tetrahedron.cpp tetrahedron.h sphere.cpp sphere.h material.cpp material.h)
add_executable(Ray_tracer ${SOURCE_FILES})
target_include_directories(Ray_tracer PUBLIC GLM)