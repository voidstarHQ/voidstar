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
    name = "glfw",
    deps = select({
        ":linux": ["@glfw//:glfw_linux"],
        ":osx": ["@glfw_osx"],
        ":windows": ["@glfw//:glfw_windows"],
    }),
)
