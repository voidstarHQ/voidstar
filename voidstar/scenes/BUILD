load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "scene",
    srcs = ["scene.cc"],
    hdrs = ["scene.h"],
    deps = [
        "//voidstar:algorithm",
        "//voidstar:arguments",
        "//voidstar:framework",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "scenes",
    deps = [
        ":scene_2d",
        ":scene_3d",
    ],
)

cc_library(
    name = "scene_2d",
    srcs = ["2d.cc"],
    deps = [
        ":scene",
        "//voidstar/algos_2d",
        "//voidstar/shaders:shader__fragment",
        "//voidstar/shaders:shader__vertex_2d",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "scene_3d",
    srcs = ["3d.cc"],
    deps = [
        ":scene",
        "//voidstar/algos_3d",
        "//voidstar/shaders:shader__fragment",
        "//voidstar/shaders:shader__vertex_3d",
    ],
    alwayslink = 1,  # For registration
)
