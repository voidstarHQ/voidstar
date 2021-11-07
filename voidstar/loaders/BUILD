load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "loader",
    srcs = ["loader.cc"],
    hdrs = [
        "loader.h",
        "uri.h",
    ],
    copts = COPTS,
    deps = ["//voidstar:framework"],
    alwayslink = 1,  # For registration
)

LOADERS = {
    "fd": [],
    "file": [],
    "mmap": ["//third_party:mman"],
}

cc_library(
    name = "loaders",
    copts = COPTS,
    deps = [":loader_" + loader for loader in LOADERS],
)

[
    cc_library(
        name = "loader_" + loader,
        srcs = [loader + ".cc"],
        copts = COPTS,
        deps = [":loader"] + deps,
        alwayslink = 1,  # For registration
    )
    for loader, deps in LOADERS.items()
]
