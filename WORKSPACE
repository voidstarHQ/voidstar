workspace(name = "voidstar")

local_repository(
    name = "bazel_lock",
    path = "../bazel_lock.git",
)

load("@bazel_lock//rules:locked.bzl", "http_archive")
load("//:LOCKFILE.bzl", "locked")

http_archive(
    name = "bazel_skylib",
    locked = locked,
    type = "zip",
    upgrades_slug = "github.com/bazelbuild/bazel-skylib",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

load("@bazel_skylib//lib:versions.bzl", "versions")

versions.check(minimum_bazel_version = "0.24.1")

http_archive(
    name = "rules_cc",
    locked = locked,
    type = "zip",
    upgrades_slug = "github.com/bazelbuild/rules_cc",
)

http_archive(
    name = "khronos_opengl_registry",
    build_file = "@//third_party:gl.BUILD",
    locked = locked,
    type = "tar.gz",
    upgrades_slug = "github.com/KhronosGroup/OpenGL-Registry",
)

http_archive(
    name = "glfw",
    build_file = "@//third_party:glfw3.BUILD",
    locked = locked,
    type = "zip",
    upgrades_slug = "github.com/glfw/glfw",
)

http_archive(
    name = "com_github_gtruc_glm",
    build_file = "@//third_party:glm.BUILD",
    locked = locked,
    type = "zip",
    upgrades_slug = "github.com/g-truc/glm",
)
