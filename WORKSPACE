workspace(name = "voidstar")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_upgradable",
    strip_prefix = "bazel_upgradable-master",
    type = "zip",
    url = "https://github.com/fenollp/bazel_upgradable/archive/master.zip",
)

load("@bazel_upgradable//rules:github.bzl", "upgradable_github_archive")

upgradable_github_archive(
    name = "rules_cc",
    branch = "master",
    slug = "bazelbuild/rules_cc",
)

upgradable_github_archive(
    name = "khronos_opengl_registry",
    branch = "master",
    build_file = "@//third_party:gl.BUILD",
    slug = "KhronosGroup/OpenGL-Registry",
)

upgradable_github_archive(
    name = "glfw",
    branch = "master",
    build_file = "@//third_party:glfw3.BUILD",
    slug = "glfw/glfw",
)

upgradable_github_archive(
    name = "com_github_gtruc_glm",
    branch = "master",
    build_file = "@//third_party:glm.BUILD",
    slug = "g-truc/glm",
)
