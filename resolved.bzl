resolved = [
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/crosstool",
            "actual": "@bazel_tools//tools/cpp:toolchain",
        },
        "native": "bind(name = \"android/crosstool\", actual = \"@bazel_tools//tools/cpp:toolchain\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/d8_jar_import",
            "actual": "@bazel_tools//tools/android:no_android_sdk_repository_error",
        },
        "native": "bind(name = \"android/d8_jar_import\", actual = \"@bazel_tools//tools/android:no_android_sdk_repository_error\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/dx_jar_import",
            "actual": "@bazel_tools//tools/android:no_android_sdk_repository_error",
        },
        "native": "bind(name = \"android/dx_jar_import\", actual = \"@bazel_tools//tools/android:no_android_sdk_repository_error\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/sdk",
            "actual": "@bazel_tools//tools/android:poison_pill_android_sdk",
        },
        "native": "bind(name = \"android/sdk\", actual = \"@bazel_tools//tools/android:poison_pill_android_sdk\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android_ndk_for_testing",
            "actual": "//:dummy",
        },
        "native": "bind(name = \"android_ndk_for_testing\", actual = \"//:dummy\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android_sdk_for_testing",
            "actual": "//:dummy",
        },
        "native": "bind(name = \"android_sdk_for_testing\", actual = \"//:dummy\")",
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "bazel_tools",
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/34c2b2925d29f26adbd2afb9a2ac4610/embedded_tools",
        },
        "native": "local_repository(name = \"bazel_tools\", path = __embedded_dir__ + \"/\" + \"embedded_tools\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "cc_toolchain",
            "actual": "@local_config_cc//:toolchain",
        },
        "native": "bind(name = \"cc_toolchain\", actual = \"@local_config_cc//:toolchain\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "databinding_annotation_processor",
            "actual": "@bazel_tools//tools/android:empty",
        },
        "native": "bind(name = \"databinding_annotation_processor\", actual = \"@bazel_tools//tools/android:empty\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "has_androidsdk",
            "actual": "@bazel_tools//tools/android:always_false",
        },
        "native": "bind(name = \"has_androidsdk\", actual = \"@bazel_tools//tools/android:always_false\")",
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "voidstar",
            "path": ".",
        },
        "native": "local_repository(name = \"voidstar\", path = \".\")",
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "bazel_upgradable",
            "url": "https://github.com/fenollp/bazel_upgradable/archive/0.2.0.zip",
            "strip_prefix": "bazel_upgradable-0.2.0",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://github.com/fenollp/bazel_upgradable/archive/0.2.0.zip",
                    "urls": [],
                    "sha256": "4cf493b0edf63c59360d44b2e0f69112529866083dd9d87814062f9f2ae03395",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "bazel_upgradable-0.2.0",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "bazel_upgradable",
                },
                "output_tree_hash": "1ed7e3f71d59e11e36617360b75745f949c1a1aaf4848b6f297d9a85cff30fd4",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glew",
            "strip_prefix": "glew-{tag_digits}",
            "type": "tar.gz",
            "build_file": "//third_party:glew.BUILD",
            "release": "{tag}.tgz",
            "remote": "git://github.com/nigels-com/glew.git",
            "tag": "<=2",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/nigels-com/glew/releases/download/glew-2.1.0/glew-2.1.0.tgz",
                    ],
                    "sha256": "04de91e7e6763039bc11940095cd9c7f880baba82196a7765f727ac05a993c95",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glew-2.1.0",
                    "type": "tar.gz",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glew.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "{tag}.tgz",
                    "remote": "git://github.com/nigels-com/glew.git",
                    "tag": "<=2",
                    "name": "glew",
                },
                "output_tree_hash": "f79fc7ceaa4bad7e02da40557fa5e95882317ef0ea85453980050213771f1f5c",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glew_win64",
            "strip_prefix": "glew-{tag_digits}",
            "build_file": "//third_party:glew_win64.BUILD",
            "release": "{tag}-win32.zip",
            "remote": "git://github.com/nigels-com/glew.git",
            "tag": "<=2",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/nigels-com/glew/releases/download/glew-2.1.0/glew-2.1.0-win32.zip",
                    ],
                    "sha256": "80cfc88fd295426b49001a9dc521da793f8547ac10aebfc8bdc91ddc06c5566c",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glew-2.1.0",
                    "type": "zip",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glew_win64.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "{tag}-win32.zip",
                    "remote": "git://github.com/nigels-com/glew.git",
                    "tag": "<=2",
                    "name": "glew_win64",
                },
                "output_tree_hash": "73848204f8734716c63d44190227fa2285b74d830ea2ef7eb9db168949ac0cc4",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glfw",
            "build_file": "//third_party:glfw3.BUILD",
            "remote": "git://github.com/glfw/glfw.git",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/glfw/glfw/archive/a506a8dc73dca2d3e07068d02cd008cdf958a914.tar.gz",
                    ],
                    "sha256": "fd491fd8afbc7453a22c235d0107b334386fe869bf87214be44b3fe0b4a4333a",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glfw-a506a8dc73dca2d3e07068d02cd008cdf958a914",
                    "type": "tar.gz",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glfw3.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/glfw/glfw.git",
                    "tag": "",
                    "name": "glfw",
                },
                "output_tree_hash": "bd121f5022c324fa1d077ae797c825148e3ba00c53ff61c9e46a8d2aaa4663a6",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glfw_osx",
            "strip_prefix": "glfw-{tag_digits}.bin.MACOS",
            "build_file": "//third_party:glfw3_osx.BUILD",
            "release": "glfw-{tag_digits}.bin.MACOS.zip",
            "remote": "git://github.com/glfw/glfw.git",
            "tag": "~3",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.bin.MACOS.zip",
                    ],
                    "sha256": "e412c75f850c320192df491ec3bf623847fafa847b46ffd3bbd7478057148f5a",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glfw-3.3.2.bin.MACOS",
                    "type": "zip",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glfw3_osx.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "glfw-{tag_digits}.bin.MACOS.zip",
                    "remote": "git://github.com/glfw/glfw.git",
                    "tag": "~3",
                    "name": "glfw_osx",
                },
                "output_tree_hash": "1d14d142ffc28377df0e16987d269135c77bd9625053a8f9a8a10501c5236c69",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glm",
            "build_file": "//third_party:glm.BUILD",
            "remote": "git://github.com/g-truc/glm.git",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/g-truc/glm/archive/b3f87720261d623986f164b2a7f6a0a938430271.tar.gz",
                    ],
                    "sha256": "db66eca1a396bbb7c5e286b9fa84b7d82d9ba317968bbb316805f80f45ca0cd8",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glm-b3f87720261d623986f164b2a7f6a0a938430271",
                    "type": "tar.gz",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glm.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/g-truc/glm.git",
                    "tag": "",
                    "name": "glm",
                },
                "output_tree_hash": "0c43b44d04182236bd72686a79a5ef0d149543224c9c873bd117ef7e6f1b1320",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "khronos_opengl_registry",
            "build_file": "//third_party:gl.BUILD",
            "remote": "git://github.com/KhronosGroup/OpenGL-Registry.git",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/KhronosGroup/OpenGL-Registry/archive/9274192362a0ac6912fd27b0c8ff0559fc658e21.tar.gz",
                    ],
                    "sha256": "15388d0eff3b14e66775cf2d334a4e87a77abfc648b24f9a5d66d0a9ec2c3224",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "OpenGL-Registry-9274192362a0ac6912fd27b0c8ff0559fc658e21",
                    "type": "tar.gz",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:gl.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/KhronosGroup/OpenGL-Registry.git",
                    "tag": "",
                    "name": "khronos_opengl_registry",
                },
                "output_tree_hash": "a58531034f9b497e54f5e5580cbfa538303dbef84fe3286f686132992a2279ca",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "rules_cc",
            "remote": "git://github.com/bazelbuild/rules_cc.git",
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
                "attributes": {
                    "urls": [
                        "https://github.com/bazelbuild/rules_cc/archive/f055da4ff0cb2b3c73de1fe2f094ebdfb8b3acb9.tar.gz",
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_cc/archive/f055da4ff0cb2b3c73de1fe2f094ebdfb8b3acb9.tar.gz",
                    ],
                    "sha256": "ef20e1eddf4bf8cab6392bd2024dd4bb626d21d9f964079ed0e13809e01d60d9",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "rules_cc-f055da4ff0cb2b3c73de1fe2f094ebdfb8b3acb9",
                    "type": "tar.gz",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/bazelbuild/rules_cc.git",
                    "tag": "",
                    "name": "rules_cc",
                },
                "output_tree_hash": "bfe1267dcda4b5d2bf8b693873e97cbb107145f08333f9741ea99ef0e2dc877e",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_coverage_tools",
            "urls": [
                "https://mirror.bazel.build/bazel_coverage_output_generator/releases/coverage_output_generator-v2.3.zip",
            ],
            "sha256": "0d6f73ed76908d7ec2840edd765a264b34036e4e3ec1c21a00421770523bcb27",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_coverage_output_generator/releases/coverage_output_generator-v2.3.zip",
                    ],
                    "sha256": "0d6f73ed76908d7ec2840edd765a264b34036e4e3ec1c21a00421770523bcb27",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_coverage_tools",
                },
                "output_tree_hash": "2f8ffdc12df41a1693ac853688f4a2b74e5b183271bd538603608922d6843254",
            },
        ],
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "bootclasspath",
            "actual": "@local_jdk//:bootclasspath",
        },
        "native": "bind(name = \"bootclasspath\", actual = \"@local_jdk//:bootclasspath\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "extclasspath",
            "actual": "@local_jdk//:extdir",
        },
        "native": "bind(name = \"extclasspath\", actual = \"@local_jdk//:extdir\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "extdir",
            "actual": "@local_jdk//:extdir",
        },
        "native": "bind(name = \"extdir\", actual = \"@local_jdk//:extdir\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jar",
            "actual": "@local_jdk//:jar",
        },
        "native": "bind(name = \"jar\", actual = \"@local_jdk//:jar\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "java",
            "actual": "@local_jdk//:java",
        },
        "native": "bind(name = \"java\", actual = \"@local_jdk//:java\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "javac",
            "actual": "@local_jdk//:javac",
        },
        "native": "bind(name = \"javac\", actual = \"@local_jdk//:javac\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jdk",
            "actual": "@local_jdk//:jdk",
        },
        "native": "bind(name = \"jdk\", actual = \"@local_jdk//:jdk\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jdk-default",
            "actual": "@local_jdk//:jdk",
        },
        "native": "bind(name = \"jdk-default\", actual = \"@local_jdk//:jdk\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_header",
            "actual": "@local_jdk//:jni_header",
        },
        "native": "bind(name = \"jni_header\", actual = \"@local_jdk//:jni_header\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-darwin",
            "actual": "@local_jdk//:jni_md_header-darwin",
        },
        "native": "bind(name = \"jni_md_header-darwin\", actual = \"@local_jdk//:jni_md_header-darwin\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-freebsd",
            "actual": "@local_jdk//:jni_md_header-freebsd",
        },
        "native": "bind(name = \"jni_md_header-freebsd\", actual = \"@local_jdk//:jni_md_header-freebsd\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-linux",
            "actual": "@local_jdk//:jni_md_header-linux",
        },
        "native": "bind(name = \"jni_md_header-linux\", actual = \"@local_jdk//:jni_md_header-linux\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-openbsd",
            "actual": "@local_jdk//:jni_md_header-openbsd",
        },
        "native": "bind(name = \"jni_md_header-openbsd\", actual = \"@local_jdk//:jni_md_header-openbsd\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jre",
            "actual": "@local_jdk//:jre",
        },
        "native": "bind(name = \"jre\", actual = \"@local_jdk//:jre\")",
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jre-default",
            "actual": "@local_jdk//:jre",
        },
        "native": "bind(name = \"jre-default\", actual = \"@local_jdk//:jre\")",
    },
    {
        "original_rule_class": "new_local_repository",
        "original_attributes": {
            "name": "local_jdk",
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/34c2b2925d29f26adbd2afb9a2ac4610/embedded_tools/tools/jdk/nosystemjdk",
            "build_file": "/home/pete/.cache/bazel/_bazel_pete/install/34c2b2925d29f26adbd2afb9a2ac4610/jdk.BUILD",
        },
        "native": "new_local_repository(name = \"local_jdk\", path = \"/home/pete/.cache/bazel/_bazel_pete/install/34c2b2925d29f26adbd2afb9a2ac4610/embedded_tools/tools/jdk/nosystemjdk\", build_file = __embedded_dir__ + \"/\" + \"jdk.BUILD\")",
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_darwin",
            "generator_name": "remote_java_tools_darwin",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_darwin-v9.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_darwin-v9.0.zip",
            ],
            "sha256": "567f5fe77e0c561b454930dea412899543849510f48f9c092dfcff8192b4086f",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_darwin-v9.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_darwin-v9.0.zip",
                    ],
                    "sha256": "567f5fe77e0c561b454930dea412899543849510f48f9c092dfcff8192b4086f",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_darwin",
                },
                "output_tree_hash": "56c05d5b80e79fbb317e6152b2e3a7ca05d5f277d0ce67af2c0c1ae278084e31",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_linux",
            "generator_name": "remote_java_tools_linux",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_linux-v9.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_linux-v9.0.zip",
            ],
            "sha256": "0be37f4227590ecb6bc929a6a7e427c65e6239363e4c3b28b1a211718b9636c9",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_linux-v9.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_linux-v9.0.zip",
                    ],
                    "sha256": "0be37f4227590ecb6bc929a6a7e427c65e6239363e4c3b28b1a211718b9636c9",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_linux",
                },
                "output_tree_hash": "a50cd668b5e0fecaf46b615ad78f4f47a55db51a50b2c75839f77307831d19ff",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_windows",
            "generator_name": "remote_java_tools_windows",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_windows-v9.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_windows-v9.0.zip",
            ],
            "sha256": "14b679e3bf6a7b4aec36dc33f15ad0027aef43f1bc92e1e2f5abf3a93c156bb5",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v9.0/java_tools_javac11_windows-v9.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v9.0/java_tools_javac11_windows-v9.0.zip",
                    ],
                    "sha256": "14b679e3bf6a7b4aec36dc33f15ad0027aef43f1bc92e1e2f5abf3a93c156bb5",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_windows",
                },
                "output_tree_hash": "e2223044ebddea18b1517acbb6526aa9f6e07902d6bca37bc8059eea5fc55201",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux",
            "generator_name": "remotejdk11_linux",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-linux_x64.tar.gz",
            ],
            "sha256": "360626cc19063bc411bfed2914301b908a8f77a7919aaea007a977fa8fb3cde1",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-linux_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-linux_x64.tar.gz",
                    ],
                    "sha256": "360626cc19063bc411bfed2914301b908a8f77a7919aaea007a977fa8fb3cde1",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-linux_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_linux",
                },
                "output_tree_hash": "564e955d13b4964a9e290728fa27ac50b2578f552868bbe39217013e4a562b98",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux_aarch64",
            "generator_name": "remotejdk11_linux_aarch64",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.48-ca-jdk11.0.6/zulu11.37.48-ca-jdk11.0.6-linux_aarch64.tar.gz",
            ],
            "sha256": "a452f1b9682d9f83c1c14e54d1446e1c51b5173a3a05dcb013d380f9508562e4",
            "strip_prefix": "zulu11.37.48-ca-jdk11.0.6-linux_aarch64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.48-ca-jdk11.0.6/zulu11.37.48-ca-jdk11.0.6-linux_aarch64.tar.gz",
                    ],
                    "sha256": "a452f1b9682d9f83c1c14e54d1446e1c51b5173a3a05dcb013d380f9508562e4",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.48-ca-jdk11.0.6-linux_aarch64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_linux_aarch64",
                },
                "output_tree_hash": "c8558b88d3038b9056e820ed11e3c0ceed2d102fa67e375970875ed485c7252c",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux_ppc64le",
            "generator_name": "remotejdk11_linux_ppc64le",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/openjdk/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
                "https://github.com/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
            ],
            "sha256": "a417db0295b1f4b538ecbaf7c774f3a177fab9657a665940170936c0eca4e71a",
            "strip_prefix": "jdk-11.0.7+10",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
                        "https://github.com/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
                    ],
                    "sha256": "a417db0295b1f4b538ecbaf7c774f3a177fab9657a665940170936c0eca4e71a",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "jdk-11.0.7+10",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_linux_ppc64le",
                },
                "output_tree_hash": "7b26b0263828f87f051af191dac288deaa8662214636710e7007ab0052eb1db2",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_macos",
            "generator_name": "remotejdk11_macos",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-macosx_x64.tar.gz",
            ],
            "sha256": "e1fe56769f32e2aaac95e0a8f86b5a323da5af3a3b4bba73f3086391a6cc056f",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-macosx_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-macosx_x64.tar.gz",
                    ],
                    "sha256": "e1fe56769f32e2aaac95e0a8f86b5a323da5af3a3b4bba73f3086391a6cc056f",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-macosx_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_macos",
                },
                "output_tree_hash": "7ab7a00a16b43325d9c87ba37e51e3f64ddc8acb8e1ccc0299ffa131470bbfe4",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_win",
            "generator_name": "remotejdk11_win",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-win_x64.zip",
            ],
            "sha256": "a9695617b8374bfa171f166951214965b1d1d08f43218db9a2a780b71c665c18",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-win_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-win_x64.zip",
                    ],
                    "sha256": "a9695617b8374bfa171f166951214965b1d1d08f43218db9a2a780b71c665c18",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-win_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_win",
                },
                "output_tree_hash": "5aee9a49df795a67a19a36d839cf96b33209237e0aff14b887a0872143ba67e7",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk14_linux",
            "generator_name": "remotejdk14_linux",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-linux_x64.tar.gz",
            ],
            "sha256": "48bb8947034cd079ad1ef83335e7634db4b12a26743a0dc314b6b861480777aa",
            "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-linux_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-linux_x64.tar.gz",
                    ],
                    "sha256": "48bb8947034cd079ad1ef83335e7634db4b12a26743a0dc314b6b861480777aa",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-linux_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk14_linux",
                },
                "output_tree_hash": "73108f1fe3d2c45375f792b098ac8fb2a432268a9f6122b182642c7edd5ad210",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk14_macos",
            "generator_name": "remotejdk14_macos",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-macosx_x64.tar.gz",
            ],
            "sha256": "088bd4d0890acc9f032b738283bf0f26b2a55c50b02d1c8a12c451d8ddf080dd",
            "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-macosx_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-macosx_x64.tar.gz",
                    ],
                    "sha256": "088bd4d0890acc9f032b738283bf0f26b2a55c50b02d1c8a12c451d8ddf080dd",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-macosx_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk14_macos",
                },
                "output_tree_hash": "5ebc87d8b2586db75f8acc5e5fa81bda0b00cd4e7ebab95795bebbf4a9095148",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk14_win",
            "generator_name": "remotejdk14_win",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-win_x64.zip",
            ],
            "sha256": "9cb078b5026a900d61239c866161f0d9558ec759aa15c5b4c7e905370e868284",
            "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-win_x64",
            "build_file": "@local_jdk//:BUILD.bazel",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/cdn.azul.com/zulu/bin/zulu14.28.21-ca-jdk14.0.1-win_x64.zip",
                    ],
                    "sha256": "9cb078b5026a900d61239c866161f0d9558ec759aa15c5b4c7e905370e868284",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "zulu14.28.21-ca-jdk14.0.1-win_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk14_win",
                },
                "output_tree_hash": "1117bed458a7ec48e09d7bdbb1722e06c5d69d9f4b32ed9ea16960206ea3954e",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "rules_java",
            "generator_name": "rules_java",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
                "https://github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
            ],
            "sha256": "bc81f1ba47ef5cc68ad32225c3d0e70b8c6f6077663835438da8d5733f917598",
            "strip_prefix": "rules_java-7cf3cefd652008d0a64a419c34c13bdca6c8f178",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
                        "https://github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
                    ],
                    "sha256": "bc81f1ba47ef5cc68ad32225c3d0e70b8c6f6077663835438da8d5733f917598",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "rules_java-7cf3cefd652008d0a64a419c34c13bdca6c8f178",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "rules_java",
                },
                "output_tree_hash": "00a0f1231dacff0b0cea3886200e0158c67a3600068275da14120f5434f83b5e",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "rules_proto",
            "generator_name": "rules_proto",
            "generator_function": "maybe",
            "urls": [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
                "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
            ],
            "sha256": "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
            "strip_prefix": "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
                        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
                    ],
                    "sha256": "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "rules_proto",
                },
                "output_tree_hash": "4f74a84e9684fc73c48656a9a6c60bdfaed2cabdf5dc7d21da7ae2ee78c7efa3",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "android_tools",
            "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.19.0rc3.tar.gz",
            "sha256": "ea5c0589a01e2a9f43c20e5c145d3530e3b3bdbe7322789bc5da38d0ca49b837",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.19.0rc3.tar.gz",
                    "urls": [],
                    "sha256": "ea5c0589a01e2a9f43c20e5c145d3530e3b3bdbe7322789bc5da38d0ca49b837",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0",
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "android_tools",
                },
                "output_tree_hash": "0c20b8b63dcadbe472899ac021ece0b532d42d89de5a1e93d841ead07b4a9c87",
            },
        ],
    },
    {
        "original_rule_class": "local_config_platform",
        "original_attributes": {
            "name": "local_config_platform",
        },
        "native": "local_config_platform(name = 'local_config_platform')",
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "platforms",
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/34c2b2925d29f26adbd2afb9a2ac4610/platforms",
        },
        "native": "local_repository(name = \"platforms\", path = __embedded_dir__ + \"/\" + \"platforms\")",
    },
    {
        "original_rule_class": "@bazel_tools//tools/osx:xcode_configure.bzl%xcode_autoconf",
        "original_attributes": {
            "name": "local_config_xcode",
            "generator_name": "local_config_xcode",
            "generator_function": "xcode_configure",
            "xcode_locator": "@bazel_tools//tools/osx:xcode_locator.m",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/osx:xcode_configure.bzl%xcode_autoconf",
                "attributes": {
                    "name": "local_config_xcode",
                    "generator_name": "local_config_xcode",
                    "generator_function": "xcode_configure",
                    "xcode_locator": "@bazel_tools//tools/osx:xcode_locator.m",
                },
                "output_tree_hash": "ec026961157bb71cf68d1b568815ad68147ed16f318161bc0da40f6f3d7d79fd",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/sh:sh_configure.bzl%sh_config",
        "original_attributes": {
            "name": "local_config_sh",
            "generator_name": "local_config_sh",
            "generator_function": "sh_configure",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/sh:sh_configure.bzl%sh_config",
                "attributes": {
                    "name": "local_config_sh",
                    "generator_name": "local_config_sh",
                    "generator_function": "sh_configure",
                },
                "output_tree_hash": "7bf5ba89669bcdf4526f821bc9f1f9f49409ae9c61c4e8f21c9f17e06c475127",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf",
        "original_attributes": {
            "name": "local_config_cc",
            "generator_name": "local_config_cc",
            "generator_function": "cc_configure",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf",
                "attributes": {
                    "name": "local_config_cc",
                    "generator_name": "local_config_cc",
                    "generator_function": "cc_configure",
                },
                "output_tree_hash": "c871086d4518427792a128a3f8e126edab64916435c385cd4a79803d5f4ffb9c",
            },
        ],
    },
    {
        "original_rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf_toolchains",
        "original_attributes": {
            "name": "local_config_cc_toolchains",
            "generator_name": "local_config_cc_toolchains",
            "generator_function": "cc_configure",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf_toolchains",
                "attributes": {
                    "name": "local_config_cc_toolchains",
                    "generator_name": "local_config_cc_toolchains",
                    "generator_function": "cc_configure",
                },
                "output_tree_hash": "1f5225797781e52701eedc83d3881885dbf142cf22222c8ef3b38c8a4b70070e",
            },
        ],
    },
    {
        "original_rule_class": "register_toolchains",
        "original_attributes": {
            "name": "//external/register_toolchains",
            "*args": [
                "@bazel_tools//tools/jdk:all",
                "@bazel_tools//tools/python:autodetecting_toolchain",
                "@local_config_sh//:local_sh_toolchain",
                "@local_config_cc_toolchains//:all",
            ],
        },
        "native": "register_toolchains(\"@bazel_tools//tools/jdk:all\", \"@bazel_tools//tools/python:autodetecting_toolchain\", \"@local_config_sh//:local_sh_toolchain\", \"@local_config_cc_toolchains//:all\")",
    },
    {
        "original_rule_class": "register_execution_platforms",
        "original_attributes": {
            "name": "//external/register_execution_platforms",
            "*args": [],
        },
        "native": "register_execution_platforms()",
    },
]
