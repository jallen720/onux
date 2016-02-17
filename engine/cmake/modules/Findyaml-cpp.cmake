# Find yaml-cpp
#
# Exports:
#     yaml-cpp_INCLUDE_DIRS - include directories for yaml-cpp
#     yaml-cpp_LIBRARIES    - libraries to link against yaml-cpp
#     yaml-cpp_FOUND        - true if yaml-cpp has been found and can be used

include("cmake/macros/pkg_config_module.cmake")

pkg_config_module(yaml-cpp "yaml-cpp")
