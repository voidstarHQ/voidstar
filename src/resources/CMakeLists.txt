# https://github.com/tmpvar/voxviz/blob/fca77c586fc4b682d9a66bb271ea920c0d71963c/shaders/CMakeLists.txt
add_custom_command(
  OUTPUT
    shaders.hh
    cache-buster.h # ensure this always runs
  COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/pack_GLSLs.sh ${CMAKE_CURRENT_BINARY_DIR}/shaders.hh
)

set(GENERATED_HEADER_DIR ${CMAKE_CURRENT_BINARY_DIR})
# set_target_properties(<target> PROPERTIES INCLUDE_DIRECTORIES ${GENERATED_HEADER_DIR)
add_custom_target(shaders_out DEPENDS shaders.hh)
