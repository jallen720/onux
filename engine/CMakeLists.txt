# Project info
cmake_minimum_required(VERSION "3.2.2" FATAL_ERROR)
project("onux-engine")

# Utilities
include("cmake/macros/module_dependency.cmake")
include("cmake/macros/test_module_dependency.cmake")

# Configuration
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

# Library
module_dependency("GLEW")
module_dependency("GLFW3")
module_dependency("Magick++")
module_dependency("Assimp")
module_dependency("Boost")
module_dependency("yaml-cpp")

include_directories("include;${include_dirs}")
set(library ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE sources "src/*.cpp")
add_library(${library} SHARED ${sources})
target_link_libraries(${library} ${libraries})

# Tests
test_module_dependency("GoogleTest")
test_module_dependency("OnuxEngine")

include_directories("tests/include;${test_include_dirs}")
set(tests "tests")
file(GLOB_RECURSE test_sources "tests/src/*.cpp")
add_executable(${tests} ${test_sources})
target_link_libraries(${tests} "${libraries};${test_libraries}")
