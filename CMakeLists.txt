cmake_minimum_required(VERSION 3.10)

# set cmake module path, to search in cmake/modules first
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

#                               MODULES

include(static_analysis)
#include(doxygen)
#include(ccache)

#                           GENERAL CONFIGURATION

set(PROJECT_NAME voidstar)
project(${PROJECT_NAME} CXX)

set(CMAKE_VERBOSE_MAKEFILE 1)
set(APP_VERSION_MAJOR 1)

#                           BUILD TYPES & FLAGS

include(sanitizers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
else (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
endif()

# strip binary for release builds
if (CMAKE_BUILD_TYPE STREQUAL Release)
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_STRIP} ${PROJECT_NAME})
endif ()

#                               SOURCES

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
    src/FdLoader.cc
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

# create your executable with
add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} shaders_out)

# create a library with
# add_library(my_lib SHARED ${SOURCES})

#                              DEPENDENCIES

# find your dependencies here !
# ==> use cmake --help-module-list
# ==> and cmake --help-module FindBoost to known which variables are set.
# find_package(Boost COMPONENTS filesystem threads)
# include_directories(${Boost_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
add_dependencies(${PROJECT_NAME} OpenGL::OpenGL)

message(STATUS "OPENGL_INCLUDE_DIRS ${OPENGL_INCLUDE_DIRS}")
message(STATUS "GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIRS}")
message(STATUS "GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR}")

message(STATUS "OPENGL_FOUND ${OPENGL_FOUND}")
message(STATUS "OPENGL_XMESA_FOUND ${OPENGL_XMESA_FOUND}")
message(STATUS "OPENGL_GLU_FOUND ${OPENGL_GLU_FOUND}")
message(STATUS "OpenGL_OpenGL_FOUND ${OpenGL_OpenGL_FOUND}")
message(STATUS "OpenGL_GLX_FOUND ${OpenGL_GLX_FOUND}")
message(STATUS "OpenGL_EGL_FOUND ${OpenGL_EGL_FOUND}")
message(STATUS "OPENGL_INCLUDE_DIR ${OPENGL_INCLUDE_DIR}")
message(STATUS "OPENGL_EGL_INCLUDE_DIRS ${OPENGL_EGL_INCLUDE_DIRS}")
message(STATUS "OPENGL_LIBRARIES ${OPENGL_LIBRARIES}")

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

if (APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    set(EXTRA_LIBS
      ${COCOA_LIBRARY}
      ${OpenGL_LIBRARY}
      ${IOKIT_LIBRARY}
      ${COREVIDEO_LIBRARY}
      )
endif (APPLE)

if (WIN32)
# nothing now
endif (WIN32)

# you can link both with
target_link_libraries(${PROJECT_NAME}
  m
  glfw
  OpenGL::OpenGL
  ${GLEW_LIBRARIES}
  ${EXTRA_LIBS}
  )

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
