workspace(name = "voidstar")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_upgradable",
    strip_prefix = "bazel_upgradable-0.2.1",
    url = "https://github.com/fenollp/bazel_upgradable/archive/0.2.1.zip",
)

load("@bazel_upgradable//:rule.bzl", "upgradable_repository")

upgradable_repository(
    name = "rules_cc",
    tag = "0.0.7",
    remote = "https://github.com/bazelbuild/rules_cc.git",
)

upgradable_repository(
    name = "khronos_opengl_registry",
    branch = "main",
    build_file = "@//third_party:gl.BUILD",
    remote = "https://github.com/KhronosGroup/OpenGL-Registry.git",
)

upgradable_repository(
    name = "glfw",
    branch = "3.3-stable",
    build_file = "@//third_party:glfw3.BUILD",
    remote = "https://github.com/glfw/glfw.git",
)

upgradable_repository(
    name = "glfw_osx",
    build_file = "@//third_party:glfw3_osx.BUILD",
    release = "glfw-{tag_digits}.bin.MACOS.zip",
    remote = "https://github.com/glfw/glfw.git",
    strip_prefix = "glfw-{tag_digits}.bin.MACOS",
    tag = "~3",
)

upgradable_repository(
    name = "glm",
    build_file = "@//third_party:glm.BUILD",
    remote = "https://github.com/g-truc/glm.git",
)

glew_version_constraint = "<=2"

upgradable_repository(
    name = "glew",
    build_file = "@//third_party:glew.BUILD",
    release = "{tag}.tgz",
    remote = "https://github.com/nigels-com/glew.git",
    strip_prefix = "glew-{tag_digits}",
    tag = glew_version_constraint,
    type = "tar.gz",
)

upgradable_repository(
    name = "glew_win64",
    build_file = "@//third_party:glew_win64.BUILD",
    release = "{tag}-win32.zip",
    remote = "https://github.com/nigels-com/glew.git",
    strip_prefix = "glew-{tag_digits}",
    tag = glew_version_constraint,
)

upgradable_repository(
    name = "mman_win32",
    build_file = "@//third_party:mman_win32.BUILD",
    remote = "https://github.com/klauspost/mman-win32.git",
)

upgradable_repository(
    name = "getopt",
    build_file = "@//third_party:getopt.BUILD",
    remote = "https://github.com/skandhurkat/Getopt-for-Visual-Studio.git",
)

# From https://github.com/fmtlib/fmt/blob/1b193e7b3716f57d64fa2f98275eb1395fea4eff/support/bazel/README.md

upgradable_repository(
    name = "fmt",
    patch_cmds = [
        "mv support/bazel/.bazelrc .bazelrc",
        "mv support/bazel/.bazelversion .bazelversion",
        "mv support/bazel/BUILD.bazel BUILD.bazel",
        "mv support/bazel/WORKSPACE.bazel WORKSPACE.bazel",
    ],
    # Windows-related patch commands are only needed in the case MSYS2 is not installed.
    # More details about the installation process of MSYS2 on Windows systems can be found here:
    # https://docs.bazel.build/versions/main/install-windows.html#installing-compilers-and-language-runtimes
    # Even if MSYS2 is installed the Windows related patch commands can still be used.
    patch_cmds_win = [
        "Move-Item -Path support/bazel/.bazelrc -Destination .bazelrc",
        "Move-Item -Path support/bazel/.bazelversion -Destination .bazelversion",
        "Move-Item -Path support/bazel/BUILD.bazel -Destination BUILD.bazel",
        "Move-Item -Path support/bazel/WORKSPACE.bazel -Destination WORKSPACE.bazel",
    ],
    remote = "https://github.com/fmtlib/fmt.git",
    tag = "~8",
)
