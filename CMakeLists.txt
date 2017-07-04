cmake_minimum_required(VERSION 3.0)

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
project(voidstar CXX)

## These are cmake >= 3.1
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
#-----------------------------------------------------------------------------
#                              DEPENDENCIES
#-----------------------------------------------------------------------------
# find your dependencies here !
# ==> use cmake --help-module-list
# ==> and cmake --help-module FindBoost to known which variables are set.
# find_package(Boost COMPONENTS filesystem threads)
# include_directories(${Boost_INCLUDE_DIRS})

if(EMSCRIPTEN)
  message(STATUS "here!")
  include_directories( /usr/include )

  set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
  message(STATUS "Cmake prefix path: ${CMAKE_PREFIX_PATH}")
endif(EMSCRIPTEN)

if(NOT EMSCRIPTEN)
        message(STATUS "not here!")
  find_package(OpenGL REQUIRED)
  include_directories(${OpenGL_INCLUDE_DIR})
  find_package(GLEW REQUIRED)
  include_directories(${GLEW_INCLUDE_DIRS})
  find_package(PkgConfig REQUIRED)
  pkg_search_module(GLFW REQUIRED glfw3)
  include_directories(${GLFW_INCLUDE_DIRS})
endif()

#-----------------------------------------------------------------------------
#                           BUILD TYPES & FLAGS
#-----------------------------------------------------------------------------

include(sanitizers)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++1y ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
else(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
endif()

# # strip binary in release mode
# if(CMAKE_BUILD_TYPE MATCHES "RELEASE")
#     set(CMAKE_EXE_LINKER_FLAGS "-s")
# endif()

#-----------------------------------------------------------------------------
#                               SOURCES
#-----------------------------------------------------------------------------

add_subdirectory(${PROJECT_SOURCE_DIR}/src/resources)

# to add an include path
include_directories(
    ${PROJECT_SOURCE_DIR}/src/include
    ${PROJECT_SOURCE_DIR}/src/common
    ${CMAKE_CURRENT_BINARY_DIR}/src/resources
)

set(SOURCES
    src/main.cc
    src/Arguments.cc
    src/Algorithm.cc
    src/Manager.cc
    src/Loader.cc
    src/Scene.cc

    src/Scene3D.cc
    src/Scene2D.cc

    src/FileLoader.cc
    src/MmapLoader.cc

    src/Algo2DEntropy.cc
    src/Algo2DFourColors.cc
    src/Algo2DGrayscale.cc
    src/Algo3DCubeFull.cc
    src/Algo3DCubeContiBnW.cc
    src/Algo3DCubeContiRainbow.cc
    src/Algo3DCubeContiFrebet.cc
    src/Algo3DSphereFull.cc
    src/Algo3DSphereContiBnW.cc
    src/Algo3DSphereContiRainbow.cc
    src/Algo3DSphereContiFrebet.cc

    src/GlfwManager.cc

    src/common/tdogl/Camera.cpp
    src/common/tdogl/Program.cpp
    src/common/tdogl/Shader.cpp
)

if(APPLE)
    #set(GUI_TYPE MACOSX_BUNDLE)
    include_directories(/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation)
    mark_as_advanced(COREFOUNDATION_LIBRARY)
    set(EXTRA_LIBS ${COREFOUNDATION_LIBRARY})
endif(APPLE)

# create your executable with
add_executable(${PROJECT_NAME} ${GUI_TYPE} ${SOURCES})

add_dependencies(${PROJECT_NAME} shaders_out)

# create a library with
# add_library(my_lib SHARED ${SOURCES})

if (NOT EMSCRIPTEN)
  target_link_libraries(${PROJECT_NAME}
    m
    ${OPENGL_gl_LIBRARY}
    ${GLEW_LIBRARIES}
    ${GLFW_STATIC_LIBRARIES} # This needs manual addition of ${GLFW_STATIC_LDFLAGS}
    ${EXTRA_LIBS}
  )
string(REPLACE ";" " " glfw_static_ldflags "${GLFW_STATIC_LDFLAGS}")
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS "${glfw_static_ldflags}")
endif()

if(EMSCRIPTEN)
  set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
  set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1")
endif()

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

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})

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
