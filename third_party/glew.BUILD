load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glew",
    srcs = ["src/glew.c"],
    hdrs = glob(["include/GL/*.h"]),
    defines = [
        "GLEW_NO_GLU",
        "GLEW_STATIC",
    ],
    includes = ["include"],
    linkopts = select({
        "@//third_party:linux": ["-lGL"],
        "@//third_party:osx": ["-framework OpenGL"],
    }),
    visibility = ["//visibility:public"],
)
