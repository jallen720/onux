# include("cmake/functions/print_list.cmake")

macro(test_module_dependency module)
    find_package(${module} REQUIRED)

    # print_list(${module}_INCLUDE_DIRS "${module}_INCLUDE_DIRS")
    # print_list(${module}_LIBRARIES "${module}_LIBRARIES")

    list(APPEND test_include_dirs ${${module}_INCLUDE_DIRS})
    list(APPEND test_libraries ${${module}_LIBRARIES})
    list(REMOVE_DUPLICATES test_include_dirs)
    list(REMOVE_DUPLICATES test_libraries)
endmacro()
