load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

package(default_visibility = ["//visibility:public"])

GLSLs = [glsl.replace(".glsl", "") for glsl in glob(["*.glsl"])]

[
    [
        genrule(
            name = name,
            srcs = ["{}.glsl".format(name)],
            outs = ["{}.h".format(name)],
            cmd = './$(location glsl2h.sh) "$<" "$@"',
            tools = ["glsl2h.sh"],
        ),
        cc_library(
            name = "shader__{}".format(name),
            hdrs = [":{}".format(name)],
            copts = COPTS,
        ),
    ]
    for name in GLSLs
]
