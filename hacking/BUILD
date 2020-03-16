package(default_visibility = ["//visibility:public"])

# For glfw3:
# sudo apt install libgl1-mesa-dev xorg-dev
# For glew:
# sudo apt install libglew-dev

cc_binary(
    name = "simple",
    srcs = ["simple.cc"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_binary(
    name = "sample",
    srcs = ["sample.cc"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_binary(
    name = "tri",
    srcs = ["tri.cc"],
    linkopts = ["-lGLEW"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_binary(
    name = "argh",
    srcs = ["argh.cc"],
    linkopts = ["-lGLEW"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_binary(
    name = "elem",
    srcs = ["elem.cc"],
    # linkopts = ["-lGLEW"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
