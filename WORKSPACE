workspace(name = "voidstar")

load("@bazel_tools//tools/build_defs/repo:http.bzl", bare_http_archive = "http_archive")

bare_http_archive(
    name = "bazel_lock",
    # Locked on 2020-04-04
    sha256 = "ce1a1c3753b970419c8d5ea3e5afbc24ad62beacbb32c48672186c78411540f8",
    strip_prefix = "bazel_lock-081217b3d17d9a8a817eb8fd4ec6058145126a2c",
    type = "zip",
    url = "https://github.com/fenollp/bazel_lock/archive/081217b3d17d9a8a817eb8fd4ec6058145126a2c.zip",
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
