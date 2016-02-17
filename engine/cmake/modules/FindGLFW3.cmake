# Find GLFW3
#
# Exports:
#     GLFW3_INCLUDE_DIRS - include directories for GLFW3
#     GLFW3_LIBRARIES    - libraries to link against GLFW3
#     GLFW3_FOUND        - true if GLFW3 has been found and can be used

include("cmake/macros/pkg_config_module.cmake")

pkg_config_module(GLFW3 "glfw3")
