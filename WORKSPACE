workspace(name = "voidstar")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_upgradable",
    strip_prefix = "bazel_upgradable-0.1.1",
    url = "https://github.com/fenollp/bazel_upgradable/archive/0.1.1.zip",
)

load("@bazel_upgradable//:rule.bzl", "upgradable_repository")

upgradable_repository(
    name = "rules_cc",
    remote = "git://github.com/bazelbuild/rules_cc.git",
)

upgradable_repository(
    name = "khronos_opengl_registry",
    build_file = "@//third_party:gl.BUILD",
    remote = "git://github.com/KhronosGroup/OpenGL-Registry.git",
)

upgradable_repository(
    name = "glfw",
    build_file = "@//third_party:glfw3.BUILD",
    remote = "git://github.com/glfw/glfw.git",
)

upgradable_repository(
    name = "glfw_osx",
    build_file = "@//third_party:glfw3_osx.BUILD",
    release = "glfw-{tag_digits}.bin.MACOS.zip",
    remote = "git://github.com/glfw/glfw.git",
    tag = "~3",
)

upgradable_repository(
    name = "glm",
    build_file = "@//third_party:glm.BUILD",
    remote = "git://github.com/g-truc/glm.git",
)

glew_version_constraint = "<=2"

upgradable_repository(
    name = "glew",
    build_file = "@//third_party:glew.BUILD",
    release = "{tag}.tgz",
    remote = "git://github.com/nigels-com/glew.git",
    strip_prefix = "glew-{tag_digits}",
    tag = glew_version_constraint,
    type = "tar.gz",
)

upgradable_repository(
    name = "glew_win64",
    build_file = "@//third_party:glew_win64.BUILD",
    release = "{tag}-win32.zip",
    remote = "git://github.com/nigels-com/glew.git",
    strip_prefix = "glew-{tag_digits}",
    tag = glew_version_constraint,
)
