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
            "path": "/root/.cache/bazel/_bazel_root/install/c65c191bb5f6bccd5efa290d850a727b/embedded_tools",
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
            "url": "https://github.com/fenollp/bazel_upgradable/archive/0.2.1.zip",
            "strip_prefix": "bazel_upgradable-0.2.1",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://github.com/fenollp/bazel_upgradable/archive/0.2.1.zip",
                    "urls": [],
                    "sha256": "d5fe3f32f7a083c3a90d8e4e58a9b9f5325f16b01b9dfc00ebdf930f38bb5588",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "bazel_upgradable-0.2.1",
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
                "output_tree_hash": "55ee19f581ca453355e3c503e2207274b9df81ae2872d724a4319e780cccd973",
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
                        "https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.tgz",
                    ],
                    "sha256": "d4fc82893cfb00109578d0a1a2337fb8ca335b3ceccf97b97e5cc7f08e4353e1",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glew-2.2.0",
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
                "output_tree_hash": "94ac1ca9ef8c8b5fb6a83030845ebbc21d0f8f593532865b5c3ed620d829e38a",
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
                        "https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip",
                    ],
                    "sha256": "ea6b14a1c6c968d0034e61ff6cb242cff2ce0ede79267a0f2b47b1b0b652c164",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glew-2.2.0",
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
                "output_tree_hash": "48289cf9cd0708d2430b9cb0f35f94923a85578b88c8b1c000f32d64a790e7ed",
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
                        "https://github.com/glfw/glfw/archive/33cd8b865d9289cfbcf3d95e6e68e4050b94fcd3.tar.gz",
                    ],
                    "sha256": "4923f4da931de2bb1b2f98b9045aa97e13174e1127d169692ebe3fd1f4506300",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glfw-33cd8b865d9289cfbcf3d95e6e68e4050b94fcd3",
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
                "output_tree_hash": "0835500bdcdd37b75fd5e587282b5c4f33e6392d927a2d9848629c534bf4281b",
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
                        "https://github.com/glfw/glfw/releases/download/3.3.3/glfw-3.3.3.bin.MACOS.zip",
                    ],
                    "sha256": "e336ed4ab06b567916a54152f51b67774ec31e71efaf35690bee56612cb48851",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glfw-3.3.3.bin.MACOS",
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
                "output_tree_hash": "51e871ba11876e25d697fee7741aa9398642d4f8e49a7125e3503c7457c93ba0",
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
                        "https://github.com/g-truc/glm/archive/761a842a595f58acfc01cc5c7760ff351feaaece.tar.gz",
                    ],
                    "sha256": "e2a18c61e6e9a8916440756775fd1a7d0616ef4faa30a170c360cacf5a83e0e0",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "glm-761a842a595f58acfc01cc5c7760ff351feaaece",
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
                "output_tree_hash": "83b3dc23b1bb75a6e61a9821f1f427c9c36a644cf9f7d785419809c481ba6f66",
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
                        "https://github.com/KhronosGroup/OpenGL-Registry/archive/c1208cc9206ddc3792b61bcd0f3eeaae68c74f6e.tar.gz",
                    ],
                    "sha256": "2a15b03d07498a8b52e02fca700cbe44b775bbcc73e42481319b368367ba9412",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "OpenGL-Registry-c1208cc9206ddc3792b61bcd0f3eeaae68c74f6e",
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
                "output_tree_hash": "833ab4abc17b3f37a79610a35fc7be0c8557da56645c22f301f0585d794899be",
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
                        "https://github.com/bazelbuild/rules_cc/archive/c612c9581b9e740a49ed4c006edb93912c8ab205.tar.gz",
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_cc/archive/c612c9581b9e740a49ed4c006edb93912c8ab205.tar.gz",
                    ],
                    "sha256": "05073d6b8562d9f8913c274b1ec2624c5562b7077da69812b2cb4d7c9aa619ff",
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "strip_prefix": "rules_cc-c612c9581b9e740a49ed4c006edb93912c8ab205",
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
                "output_tree_hash": "e2b46a9789a739f6b2a8fa87c8c5045f71bec30e5bff537cfb1bf68e4948e000",
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
            "path": "/usr/lib/jvm/java-8-openjdk-amd64",
            "build_file": "/root/.cache/bazel/_bazel_root/install/c65c191bb5f6bccd5efa290d850a727b/jdk.BUILD",
        },
        "native": "new_local_repository(name = \"local_jdk\", path = \"/usr/lib/jvm/java-8-openjdk-amd64\", build_file = __embedded_dir__ + \"/\" + \"jdk.BUILD\")",
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
                "https://mirror.bazel.com/openjdk/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
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
                        "https://mirror.bazel.com/openjdk/AdoptOpenJDK/openjdk11-binaries/releases/download/jdk-11.0.7+10/OpenJDK11U-jdk_ppc64le_linux_hotspot_11.0.7_10.tar.gz",
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
            "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.19.0rc1.tar.gz",
            "sha256": "761e997a9055fe5e2b70aba8d64e78d4c2113feafaa8ac81909cb63e403f3087",
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.19.0rc1.tar.gz",
                    "urls": [],
                    "sha256": "761e997a9055fe5e2b70aba8d64e78d4c2113feafaa8ac81909cb63e403f3087",
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
                "output_tree_hash": "448d40f925c5db4e8ddc0943bd1668bbc93f6a56cadfdee82a269914fd98816e",
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
            "path": "/root/.cache/bazel/_bazel_root/install/c65c191bb5f6bccd5efa290d850a727b/platforms",
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
