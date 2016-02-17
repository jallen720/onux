# Find GL
#
# Exports:
#     GL_INCLUDE_DIRS - include directories for GL
#     GL_LIBRARIES    - libraries to link against GL
#     GL_FOUND        - true if GL has been found and can be used

include("FindPackageHandleStandardArgs")

set(GL_LIBRARIES "GL")

find_package_handle_standard_args(
    GL
    REQUIRED_VARS
    GL_LIBRARIES
)

mark_as_advanced(GL_LIBRARIES)
