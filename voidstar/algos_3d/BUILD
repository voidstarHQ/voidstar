load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "algo_3d",
    hdrs = ["algo_3d.h"],
    copts = COPTS,
    deps = [
        "//voidstar:algorithm",
        "//voidstar:arguments",
    ],
)

CUBES = [
    "cube_conti_bnw",
    "cube_conti_frebet",
    "cube_conti_rainbow",
    "cube_full",
]

SPHERES = [
    "sphere_conti_bnw",
    "sphere_conti_frebet",
    "sphere_conti_rainbow",
    "sphere_full",
]

cc_library(
    name = "algos_3d",
    copts = COPTS,
    deps = [":" + algo for algo in CUBES + SPHERES],
)

[
    cc_library(
        name = algo,
        srcs = [algo + ".cc"],
        copts = COPTS,
        deps = [
            ":algo_3d",
            ":cube",
        ],
        alwayslink = 1,  # For registration
    )
    for algo in CUBES
]

cc_library(
    name = "cube",
    hdrs = ["cube.h"],
    copts = COPTS,
)

[
    cc_library(
        name = algo,
        srcs = [algo + ".cc"],
        copts = COPTS,
        deps = [
            ":algo_3d",
            ":sphere",
        ],
        alwayslink = 1,  # For registration
    )
    for algo in SPHERES
]

cc_library(
    name = "sphere",
    hdrs = ["sphere.h"],
    copts = COPTS,
)
