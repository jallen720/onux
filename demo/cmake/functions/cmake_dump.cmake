function(cmake_dump)
    message("================================= DUMP =================================")
    get_cmake_property(variable_names VARIABLES)

    foreach (variable_name ${variable_names})
        message(STATUS "${variable_name}=${${variable_name}}")
    endforeach()

    message("================================= DUMP =================================")
endfunction()
