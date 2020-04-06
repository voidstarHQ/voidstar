load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

config_setting(
    name = "linux",
    constraint_values = ["@bazel_tools//platforms:linux"],
)

config_setting(
    name = "osx",
    constraint_values = ["@bazel_tools//platforms:osx"],
)

config_setting(
    name = "windows",
    constraint_values = ["@bazel_tools//platforms:windows"],
)

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
        ":linux": ["-lGL"],
        ":osx": ["-framework OpenGL"],
    }),
    visibility = ["//visibility:public"],
)
