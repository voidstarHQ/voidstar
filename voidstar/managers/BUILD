package(default_visibility = ["//visibility:public"])

# TODO: third_party GLM
# sudo apt install libglm-dev

cc_binary(
    name = "voidstar",
    srcs = [        "main.cc",    ],
    linkopts = ["-lGLEW"],
    deps = [
        "//voidstar/include:headers",
        "//voidstar/shaders:shader__fragment",
        "//voidstar/shaders:shader__vertex_2d",
        "//voidstar/shaders:shader__vertex_3d",
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
