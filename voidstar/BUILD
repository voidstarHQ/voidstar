package(default_visibility = ["//visibility:public"])

# TODO: third_party GLM
# sudo apt install libglm-dev

cc_binary(
    name = "voidstar",
    srcs = [
        "Algo2DEntropy.cc",
        "Algo2DFourColors.cc",
        "Algo2DGrayscale.cc",
        "Algo3DCubeContiBnW.cc",
        "Algo3DCubeContiFrebet.cc",
        "Algo3DCubeContiRainbow.cc",
        "Algo3DCubeFull.cc",
        "Algo3DSphereContiBnW.cc",
        "Algo3DSphereContiFrebet.cc",
        "Algo3DSphereContiRainbow.cc",
        "Algo3DSphereFull.cc",
        "Algorithm.cc",
        "Arguments.cc",
        "FdLoader.cc",
        "FileLoader.cc",
        "GlfwManager.cc",
        "Loader.cc",
        "Manager.cc",
        "MmapLoader.cc",
        "Scene.cc",
        "Scene2D.cc",
        "Scene3D.cc",
        "main.cc",
    ],
    linkopts = ["-lGLEW"],
    deps = [
        "//src/include:headers",
        "//src/shaders:shader__fragment",
        "//src/shaders:shader__vertex_2d",
        "//src/shaders:shader__vertex_3d",
        "@glfw",
        "@khronos_opengl_registry//:gl_headers",
    ],
)
