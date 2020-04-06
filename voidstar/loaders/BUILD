load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "loader",
    srcs = ["loader.cc"],
    hdrs = [
        "loader.h",
        "uri.h",
    ],
    deps = ["//voidstar:framework"],
    alwayslink = 1,  # For registration
)

config_setting(
    name = "windows",
    constraint_values = ["@bazel_tools//platforms:windows"],
)

LOADERS = [
    "fd",
    "file",
    "mmap",
]

cc_library(
    name = "loaders",
    deps = select({
        ":windows": [
            ":loader_fd",
            ":loader_file",
            # ":loader_mmap", # TODO
        ],
        "//conditions:default": [
            ":loader_fd",
            ":loader_file",
            ":loader_mmap",
        ],
    }),
)

[
    cc_library(
        name = "loader_" + loader,
        srcs = [loader + ".cc"],
        deps = [":loader"],
        alwayslink = 1,  # For registration
    )
    for loader in LOADERS
]
