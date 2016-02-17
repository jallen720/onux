include("FindPackageHandleStandardArgs")

macro(pkg_config_module module pkg_config_name)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(${module}_PKG_CONFIG ${pkg_config_name})

    set(${module}_INCLUDE_DIRS ${${module}_PKG_CONFIG_INCLUDE_DIRS})
    set(${module}_LIBRARIES ${${module}_PKG_CONFIG_LIBRARIES})

    find_package_handle_standard_args(
        ${module}
        REQUIRED_VARS
        ${module}_INCLUDE_DIRS
        ${module}_LIBRARIES
    )

    mark_as_advanced(${module}_INCLUDE_DIRS ${module}_LIBRARIES)
endmacro()
