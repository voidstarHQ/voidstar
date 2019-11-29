package(default_visibility = ["//visibility:public"])

config_setting(
    name = "linux",
    constraint_values = ["@bazel_tools//platforms:linux"],
)

config_setting(
    name = "macos",
    constraint_values = ["@bazel_tools//platforms:macos"],
)

config_setting(
    name = "windows",
    constraint_values = ["@bazel_tools//platforms:windows"],
)

cc_library(
    name = "glfw_linux",
    srcs = glob([
        "src/context.c",
        "src/egl_context.c",
        "src/egl_context.h",
        "src/glfw_config.h",
        "src/glx_context.c",
        "src/glx_context.h",
        "src/init.c",
        "src/input.c",
        "src/internal.h",
        "src/linux_joystick.c",
        "src/linux_joystick.h",
        "src/mappings.h",
        "src/monitor.c",
        "src/osmesa_context.c",
        "src/osmesa_context.h",
        "src/posix_time.c",
        "src/posix_time.h",
        "src/posix_thread.c",
        "src/posix_thread.h",
        "src/posix_tls.c",
        "src/posix_tls.h",
        "src/vulkan.c",
        "src/window.c",
        "src/x11_init.c",
        "src/x11_monitor.c",
        "src/x11_platform.h",
        "src/x11_window.c",
        "src/xkb_unicode.c",
        "src/xkb_unicode.h",
    ]),
    hdrs = [
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h",
    ],
    copts = [
        "-I/usr/include",
    ],
    defines = [
        "_GLFW_X11",
        "_GLFW_GLX",
        "_GLFW_USE_OPENGL",
    ],
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
    srcs = glob([
        "src/context.c",
        "src/egl_context.c",
        "src/egl_context.h",
        "src/glfw_config.h",
        "src/init.c",
        "src/input.c",
        "src/internal.h",
        "src/monitor.c",
        "src/vulkan.c",
        "src/window.c",
        "src/wgl_context.c",
        "src/wgl_context.h",
        "src/win32_init.c",
        "src/win32_joystick.c",
        "src/win32_joystick.h",
        "src/win32_monitor.c",
        "src/win32_platform.h",
        "src/win32_time.c",
        "src/win32_time.h",
        "src/win32_tls.c",
        "src/win32_tls.h",
        "src/win32_window.c",
        "src/win32_unicode.c",
        "src/win32_unicode.h",
    ]),
    hdrs = [
        "include/GLFW/glfw3.h",
        "include/GLFW/glfw3native.h",
    ],
    defines = [
        "_GLFW_WIN32",
        "_GLFW_USE_OPENGL",
    ],
    linkopts = [
        "-DEFAULTLIB:opengl32.lib",
        "-DEFAULTLIB:gdi32.lib",
        "-DEFAULTLIB:user32.lib",
        "-DEFAULTLIB:shell32.lib",
    ],
    # Note: the Bazel MSVC CROSSTOOL prevents including wingdi.h by default, to
    # prevent Windows macros from altering the global namespace. Glfw is set up
    # to carefully handle these headers.
    nocopts = "/DNOGDI",
    deps = [
        "@khronos_opengl_registry//:gl_headers",
    ],
)

cc_library(
    name = "glfw",
    deps = select({
        ":linux": [":glfw_linux"],
        ":windows": [":glfw_windows"],
    }),
)
