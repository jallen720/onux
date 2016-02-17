# Find Boost
#
# Exports:
#     Boost_INCLUDE_DIRS - include directories for Boost
#     Boost_LIBRARIES    - libraries to link against Boost
#     Boost_FOUND        - true if Boost has been found and can be used

include("FindPackageHandleStandardArgs")

set(Boost_INCLUDE_DIRS "/usr/local/include")
set(Boost_LIBRARIES "boost_system;boost_filesystem")

find_package_handle_standard_args(
    Boost
    REQUIRED_VARS
    Boost_INCLUDE_DIRS
    Boost_LIBRARIES
)

mark_as_advanced(Boost_INCLUDE_DIRS Boost_LIBRARIES)
