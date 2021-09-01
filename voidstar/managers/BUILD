load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "manager",
    srcs = ["manager.cc"],
    hdrs = [
        "events.h",
        "manager.h",
    ],
    copts = COPTS,
    deps = [
        "//voidstar:arguments",
        "//voidstar:framework",
        "//voidstar/scenes:scene",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "managers",
    copts = COPTS,
    deps = [
        ":manager_glfw3",
    ],
)

cc_library(
    name = "manager_glfw3",
    srcs = ["glfw3.cc"],
    hdrs = ["glfw3.h"],
    copts = COPTS,
    deps = [
        ":manager",
        "//third_party:glew",
        "//third_party:glfw",
        "@glm",
        "@khronos_opengl_registry//:gl_headers",
    ],
    alwayslink = 1,  # For registration
)
