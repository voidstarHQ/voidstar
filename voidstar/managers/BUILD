load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "manager",
    srcs = ["manager.cc"],
    hdrs = [
        "events.h",
        "manager.h",
    ],
    deps = [
        "//voidstar:arguments",
        "//voidstar:framework",
        "//voidstar/scenes:scene",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "managers",
    deps = [
        ":manager_glfw3",
    ],
)

cc_library(
    name = "manager_glfw3",
    srcs = ["glfw3.cc"],
    hdrs = ["glfw3.h"],
    deps = [
        ":manager",
        "@glm",
        "@glew",
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
    alwayslink = 1,  # For registration
)
