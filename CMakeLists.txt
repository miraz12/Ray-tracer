cmake_minimum_required(VERSION 3.8)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 11)

find_package(glm REQUIRED)

set(SOURCE_FILES main.cpp triangle.cpp triangle.h base.h camera.cpp camera.h scene.cpp scene.h)
add_executable(Ray_tracer ${SOURCE_FILES})

target_link_libraries(Ray_tracer PRIVATE glm)