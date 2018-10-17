cmake_minimum_required(VERSION 3.5)
project(Ray_tracer)

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#set(CMAKE_CXX_FLAGS "-Wall ")
#set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE_FILES main.cpp triangle.cpp triangle.h base.h camera.cpp camera.h scene.cpp scene.h tetrahedron.cpp tetrahedron.h sphere.cpp sphere.h material.cpp material.h lightsource.cpp lightsource.h random.cc random.h spherelightsource.cpp spherelightsource.h)
add_executable(Ray_tracer ${SOURCE_FILES})
target_include_directories(Ray_tracer PUBLIC GLM)
