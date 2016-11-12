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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++1y -fdiagnostics-color")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O2")

# strip binary in release mode
if(CMAKE_BUILD_TYPE MATCHES "RELEASE")
    set(CMAKE_EXE_LINKER_FLAGS "-s")
endif()

#-----------------------------------------------------------------------------
#                               SOURCES
#-----------------------------------------------------------------------------

# to add an include path
include_directories(
    ${PROJECT_SOURCE_DIR}/src/common/
    ${PROJECT_SOURCE_DIR}/src/common/thirdparty/
    ${PROJECT_SOURCE_DIR}/src/common/thirdparty/stb_image
)

set(
    SOURCES

    platforms/linux/platform_linux.cpp

    src/miners/source/main.cc
    src/miners/source/Arguments.cc
    src/miners/source/GlfwManager.cc
    src/miners/source/Scene.cc

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
