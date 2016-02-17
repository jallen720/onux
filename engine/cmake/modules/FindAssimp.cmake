# Find Assimp
#
# Exports:
#     Assimp_INCLUDE_DIRS - include directories for Assimp
#     Assimp_LIBRARIES    - libraries to link against Assimp
#     Assimp_FOUND        - true if Assimp has been found and can be used

include("cmake/macros/pkg_config_module.cmake")

pkg_config_module(Assimp "assimp")
