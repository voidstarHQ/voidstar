load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "voidstar",
    srcs = ["main.cc"],
    copts = COPTS,
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
        "flags.h",
        "registrar.h",
        "size2str.h",
        "types.h",
    ],
    copts = COPTS,
    deps = [
        ":indices",
        "@fmt",
    ],
)

cc_library(
    name = "indices",
    hdrs = ["indices.h"],
    copts = COPTS,
    deps = ["//third_party:glew"],
)

cc_library(
    name = "arguments",
    srcs = ["arguments.cc"],
    hdrs = ["arguments.h"],
    copts = COPTS,
    deps = [
        ":framework",
        "//third_party:getopt",
    ],
    alwayslink = 1,  # For registration
)

cc_library(
    name = "algorithm",
    srcs = ["algorithm.cc"],
    hdrs = [
        "algorithm.h",
        "data_range.h",
    ],
    copts = COPTS,
    deps = [
        ":arguments",
        ":framework",
        "//voidstar/loaders",
    ],
    alwayslink = 1,  # For registration
)
