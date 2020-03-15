workspace(name = "voidstar")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

load("@bazel_skylib//lib:versions.bzl", "versions")

versions.check(minimum_bazel_version = "0.24.1")

# 2020-03-12
rules_cc = "34ca16f4aa4bf2a5d3e4747229202d6cb630ebab"

http_archive(
    name = "rules_cc",
    sha256 = "523c59bb3f16518679668594c8874da46872fde05c32ba246bc0a35ec292f8a6",
    strip_prefix = "rules_cc-{}".format(rules_cc),
    urls = ["https://github.com/bazelbuild/rules_cc/archive/{}.zip".format(rules_cc)],
)

# Khronos GL headers.
# 2020-03-13
khronos_opengl_registry = "2313103f76edbe9023a3df74de978f90200bd87c"

http_archive(
    name = "khronos_opengl_registry",
    build_file = "@//third_party:gl.BUILD",
    sha256 = "f4bf3f56433fcba5f6a0ec6a8a2f875a036fe250aab3e8b7b7eab1bd46484330",
    strip_prefix = "OpenGL-Registry-{}".format(khronos_opengl_registry),
    urls = ["https://github.com/KhronosGroup/OpenGL-Registry/archive/{}.zip".format(khronos_opengl_registry)],
)

http_archive(
    name = "glfw",
    build_file = "@//third_party:glfw.BUILD",
    sha256 = "1092f6815d1f6d1f67479d2dad6057172b471122d911e7a7ea2be120956ffaa4",
    strip_prefix = "glfw-3.3",
    urls = ["https://github.com/glfw/glfw/archive/3.3.zip"],
)
