load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

config_setting(
    name = "linux",
    constraint_values = ["@platforms//os:linux"],
)

config_setting(
    name = "osx",
    constraint_values = ["@platforms//os:osx"],
)

config_setting(
    name = "windows",
    constraint_values = ["@platforms//os:windows"],
)

cc_library(
    name = "glfw",
    deps = select({
        ":linux": ["@glfw//:glfw_linux"],
        ":osx": ["@glfw_osx"],
        ":windows": ["@glfw//:glfw_windows"],
    }),
)

cc_library(
    name = "glew",
    deps = select({
        ":windows": ["@glew_win64//:glew_win64"],
        "//conditions:default": ["@glew//:glew"],
    }),
)

cc_library(
    name = "mman",
    deps = select({
        ":windows": ["@mman_win32//:mman_win32"],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "getopt",
    deps = select({
        ":windows": ["@getopt//:getopt"],
        "//conditions:default": [],
    }),
)
