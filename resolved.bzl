resolved = [
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/crosstool",
            "actual": "@bazel_tools//tools/cpp:toolchain"
        },
        "native": "bind(name = \"android/crosstool\", actual = \"@bazel_tools//tools/cpp:toolchain\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/d8_jar_import",
            "actual": "@bazel_tools//tools/android:no_android_sdk_repository_error"
        },
        "native": "bind(name = \"android/d8_jar_import\", actual = \"@bazel_tools//tools/android:no_android_sdk_repository_error\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/dx_jar_import",
            "actual": "@bazel_tools//tools/android:no_android_sdk_repository_error"
        },
        "native": "bind(name = \"android/dx_jar_import\", actual = \"@bazel_tools//tools/android:no_android_sdk_repository_error\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android/sdk",
            "actual": "@bazel_tools//tools/android:poison_pill_android_sdk"
        },
        "native": "bind(name = \"android/sdk\", actual = \"@bazel_tools//tools/android:poison_pill_android_sdk\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android_ndk_for_testing",
            "actual": "//:dummy"
        },
        "native": "bind(name = \"android_ndk_for_testing\", actual = \"//:dummy\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "android_sdk_for_testing",
            "actual": "//:dummy"
        },
        "native": "bind(name = \"android_sdk_for_testing\", actual = \"//:dummy\")"
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "bazel_tools",
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/a968348e0a72afc534c7baff88ca46f1/embedded_tools"
        },
        "native": "local_repository(name = \"bazel_tools\", path = __embedded_dir__ + \"/\" + \"embedded_tools\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "cc_toolchain",
            "actual": "@local_config_cc//:toolchain"
        },
        "native": "bind(name = \"cc_toolchain\", actual = \"@local_config_cc//:toolchain\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "databinding_annotation_processor",
            "actual": "@bazel_tools//tools/android:empty"
        },
        "native": "bind(name = \"databinding_annotation_processor\", actual = \"@bazel_tools//tools/android:empty\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "has_androidsdk",
            "actual": "@bazel_tools//tools/android:always_false"
        },
        "native": "bind(name = \"has_androidsdk\", actual = \"@bazel_tools//tools/android:always_false\")"
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "voidstar",
            "path": "."
        },
        "native": "local_repository(name = \"voidstar\", path = \".\")"
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "bazel_upgradable",
            "url": "https://github.com/fenollp/bazel_upgradable/archive/master.zip",
            "strip_prefix": "bazel_upgradable-master",
            "type": "zip"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://github.com/fenollp/bazel_upgradable/archive/master.zip",
                    "urls": [],
                    "sha256": "c18eba9c7fb6a9206586eacb10c2946d9204c2f7749c676217079c96a6d3da59",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "bazel_upgradable-master",
                    "type": "zip",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "bazel_upgradable"
                },
                "output_tree_hash": "e7d0faa83e22e2c8b3a0b0ccdfd82413c7a7e7ce29e43987cfeaae110c2a33d3"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
        "original_attributes": {
            "name": "com_github_gtruc_glm",
            "build_file": "//third_party:glm.BUILD",
            "branch": "master",
            "slug": "g-truc/glm"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
                "attributes": {
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glm.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "master",
                    "slug": "g-truc/glm",
                    "tag": "",
                    "sha256": "cc5f92593be85d51fc243a4735a07898f010e32f7c1496822e8d78a3df651320",
                    "strip_prefix": "glm-efbfecab63da2adb2dc197f91270ff6221900740",
                    "urls": [
                        "https://github.com/g-truc/glm/archive/efbfecab63da2adb2dc197f91270ff6221900740.zip"
                    ],
                    "name": "com_github_gtruc_glm"
                },
                "output_tree_hash": "294235b12e80f17d7f43e8acf64a5eeaa2abed2f8cdeb138dddd3f2fa33d9ff3"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
        "original_attributes": {
            "name": "glfw",
            "build_file": "//third_party:glfw3.BUILD",
            "branch": "master",
            "slug": "glfw/glfw"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
                "attributes": {
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:glfw3.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "master",
                    "slug": "glfw/glfw",
                    "tag": "",
                    "sha256": "d627cb439cece9ead0693659ced597e9775596a3b72c708ba04590520c7e8ca9",
                    "strip_prefix": "glfw-e65de2941c056ee5833b4dab3db36b297b53aa14",
                    "urls": [
                        "https://github.com/glfw/glfw/archive/e65de2941c056ee5833b4dab3db36b297b53aa14.zip"
                    ],
                    "name": "glfw"
                },
                "output_tree_hash": "a7df8ded487e666323402f7c623f103b7437bd53a92e011c83fbe351a54866ab"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
        "original_attributes": {
            "name": "khronos_opengl_registry",
            "build_file": "//third_party:gl.BUILD",
            "branch": "master",
            "slug": "KhronosGroup/OpenGL-Registry"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
                "attributes": {
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "//third_party:gl.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "master",
                    "slug": "KhronosGroup/OpenGL-Registry",
                    "tag": "",
                    "sha256": "f6542a854b3ac7d6af8a8da76e00303e000852942aa1b2b83b52c07bacbb0913",
                    "strip_prefix": "OpenGL-Registry-4594c03239fb76580bc5d5a13acb2a8f563f0158",
                    "urls": [
                        "https://github.com/KhronosGroup/OpenGL-Registry/archive/4594c03239fb76580bc5d5a13acb2a8f563f0158.zip"
                    ],
                    "name": "khronos_opengl_registry"
                },
                "output_tree_hash": "a8053e275c1de3f382d06c735dc3a6419828e377716358d7df055d3beef525df"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
        "original_attributes": {
            "name": "rules_cc",
            "branch": "master",
            "slug": "bazelbuild/rules_cc"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//rules:github.bzl%upgradable_github_archive",
                "attributes": {
                    "netrc": "",
                    "auth_patterns": {},
                    "canonical_id": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "master",
                    "slug": "bazelbuild/rules_cc",
                    "tag": "",
                    "sha256": "523c59bb3f16518679668594c8874da46872fde05c32ba246bc0a35ec292f8a6",
                    "strip_prefix": "rules_cc-34ca16f4aa4bf2a5d3e4747229202d6cb630ebab",
                    "urls": [
                        "https://github.com/bazelbuild/rules_cc/archive/34ca16f4aa4bf2a5d3e4747229202d6cb630ebab.zip"
                    ],
                    "name": "rules_cc"
                },
                "output_tree_hash": "aa9a5fa504287193f8401e75000f9a7fe7c2dcbcaee37f61077734f2bb650a22"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_coverage_tools",
            "urls": [
                "https://mirror.bazel.build/bazel_coverage_output_generator/releases/coverage_output_generator-v2.1.zip"
            ],
            "sha256": "96ac6bc9b9fbc67b532bcae562da1642409791e6a4b8e522f04946ee5cc3ff8e"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_coverage_output_generator/releases/coverage_output_generator-v2.1.zip"
                    ],
                    "sha256": "96ac6bc9b9fbc67b532bcae562da1642409791e6a4b8e522f04946ee5cc3ff8e",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_coverage_tools"
                },
                "output_tree_hash": "a021aeb7dfe67e7a2bb584ae6cfaaff48068b302c3b972d0d5a2cb068640531b"
            }
        ]
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "bootclasspath",
            "actual": "@local_jdk//:bootclasspath"
        },
        "native": "bind(name = \"bootclasspath\", actual = \"@local_jdk//:bootclasspath\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "extclasspath",
            "actual": "@local_jdk//:extdir"
        },
        "native": "bind(name = \"extclasspath\", actual = \"@local_jdk//:extdir\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "extdir",
            "actual": "@local_jdk//:extdir"
        },
        "native": "bind(name = \"extdir\", actual = \"@local_jdk//:extdir\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jar",
            "actual": "@local_jdk//:jar"
        },
        "native": "bind(name = \"jar\", actual = \"@local_jdk//:jar\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "java",
            "actual": "@local_jdk//:java"
        },
        "native": "bind(name = \"java\", actual = \"@local_jdk//:java\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "javac",
            "actual": "@local_jdk//:javac"
        },
        "native": "bind(name = \"javac\", actual = \"@local_jdk//:javac\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jdk",
            "actual": "@local_jdk//:jdk"
        },
        "native": "bind(name = \"jdk\", actual = \"@local_jdk//:jdk\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jdk-default",
            "actual": "@local_jdk//:jdk"
        },
        "native": "bind(name = \"jdk-default\", actual = \"@local_jdk//:jdk\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_header",
            "actual": "@local_jdk//:jni_header"
        },
        "native": "bind(name = \"jni_header\", actual = \"@local_jdk//:jni_header\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-darwin",
            "actual": "@local_jdk//:jni_md_header-darwin"
        },
        "native": "bind(name = \"jni_md_header-darwin\", actual = \"@local_jdk//:jni_md_header-darwin\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-freebsd",
            "actual": "@local_jdk//:jni_md_header-freebsd"
        },
        "native": "bind(name = \"jni_md_header-freebsd\", actual = \"@local_jdk//:jni_md_header-freebsd\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-linux",
            "actual": "@local_jdk//:jni_md_header-linux"
        },
        "native": "bind(name = \"jni_md_header-linux\", actual = \"@local_jdk//:jni_md_header-linux\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jni_md_header-openbsd",
            "actual": "@local_jdk//:jni_md_header-openbsd"
        },
        "native": "bind(name = \"jni_md_header-openbsd\", actual = \"@local_jdk//:jni_md_header-openbsd\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jre",
            "actual": "@local_jdk//:jre"
        },
        "native": "bind(name = \"jre\", actual = \"@local_jdk//:jre\")"
    },
    {
        "original_rule_class": "bind",
        "original_attributes": {
            "name": "jre-default",
            "actual": "@local_jdk//:jre"
        },
        "native": "bind(name = \"jre-default\", actual = \"@local_jdk//:jre\")"
    },
    {
        "original_rule_class": "new_local_repository",
        "original_attributes": {
            "name": "local_jdk",
            "path": "",
            "build_file": "/home/pete/.cache/bazel/_bazel_pete/install/a968348e0a72afc534c7baff88ca46f1/jdk.BUILD"
        },
        "native": "new_local_repository(name = \"local_jdk\", path = \"\", build_file = __embedded_dir__ + \"/\" + \"jdk.BUILD\")"
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_darwin",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_darwin-v7.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_darwin-v7.0.zip"
            ],
            "sha256": "373a4226906ae9ba908550da16e133c4cd1f01b8973af82b9a2eb6903cb4d645"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_darwin-v7.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_darwin-v7.0.zip"
                    ],
                    "sha256": "373a4226906ae9ba908550da16e133c4cd1f01b8973af82b9a2eb6903cb4d645",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_darwin"
                },
                "output_tree_hash": "6a1274bb378cd31f3c01309fe031e1167eded56f10a1663e33319b1d09eb2697"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_linux",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_linux-v7.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_linux-v7.0.zip"
            ],
            "sha256": "3ff465e82954a70f49982610dd63f6f651beaa83c707dd637870b0e41cdcd2f0"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_linux-v7.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_linux-v7.0.zip"
                    ],
                    "sha256": "3ff465e82954a70f49982610dd63f6f651beaa83c707dd637870b0e41cdcd2f0",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_linux"
                },
                "output_tree_hash": "078d6939f452c18f7e157e36ced2fc741f87bb41459d15d2141cb1e543227a71"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_windows",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_windows-v7.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_windows-v7.0.zip"
            ],
            "sha256": "11d90a147919e74d11870cdd58c4ee5de3062c08d11b16aa72d3f3bbfa9497a0"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v7.0/java_tools_javac11_windows-v7.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11-v7.0/java_tools_javac11_windows-v7.0.zip"
                    ],
                    "sha256": "11d90a147919e74d11870cdd58c4ee5de3062c08d11b16aa72d3f3bbfa9497a0",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remote_java_tools_windows"
                },
                "output_tree_hash": "e19aaaf567a4ba900cd3fc1ae86e150f3328ee255d799e9d8705394fcd09de36"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk10_linux",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-linux_x64-allmodules.tar.gz"
            ],
            "sha256": "57fad3602e74c79587901d6966d3b54ef32cb811829a2552163185d5064fe9b5",
            "strip_prefix": "zulu10.2+3-jdk10.0.1-linux_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-linux_x64-allmodules.tar.gz"
                    ],
                    "sha256": "57fad3602e74c79587901d6966d3b54ef32cb811829a2552163185d5064fe9b5",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu10.2+3-jdk10.0.1-linux_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk10_linux"
                },
                "output_tree_hash": "b714a0289904226bbe7719bdca945c8f26fdf78e63773b6fe960249e912f7044"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk10_linux_aarch64",
            "urls": [
                "https://mirror.bazel.build/openjdk.linaro.org/releases/jdk10-server-release-1804.tar.xz",
                "http://openjdk.linaro.org/releases/jdk10-server-release-1804.tar.xz"
            ],
            "sha256": "b7098b7aaf6ee1ffd4a2d0371a0be26c5a5c87f6aebbe46fe9a92c90583a84be",
            "strip_prefix": "jdk10-server-release-1804",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk.linaro.org/releases/jdk10-server-release-1804.tar.xz",
                        "http://openjdk.linaro.org/releases/jdk10-server-release-1804.tar.xz"
                    ],
                    "sha256": "b7098b7aaf6ee1ffd4a2d0371a0be26c5a5c87f6aebbe46fe9a92c90583a84be",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "jdk10-server-release-1804",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk10_linux_aarch64"
                },
                "output_tree_hash": "869e1b005aeb6cecb1ff8e2292ef31ddfce995db7e9883a1f6f8be14801acf47"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk10_macos",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-macosx_x64-allmodules.tar.gz"
            ],
            "sha256": "e669c9a897413d855b550b4e39d79614392e6fb96f494e8ef99a34297d9d85d3",
            "strip_prefix": "zulu10.2+3-jdk10.0.1-macosx_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-macosx_x64-allmodules.tar.gz"
                    ],
                    "sha256": "e669c9a897413d855b550b4e39d79614392e6fb96f494e8ef99a34297d9d85d3",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu10.2+3-jdk10.0.1-macosx_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk10_macos"
                },
                "output_tree_hash": "fc0d5838a0ed6e018a6a22b33dd011a8941e65990a6be3d2362dffda8733d40e"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk10_win",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-win_x64-allmodules.zip"
            ],
            "sha256": "c39e7700a8d41794d60985df5a20352435196e78ecbc6a2b30df7be8637bffd5",
            "strip_prefix": "zulu10.2+3-jdk10.0.1-win_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu10.2+3-jdk10.0.1/zulu10.2+3-jdk10.0.1-win_x64-allmodules.zip"
                    ],
                    "sha256": "c39e7700a8d41794d60985df5a20352435196e78ecbc6a2b30df7be8637bffd5",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu10.2+3-jdk10.0.1-win_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk10_win"
                },
                "output_tree_hash": "756c25322349559a735471501683cbe713dc2f8b8f8309d22d5c14f5318e4bd0"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-linux_x64.tar.gz"
            ],
            "sha256": "232b1c3511f0d26e92582b7c3cc363be7ac633e371854ca2f2e9f2b50eb72a75",
            "strip_prefix": "zulu11.2.3-jdk11.0.1-linux_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-linux_x64.tar.gz"
                    ],
                    "sha256": "232b1c3511f0d26e92582b7c3cc363be7ac633e371854ca2f2e9f2b50eb72a75",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.2.3-jdk11.0.1-linux_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_linux"
                },
                "output_tree_hash": "09b1584f92b66c75bf10c76c016c158925bed0453f77456ca78d056a71cd605e"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux_aarch64",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.31.15-ca-jdk11.0.3/zulu11.31.15-ca-jdk11.0.3-linux_aarch64.tar.gz"
            ],
            "sha256": "3b0d91611b1bdc4d409afcf9eab4f0e7f4ae09f88fc01bd9f2b48954882ae69b",
            "strip_prefix": "zulu11.31.15-ca-jdk11.0.3-linux_aarch64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.31.15-ca-jdk11.0.3/zulu11.31.15-ca-jdk11.0.3-linux_aarch64.tar.gz"
                    ],
                    "sha256": "3b0d91611b1bdc4d409afcf9eab4f0e7f4ae09f88fc01bd9f2b48954882ae69b",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.31.15-ca-jdk11.0.3-linux_aarch64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_linux_aarch64"
                },
                "output_tree_hash": "3229e1f66676f7029a1da630943c34cffa199fa13639c9a9cd88d6cb31fe135a"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_macos",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-macosx_x64.tar.gz"
            ],
            "sha256": "1edf366ee821e5db8e348152fcb337b28dfd6bf0f97943c270dcc6747cedb6cb",
            "strip_prefix": "zulu11.2.3-jdk11.0.1-macosx_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-macosx_x64.tar.gz"
                    ],
                    "sha256": "1edf366ee821e5db8e348152fcb337b28dfd6bf0f97943c270dcc6747cedb6cb",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.2.3-jdk11.0.1-macosx_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_macos"
                },
                "output_tree_hash": "609e6c7e3ef398bdb58f9266169bb12dafc585fef591317b545c08070bf56ca1"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_win",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-win_x64.zip"
            ],
            "sha256": "8e1e2b8347de6746f3fd1538840dd643201533ab113abc4ed93678e342d28aa3",
            "strip_prefix": "zulu11.2.3-jdk11.0.1-win_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.2.3-jdk11.0.1/zulu11.2.3-jdk11.0.1-win_x64.zip"
                    ],
                    "sha256": "8e1e2b8347de6746f3fd1538840dd643201533ab113abc4ed93678e342d28aa3",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.2.3-jdk11.0.1-win_x64",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk11_win"
                },
                "output_tree_hash": "90ff0b507bbec499e9bbc867f6456a2901e73cacb1003a90adbad810a49ba412"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk_linux",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-linux_x64-allmodules.tar.gz"
            ],
            "sha256": "f27cb933de4f9e7fe9a703486cf44c84bc8e9f138be0c270c9e5716a32367e87",
            "strip_prefix": "zulu9.0.7.1-jdk9.0.7-linux_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-linux_x64-allmodules.tar.gz"
                    ],
                    "sha256": "f27cb933de4f9e7fe9a703486cf44c84bc8e9f138be0c270c9e5716a32367e87",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu9.0.7.1-jdk9.0.7-linux_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk_linux"
                },
                "output_tree_hash": "f0797dd509408aec532df0d8f93d4beb15166267fc4f254cc6e1cec7e75334a7"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk_linux_aarch64",
            "urls": [
                "https://mirror.bazel.build/openjdk.linaro.org/releases/jdk9-server-release-1708.tar.xz",
                "http://openjdk.linaro.org/releases/jdk9-server-release-1708.tar.xz"
            ],
            "sha256": "72e7843902b0395e2d30e1e9ad2a5f05f36a4bc62529828bcbc698d54aec6022",
            "strip_prefix": "jdk9-server-release-1708",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk.linaro.org/releases/jdk9-server-release-1708.tar.xz",
                        "http://openjdk.linaro.org/releases/jdk9-server-release-1708.tar.xz"
                    ],
                    "sha256": "72e7843902b0395e2d30e1e9ad2a5f05f36a4bc62529828bcbc698d54aec6022",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "jdk9-server-release-1708",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk_linux_aarch64"
                },
                "output_tree_hash": "ecfef58ce3c153032fae0dec5884083464ccb10f8fc7ecd0711da02c0715969e"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk_macos",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-macosx_x64-allmodules.tar.gz"
            ],
            "sha256": "404e7058ff91f956612f47705efbee8e175a38b505fb1b52d8c1ea98718683de",
            "strip_prefix": "zulu9.0.7.1-jdk9.0.7-macosx_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-macosx_x64-allmodules.tar.gz"
                    ],
                    "sha256": "404e7058ff91f956612f47705efbee8e175a38b505fb1b52d8c1ea98718683de",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu9.0.7.1-jdk9.0.7-macosx_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk_macos"
                },
                "output_tree_hash": "b6328273f948385883454edd5e67c8888a70b93dd3674c8c119e1722167108b0"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk_win",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-win_x64-allmodules.zip"
            ],
            "sha256": "e738829017f107e7a7cd5069db979398ec3c3f03ef56122f89ba38e7374f63ed",
            "strip_prefix": "zulu9.0.7.1-jdk9.0.7-win_x64-allmodules",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu-9.0.7.1-jdk9.0.7/zulu9.0.7.1-jdk9.0.7-win_x64-allmodules.zip"
                    ],
                    "sha256": "e738829017f107e7a7cd5069db979398ec3c3f03ef56122f89ba38e7374f63ed",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu9.0.7.1-jdk9.0.7-win_x64-allmodules",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file": "@local_jdk//:BUILD.bazel",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "remotejdk_win"
                },
                "output_tree_hash": "f1855394faac6e484817b7a7da4745e7bbfca775f18ee2fdc9ef6e65f6cac907"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "rules_java",
            "urls": [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
                "https://github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip"
            ],
            "sha256": "bc81f1ba47ef5cc68ad32225c3d0e70b8c6f6077663835438da8d5733f917598",
            "strip_prefix": "rules_java-7cf3cefd652008d0a64a419c34c13bdca6c8f178"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip",
                        "https://github.com/bazelbuild/rules_java/archive/7cf3cefd652008d0a64a419c34c13bdca6c8f178.zip"
                    ],
                    "sha256": "bc81f1ba47ef5cc68ad32225c3d0e70b8c6f6077663835438da8d5733f917598",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "rules_java-7cf3cefd652008d0a64a419c34c13bdca6c8f178",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "rules_java"
                },
                "output_tree_hash": "00a0f1231dacff0b0cea3886200e0158c67a3600068275da14120f5434f83b5e"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "rules_proto",
            "urls": [
                "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
                "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz"
            ],
            "sha256": "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
            "strip_prefix": "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
                        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz"
                    ],
                    "sha256": "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "rules_proto"
                },
                "output_tree_hash": "4f74a84e9684fc73c48656a9a6c60bdfaed2cabdf5dc7d21da7ae2ee78c7efa3"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "android_tools",
            "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.14.tar.gz",
            "sha256": "a3a951838448483e7af25afd10671b266cc6283104b4a2a427d31cac12cf0912"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.14.tar.gz",
                    "urls": [],
                    "sha256": "a3a951838448483e7af25afd10671b266cc6283104b4a2a427d31cac12cf0912",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "",
                    "type": "",
                    "patches": [],
                    "patch_tool": "",
                    "patch_args": [
                        "-p0"
                    ],
                    "patch_cmds": [],
                    "patch_cmds_win": [],
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "name": "android_tools"
                },
                "output_tree_hash": "e826feef6e130955e1f725dcc37700c4f732007f523137dcb84351a57c9e7685"
            }
        ]
    },
    {
        "original_rule_class": "local_config_platform",
        "original_attributes": {
            "name": "local_config_platform"
        },
        "native": "local_config_platform(name = 'local_config_platform')"
    },
    {
        "original_rule_class": "local_repository",
        "original_attributes": {
            "name": "platforms",
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/a968348e0a72afc534c7baff88ca46f1/platforms"
        },
        "native": "local_repository(name = \"platforms\", path = __embedded_dir__ + \"/\" + \"platforms\")"
    },
    {
        "original_rule_class": "@bazel_tools//tools/osx:xcode_configure.bzl%xcode_autoconf",
        "original_attributes": {
            "name": "local_config_xcode",
            "xcode_locator": "@bazel_tools//tools/osx:xcode_locator.m"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/osx:xcode_configure.bzl%xcode_autoconf",
                "attributes": {
                    "name": "local_config_xcode",
                    "xcode_locator": "@bazel_tools//tools/osx:xcode_locator.m"
                },
                "output_tree_hash": "ec026961157bb71cf68d1b568815ad68147ed16f318161bc0da40f6f3d7d79fd"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/sh:sh_configure.bzl%sh_config",
        "original_attributes": {
            "name": "local_config_sh"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/sh:sh_configure.bzl%sh_config",
                "attributes": {
                    "name": "local_config_sh"
                },
                "output_tree_hash": "7bf5ba89669bcdf4526f821bc9f1f9f49409ae9c61c4e8f21c9f17e06c475127"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf",
        "original_attributes": {
            "name": "local_config_cc"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf",
                "attributes": {
                    "name": "local_config_cc"
                },
                "output_tree_hash": "6964c407a22e3fa0c52c992e4cf24145271e2580a714d100c1cf11e4ddbc019e"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf_toolchains",
        "original_attributes": {
            "name": "local_config_cc_toolchains"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/cpp:cc_configure.bzl%cc_autoconf_toolchains",
                "attributes": {
                    "name": "local_config_cc_toolchains"
                },
                "output_tree_hash": "1f5225797781e52701eedc83d3881885dbf142cf22222c8ef3b38c8a4b70070e"
            }
        ]
    },
    {
        "original_rule_class": "register_toolchains",
        "original_attributes": {
            "name": "//external/register_toolchains",
            "*args": [
                "@bazel_tools//tools/jdk:all",
                "@bazel_tools//tools/python:autodetecting_toolchain",
                "@local_config_sh//:local_sh_toolchain",
                "@local_config_cc_toolchains//:all"
            ]
        },
        "native": "register_toolchains(\"@bazel_tools//tools/jdk:all\", \"@bazel_tools//tools/python:autodetecting_toolchain\", \"@local_config_sh//:local_sh_toolchain\", \"@local_config_cc_toolchains//:all\")"
    },
    {
        "original_rule_class": "register_execution_platforms",
        "original_attributes": {
            "name": "//external/register_execution_platforms",
            "*args": []
        },
        "native": "register_execution_platforms()"
    }
]
