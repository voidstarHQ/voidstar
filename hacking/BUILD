load("@rules_cc//cc:defs.bzl", "cc_binary")

package(default_visibility = ["//visibility:public"])

# For glfw3:
# sudo apt install libgl1-mesa-dev xorg-dev
# For glew:
# sudo apt install libglew-dev

cc_binary(
    name = "argh",
    srcs = ["argh.cc"],
    linkopts = ["-lGLEW"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
