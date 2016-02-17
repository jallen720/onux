# include("cmake/functions/print_list.cmake")

macro(module_dependency module)
    find_package(${module} REQUIRED)

    # print_list(${module}_INCLUDE_DIRS "${module}_INCLUDE_DIRS")
    # print_list(${module}_LIBRARIES "${module}_LIBRARIES")

    list(APPEND include_dirs ${${module}_INCLUDE_DIRS})
    list(APPEND libraries ${${module}_LIBRARIES})
    list(REMOVE_DUPLICATES include_dirs)
    list(REMOVE_DUPLICATES libraries)
endmacro()
