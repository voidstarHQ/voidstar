load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO: simplify & update using https://raw.githubusercontent.com/pbellis/bazel-glfw/master/glfw.BUILD

# SRCS from https://github.com/glfw/glfw/blob/e65de2941c056ee5833b4dab3db36b297b53aa14/src/CMakeLists.txt

SRCS = [
    "src/context.c",
    "src/init.c",
    "src/input.c",
    "src/internal.h",
    "src/mappings.h",
    "src/monitor.c",
    "src/vulkan.c",
    "src/window.c",
]

SRCS_WIN32 = [
    "src/egl_context.c",
    "src/egl_context.h",
    "src/osmesa_context.c",
    "src/osmesa_context.h",
    "src/wgl_context.c",
    "src/wgl_context.h",
    "src/win32_init.c",
    "src/win32_joystick.c",
    "src/win32_joystick.h",
    "src/win32_monitor.c",
    "src/win32_platform.h",
    "src/win32_thread.c",
    "src/win32_time.c",
    "src/win32_window.c",
]

SRCS_X11 = [
    "src/egl_context.c",
    "src/egl_context.h",
    "src/glx_context.c",
    "src/glx_context.h",
    "src/osmesa_context.c",
    "src/osmesa_context.h",
    "src/posix_thread.c",
    "src/posix_thread.h",
    "src/posix_time.c",
    "src/posix_time.h",
    "src/x11_init.c",
    "src/x11_monitor.c",
    "src/x11_platform.h",
    "src/x11_window.c",
    "src/xkb_unicode.c",
    "src/xkb_unicode.h",
]

HDRS = [
    "include/GLFW/glfw3.h",
    "include/GLFW/glfw3native.h",
]

INCLUDES = [
    "include",
]

cc_library(
    name = "glfw_linux",
    srcs = SRCS + SRCS_X11 + [
        "src/linux_joystick.c",
        "src/linux_joystick.h",
    ],
    hdrs = HDRS,
    defines = [
        "_GLFW_X11",
        "_GLFW_GLX",
        "_GLFW_USE_OPENGL",
    ],
    includes = INCLUDES,
    linkopts = [
        # Note:  This is a bit of a HACK to build & link against whatever
        # version of X11 is installed on the system. Ideally, X11 would also
        # be built with bazel to ensure consistency.
        "-lX11",
        "-lXrandr",
        "-lXi",
        "-lXxf86vm",
        "-lGL",
        "-lXcursor",
        "-lpthread",
        "-lXinerama",
        "-ldl",
    ],
)

cc_library(
    name = "glfw_windows",
    srcs = SRCS + SRCS_WIN32,
    hdrs = HDRS,
    defines = [
        "_GLFW_WIN32",
        "_GLFW_USE_OPENGL",
    ],
    includes = INCLUDES,
    linkopts = [
        "-DEFAULTLIB:opengl32.lib",
        "-DEFAULTLIB:gdi32.lib",
        "-DEFAULTLIB:user32.lib",
        "-DEFAULTLIB:shell32.lib",
    ],
    # Note: the Bazel MSVC CROSSTOOL prevents including wingdi.h by default, to
    # prevent Windows macros from altering the global namespace. Glfw is set up
    # to carefully handle these headers.
    # FIXME: commented out due to:
    # in nocopts attribute of cc_library rule @glfw//:glfw_windows: This attribute was removed. See https://github.com/bazelbuild/bazel/issues/8706 for details.
    # nocopts = "/DNOGDI",
    deps = ["@khronos_opengl_registry//:gl_headers"],
)
