# Find GLEW
#
# Exports:
#     GLEW_INCLUDE_DIRS - include directories for GLEW
#     GLEW_LIBRARIES    - libraries to link against GLEW
#     GLEW_FOUND        - true if GLEW has been found and can be used

include("cmake/macros/pkg_config_module.cmake")

pkg_config_module(GLEW "glew")
