# Find Magick++
#
# Exports:
#     Magick++_INCLUDE_DIRS - include directories for Magick++
#     Magick++_LIBRARIES    - libraries to link against Magick++
#     Magick++_FOUND        - true if Magick++ has been found and can be used

include("cmake/macros/pkg_config_module.cmake")

pkg_config_module(Magick++ "Magick++-6.Q16")
