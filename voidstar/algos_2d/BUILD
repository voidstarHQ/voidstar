load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "algo_2d",
    hdrs = ["algo_2d.h"],
    copts = COPTS,
    deps = [
        "//voidstar:algorithm",
        "//voidstar:arguments",
    ],
)

ALGOS = [
    "4col",
    "entropy",
    "gray",
]

cc_library(
    name = "algos_2d",
    copts = COPTS,
    deps = [":" + algo for algo in ALGOS],
)

[
    cc_library(
        name = algo,
        srcs = [algo + ".cc"],
        copts = COPTS,
        deps = [":algo_2d"],
        alwayslink = 1,  # For registration
    )
    for algo in ALGOS
]
