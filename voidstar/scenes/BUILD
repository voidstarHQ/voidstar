load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "scene",
    srcs = ["scene.cc"],
    hdrs = ["scene.h"],
    copts = COPTS,
    deps = [
        "//voidstar:algorithm",
        "//voidstar:arguments",
        "//voidstar:framework",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "scenes",
    copts = COPTS,
    deps = [
        ":scene_2d",
        ":scene_3d",
    ],
)

cc_library(
    name = "scene_2d",
    srcs = ["2d.cc"],
    copts = COPTS,
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
    copts = COPTS,
    deps = [
        ":scene",
        "//voidstar/algos_3d",
        "//voidstar/shaders:shader__fragment",
        "//voidstar/shaders:shader__vertex_3d",
    ],
    alwayslink = 1,  # For registration
)
