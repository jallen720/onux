# Project info
cmake_minimum_required(VERSION "3.2.2" FATAL_ERROR)
project("demo")

# Utilities
include("cmake/macros/module_dependency.cmake")

# Configuration
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

# App
module_dependency("OnuxEngine")
module_dependency("GL")

include_directories("include;${include_dirs}")
set(target ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE sources "src/*.cpp")
add_executable(${target} ${sources})
target_link_libraries(${target} ${libraries})
