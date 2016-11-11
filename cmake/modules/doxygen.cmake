#-----------------------------------------------------------------------------
#                               DOXYGEN ?
#-----------------------------------------------------------------------------
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(
        "${CMAKE_SOURCE_DIR}/cmake/in/Doxyfile.in.cmake"
        "${CMAKE_BINARY_DIR}/doc/Doxyfile"
        @ONLY
    )
    add_custom_target(
        doc
        COMMAND doxygen ${CMAKE_BINARY_DIR}/doc/Doxyfile
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT Doxygen is generating the documentation...
        VERBATIM
    )
else(DOXYGEN_FOUND)
    message(WARNING "Doxygen not found. Target doc will not be available")
endif(DOXYGEN_FOUND)

