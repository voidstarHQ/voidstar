load("@rules_cc//cc:defs.bzl", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "argh",
    srcs = ["argh.cc"],
    deps = [
        "@glew",
        "@glfw",
        "@glm",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
