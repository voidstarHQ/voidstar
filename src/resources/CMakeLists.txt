add_custom_command(
  OUTPUT
    shaders.hh
    cache-buster.h # ensure this always runs
  COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/pack_GLSLs.sh ${CMAKE_CURRENT_BINARY_DIR}/shaders.hh
)

set(GENERATED_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target(shaders_out DEPENDS shaders.hh)
