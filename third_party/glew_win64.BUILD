load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glew_win64",
    # TODO? bin/Release/x64/glew32.dll
    srcs = glob(["lib/Release/x64/*.lib"]),
    hdrs = glob(["include/GL/*.h"]),
    defines = [
        "GLEW_NO_GLU",
        "GLEW_STATIC",
    ],
    includes = ["include"],
    visibility = ["//visibility:public"],
)
