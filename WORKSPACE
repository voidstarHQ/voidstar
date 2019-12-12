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

http_archive(
    name = "rules_cc",
    # sha256 = "a5a6362ad8e45bbac01388c17d273f625b7916621e10e535b4a2eea3bc62a5ae",
    strip_prefix = "rules_cc-master",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/master.zip"],
)

# Khronos GL headers.
http_archive(
    name = "khronos_opengl_registry",
    build_file = "@//third_party:gl.BUILD",
    # sha256 = "a87f57e456a5fae6c0d60222b84d3db4a2f57574e449d04dfa3b65198991f5b3",
    strip_prefix = "OpenGL-Registry-master",
    urls = ["https://github.com/KhronosGroup/OpenGL-Registry/archive/master.zip"],
)

http_archive(
    name = "glfw",
    build_file = "@//third_party:glfw.BUILD",
    strip_prefix = "glfw-3.3",
    urls = ["https://github.com/glfw/glfw/archive/3.3.zip"],
    sha256 = "1092f6815d1f6d1f67479d2dad6057172b471122d911e7a7ea2be120956ffaa4",
    # 3.3 contains https://github.com/glfw/glfw/commit/a397195d3fd14b3e94026bce684e6b5f392f5015
    # strip_prefix = "glfw-a397195d3fd14b3e94026bce684e6b5f392f5015",
    # urls = ["https://github.com/glfw/glfw/archive/a397195d3fd14b3e94026bce684e6b5f392f5015.tar.gz"],
    # sha256 = "72ca890717a17caac274beee7ae326f32301e89ca7fa645eb446d3d49a9ffd60",
)
