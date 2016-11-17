cmake_minimum_required(VERSION 2.8)

# set cmake module path, to search in cmake/modules first
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")
#-----------------------------------------------------------------------------
#                               MODULES
#-----------------------------------------------------------------------------
include(static_analysis)
#include(doxygen)
#include(ccache)
#-----------------------------------------------------------------------------
#                           GENERAL CONFIGURATION
#-----------------------------------------------------------------------------
project(ProjectName CXX)
#-----------------------------------------------------------------------------
#                              DEPENDENCIES
#-----------------------------------------------------------------------------
# find your dependencies here !
# ==> use cmake --help-module-list
# ==> and cmake --help-module FindBoost to known which variables are setted
# find_package(Boost COMPONENTS filesystem threads)
# include_directories(${Boost_INCLUDE_DIRS})
find_package(OpenGL)
include_directories(${OpenGL_INCLUDE_DIRS})
find_package(GLEW)
include_directories(${GLEW_INCLUDE_DIRS})

#-----------------------------------------------------------------------------
#                           BUILD TYPES & FLAGS
#-----------------------------------------------------------------------------

include(sanitizers)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++1y")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
else(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
endif()

# strip binary in release mode
if(CMAKE_BUILD_TYPE MATCHES "RELEASE")
    set(CMAKE_EXE_LINKER_FLAGS "-s")
endif()

#-----------------------------------------------------------------------------
#                               SOURCES
#-----------------------------------------------------------------------------

# to add an include path
include_directories(
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/src/common
    ${PROJECT_SOURCE_DIR}/src/common/thirdparty
    ${PROJECT_SOURCE_DIR}/src/common/thirdparty/stb_image
    ${PROJECT_SOURCE_DIR}/src/common/thirdparty/glfw/include
)

set(SOURCES

    src/miners/main.cc
    src/miners/Arguments.cc
    src/miners/Algorithm.cc
    src/miners/Manager.cc

    src/miners/Scene3D.cc
    src/miners/Scene2D.cc

    src/miners/FileLoader.cc
    src/miners/MmapLoader.cc

    src/miners/ContiAlgorithm3D.cc
    src/miners/Algorithm2DFourColors.cc
    src/miners/Algorithm2DGrayscale.cc

    src/miners/GlfwManager.cc

    src/common/platform/linux/platform.cpp

    src/common/tdogl/Bitmap.cpp
    src/common/tdogl/Camera.cpp
    src/common/tdogl/Program.cpp
    src/common/tdogl/Shader.cpp
    src/common/tdogl/Texture.cpp
)

# create your executable with
add_executable(miners ${SOURCES})

# create a library with
# add_library(my_lib SHARED ${SOURCES})

# you can link both with
target_link_libraries(miners m GL GLEW glfw)

add_custom_command(TARGET miners POST_BUILD
                   COMMAND ln -sf ${PROJECT_SOURCE_DIR}/src/resources .)

#-----------------------------------------------------------------------------
#                           	PACKAGING
#-----------------------------------------------------------------------------
# package your installation with the install command
# see cmake documentation for further explanation
# edit cmake/modules/packaging to setup package name, dependencies ...

# install(
# 	FILES <file1> <file2> ...
# 	DESTINATION <dir>
# 	PERMISSIONS OWNER_READ OWNER_WRITE ...
# )
# OR
# install(PROGRAMS myexecutable DESTINATION <dir>)

include(uninstall)
# add_subdirectory("${CMAKE_SOURCE_DIR}/cmake/cpack") # enable packaging with CPack

#-----------------------------------------------------------------------------
#                               BUILD SUMMARY
#-----------------------------------------------------------------------------
message(STATUS " ↳ Compiler     → ${CMAKE_CXX_COMPILER}")
message(STATUS " ↳ Prefix       → ${CMAKE_INSTALL_PREFIX}")
message(STATUS " ↳ Build        → ${CMAKE_BUILD_TYPE}")
message(STATUS " ↳ Sanitizers   → ${COMPILER_SANITIZER}")
message(STATUS " ↳ CXX Flags    → ${CMAKE_CXX_FLAGS}")
