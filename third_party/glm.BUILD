load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:private"])

licenses(["notice"])  # MIT

cc_library(
    name = "glm",
    srcs = glob(["glm/**/*.cpp"]),
    hdrs = glob([
        "glm/**/*.h",
        "glm/**/*.hpp",
    ]),
    includes = ["."],
    textual_hdrs = glob(["glm/**/*.inl"]),
    visibility = ["//visibility:public"],
)
