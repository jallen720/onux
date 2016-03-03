function(print_list list list_name)
    message("\n${list_name} {")

    foreach(element IN LISTS ${list})
        message("    ${element}")
    endforeach()

    message("}\n")
endfunction()
