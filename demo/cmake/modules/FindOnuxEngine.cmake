# Find OnuxEngine
#
# Exports:
#     OnuxEngine_INCLUDE_DIRS - include directories for OnuxEngine
#     OnuxEngine_LIBRARIES    - libraries to link against OnuxEngine
#     OnuxEngine_FOUND        - true if OnuxEngine has been found and can be used

include("FindPackageHandleStandardArgs")

set(OnuxEngine_INCLUDE_DIRS "/home/joel/Desktop/projects/onux/engine/include")
set(OnuxEngine_LIBRARIES "/home/joel/Desktop/projects/onux/engine/lib/libonux-engine.so")

find_package_handle_standard_args(
    OnuxEngine
    REQUIRED_VARS
    OnuxEngine_INCLUDE_DIRS
    OnuxEngine_LIBRARIES
)

mark_as_advanced(OnuxEngine_INCLUDE_DIRS OnuxEngine_LIBRARIES)
