# Find GoogleTest
#
# Exports:
#     GoogleTest_INCLUDE_DIRS - include directories for GoogleTest
#     GoogleTest_LIBRARIES    - libraries to link against GoogleTest
#     GoogleTest_FOUND        - true if GoogleTest has been found and can be used

include("FindPackageHandleStandardArgs")

set(GoogleTest_INCLUDE_DIRS "/usr/local/include")
set(GoogleTest_LIBRARIES "gtest;pthread")

find_package_handle_standard_args(
    GoogleTest
    REQUIRED_VARS
    GoogleTest_INCLUDE_DIRS
    GoogleTest_LIBRARIES
)

mark_as_advanced(GoogleTest_INCLUDE_DIRS GoogleTest_LIBRARIES)
