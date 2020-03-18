package(default_visibility = ["//visibility:public"])

cc_library(
    name = "gl_headers",
    hdrs = glob(["api/GL/*.h"]),
    # Allows short paths like #include <GL/gl.h>.
    strip_include_prefix = "api",
)
