package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "simple",
    srcs = ["glfwSample.cc"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_binary(
    name = "tri",
    srcs = ["hello_triangle.cc"],
    linkopts = ["-lGLEW"],
    deps = [
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
