load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glfw_osx",
    srcs = glob([
        "lib-macos/libglfw3.a",  # Up to 3.3.2
        "lib-x86_64/libglfw3.a", # Since 3.3.3
    ]),
    hdrs = [
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h",
    ],
    defines = [
        "_GLFW_COCOA",
        # "_GLFW_GLX",
        # "_GLFW_USE_OPENGL",
    ],
    includes = ["include"],
    linkopts = [
        "-framework Cocoa",
        "-framework IOKit",
        "-framework CoreFoundation",
    ],
)
