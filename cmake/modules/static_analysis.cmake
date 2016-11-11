#-----------------------------------------------------------------------------
#                               STATIC ANALYSIS
#-----------------------------------------------------------------------------
# detect ccc_analyzer
# create ${CMAKE_BINARY_DIR}/static_analysis_build
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/static_analysis_build)
# create custom target
add_custom_target(
	static_analysis
	COMMAND cmake ../.. -DCMAKE_CXX_COMPILER=c++-analyzer -DCMAKE_BUILD_TYPE=DEBUG
	# -v -> verbosity
	# -V -> open results in browser
	COMMAND scan-build -v -V make
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/static_analysis_build
)

# # Since we cannot set a specific compiler for a specific target
# # we have to create a separate build type for static analysis
# # Also, we have to set this before any call to the project command
# # to be able to change CMAKE_C.._COMPILER variable
# if (${CMAKE_BUILD_TYPE} STREQUAL "STATIC_ANALYSIS")
#     # set C and CXX compiler
#     set(CMAKE_C_COMPILER "ccc-analyzer")
#     set(CMAKE_CXX_COMPILER "c++-analyzer")
# endif ()