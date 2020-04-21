load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "voidstar",
    srcs = ["main.cc"],
    deps = [
        "//voidstar/loaders",
        "//voidstar/managers",
        "//voidstar/scenes",
    ],
)

cc_library(
    name = "framework",
    srcs = [
        "size2str.cc",
    ],
    hdrs = [
        "registrar.h",
        "size2str.h",
        "types.h",
    ],
    deps = [":indices"],
)

cc_library(
    name = "indices",
    hdrs = ["indices.h"],
    deps = ["//third_party:glew"],
)

cc_library(
    name = "arguments",
    srcs = ["arguments.cc"],
    hdrs = ["arguments.h"],
    deps = [":framework"],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "algorithm",
    srcs = ["algorithm.cc"],
    hdrs = [
        "algorithm.h",
        "data_range.h",
    ],
    deps = [
        ":arguments",
        ":framework",
        "//voidstar/loaders",
    ],
    alwayslink = 1,  # For registration
)
