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

LOADERS = [
    "fd",
    "file",
    "mmap",
]

cc_library(
    name = "loaders",
    deps = [":loader_" + loader for loader in LOADERS],
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
