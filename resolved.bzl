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
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/4160a288ad7ebd1c653ffcc1508dbbfa/embedded_tools"
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
            "strip_prefix": "bazel_upgradable-master"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://github.com/fenollp/bazel_upgradable/archive/master.zip",
                    "urls": [],
                    "sha256": "54c243e96358113d659994881e55090ed6e7db2c0262343109a78319d4bcd70b",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "bazel_upgradable-master",
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
                    "name": "bazel_upgradable"
                },
                "output_tree_hash": "0612603fcc06f4ec4d9489e5a0c89ebebd6c36088c58c4eb7b4b7daa884248d4"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glew",
            "build_file": "//third_party:glew.BUILD",
            "release": "{tag}.tgz",
            "remote": "git://github.com/nigels-com/glew.git",
            "tag": "<=2",
            "type": "tar.gz"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "build_file": "//third_party:glew.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "{tag}.tgz",
                    "remote": "git://github.com/nigels-com/glew.git",
                    "sha256": "04de91e7e6763039bc11940095cd9c7f880baba82196a7765f727ac05a993c95",
                    "strip_prefix": "",
                    "tag": "<=2",
                    "type": "tar.gz",
                    "urls": [
                        "https://github.com/nigels-com/glew/releases/download/glew-2.1.0/glew-2.1.0.tgz"
                    ],
                    "name": "glew"
                },
                "output_tree_hash": "bc0edc6ac1b1f0195eece677364594ce31e6a9b748a7443946974d724cc2c44d"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glew_win64",
            "build_file": "//third_party:glew_win64.BUILD",
            "release": "{tag}-win32.zip",
            "remote": "git://github.com/nigels-com/glew.git",
            "strip_prefix": "glew-2.1.0",
            "tag": "<=2"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "build_file": "//third_party:glew_win64.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "{tag}-win32.zip",
                    "remote": "git://github.com/nigels-com/glew.git",
                    "sha256": "80cfc88fd295426b49001a9dc521da793f8547ac10aebfc8bdc91ddc06c5566c",
                    "strip_prefix": "glew-2.1.0",
                    "tag": "<=2",
                    "type": "zip",
                    "urls": [
                        "https://github.com/nigels-com/glew/releases/download/glew-2.1.0/glew-2.1.0-win32.zip"
                    ],
                    "name": "glew_win64"
                },
                "output_tree_hash": "73848204f8734716c63d44190227fa2285b74d830ea2ef7eb9db168949ac0cc4"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glfw",
            "build_file": "//third_party:glfw3.BUILD",
            "remote": "git://github.com/glfw/glfw.git"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/glfw/glfw.git",
                    "sha256": "2e64b9dd50c835860d271677dd3386f250a49b852eb73a6ee96a5f9f1e3eac09",
                    "strip_prefix": "glfw-e65de2941c056ee5833b4dab3db36b297b53aa14",
                    "tag": "",
                    "type": "tar.gz",
                    "urls": [
                        "https://github.com/glfw/glfw/archive/e65de2941c056ee5833b4dab3db36b297b53aa14.tar.gz"
                    ],
                    "name": "glfw"
                },
                "output_tree_hash": "34292e679f5f8200fc8820ca898e06f3c7b41f2d16b5faf85f795ff96cb6ec64"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glfw_osx",
            "build_file": "//third_party:glfw3_osx.BUILD",
            "release": "glfw-{tag_digits}.bin.MACOS.zip",
            "remote": "git://github.com/glfw/glfw.git",
            "tag": "~3"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "build_file": "//third_party:glfw3_osx.BUILD",
                    "build_file_content": "",
                    "workspace_file_content": "",
                    "branch": "",
                    "release": "glfw-{tag_digits}.bin.MACOS.zip",
                    "remote": "git://github.com/glfw/glfw.git",
                    "sha256": "e412c75f850c320192df491ec3bf623847fafa847b46ffd3bbd7478057148f5a",
                    "strip_prefix": "",
                    "tag": "~3",
                    "type": "zip",
                    "urls": [
                        "https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.bin.MACOS.zip"
                    ],
                    "name": "glfw_osx"
                },
                "output_tree_hash": "0c89ea86ce1e3231a4e1cc0fc9b21719a333e50fc90e1c3644429d142fba2692"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "glm",
            "build_file": "//third_party:glm.BUILD",
            "remote": "git://github.com/g-truc/glm.git"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/g-truc/glm.git",
                    "sha256": "70ad78e872c145f0164d54da833b651914c184edc65958906937b9739fb8fb1b",
                    "strip_prefix": "glm-bf71a834948186f4097caa076cd2663c69a10e1e",
                    "tag": "",
                    "type": "tar.gz",
                    "urls": [
                        "https://github.com/g-truc/glm/archive/bf71a834948186f4097caa076cd2663c69a10e1e.tar.gz"
                    ],
                    "name": "glm"
                },
                "output_tree_hash": "7ce5597866e31431b7ec5491f4c033879e2beb557f9a86d119060ae90dc42f77"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "khronos_opengl_registry",
            "build_file": "//third_party:gl.BUILD",
            "remote": "git://github.com/KhronosGroup/OpenGL-Registry.git"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/KhronosGroup/OpenGL-Registry.git",
                    "sha256": "708ab9be144ff1fdc4f579f3dc92e1cc44dbc69423ee1b8e0392dab2923f7d2a",
                    "strip_prefix": "OpenGL-Registry-6b670cbfa807378e46c7e704b2980561279304f3",
                    "tag": "",
                    "type": "tar.gz",
                    "urls": [
                        "https://github.com/KhronosGroup/OpenGL-Registry/archive/6b670cbfa807378e46c7e704b2980561279304f3.tar.gz"
                    ],
                    "name": "khronos_opengl_registry"
                },
                "output_tree_hash": "eeeb0341f76c25683108df86790c8a941da6291af32cf0995b9cf4e7a1b06051"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
        "original_attributes": {
            "name": "rules_cc",
            "remote": "git://github.com/bazelbuild/rules_cc.git"
        },
        "repositories": [
            {
                "rule_class": "@bazel_upgradable//:rule.bzl%upgradable_repository",
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
                    "branch": "",
                    "release": "",
                    "remote": "git://github.com/bazelbuild/rules_cc.git",
                    "sha256": "6b4f61176c8f29173886e3625ff4488c4a708ef871b6f6dd4c0c09478bb3fca2",
                    "strip_prefix": "rules_cc-77099ee80d15004ddbac96234761c0a564479131",
                    "tag": "",
                    "type": "tar.gz",
                    "urls": [
                        "https://github.com/bazelbuild/rules_cc/archive/77099ee80d15004ddbac96234761c0a564479131.tar.gz"
                    ],
                    "name": "rules_cc"
                },
                "output_tree_hash": "6b681b20946d243322193eee8349f04d7ce23cbb8ec1aaf4dfb33f2dcf90ffa9"
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
            "build_file": "/home/pete/.cache/bazel/_bazel_pete/install/4160a288ad7ebd1c653ffcc1508dbbfa/jdk.BUILD"
        },
        "native": "new_local_repository(name = \"local_jdk\", path = \"\", build_file = __embedded_dir__ + \"/\" + \"jdk.BUILD\")"
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_darwin",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_darwin-v8.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_darwin-v8.0.zip"
            ],
            "sha256": "e0291e8956ac295143da4a673ca50727f7376665ee82b649a4ee810b64ff76c1"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_darwin-v8.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_darwin-v8.0.zip"
                    ],
                    "sha256": "e0291e8956ac295143da4a673ca50727f7376665ee82b649a4ee810b64ff76c1",
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
                "output_tree_hash": "e1494f2430a8d725c7386b148acf1f65c9f9bc2b2e1369831c309db7257fc6f0"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_linux",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_linux-v8.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_linux-v8.0.zip"
            ],
            "sha256": "c24aef916cc5a8e9f6d53db1f93c54fe5790a58996a1099592e1dfe992acc81e"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_linux-v8.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_linux-v8.0.zip"
                    ],
                    "sha256": "c24aef916cc5a8e9f6d53db1f93c54fe5790a58996a1099592e1dfe992acc81e",
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
                "output_tree_hash": "61010b7dba00e61e471de4ce70caf0e57b1e4508b2bbf5e4fa81bec90045de53"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remote_java_tools_windows",
            "urls": [
                "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_windows-v8.0.zip",
                "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_windows-v8.0.zip"
            ],
            "sha256": "444c391977e50af4e10549a28d021069d2ca7745a0e7b9b968a7b153fe3ea430"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/bazel_java_tools/releases/javac11/v8.0/java_tools_javac11_windows-v8.0.zip",
                        "https://github.com/bazelbuild/java_tools/releases/download/javac11_v8.0/java_tools_javac11_windows-v8.0.zip"
                    ],
                    "sha256": "444c391977e50af4e10549a28d021069d2ca7745a0e7b9b968a7b153fe3ea430",
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
                "output_tree_hash": "9dda84c2aab258115c3c074127a465640a2c493e02c0ad56a4b4f80eedc4dfb0"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-linux_x64.tar.gz"
            ],
            "sha256": "360626cc19063bc411bfed2914301b908a8f77a7919aaea007a977fa8fb3cde1",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-linux_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-linux_x64.tar.gz"
                    ],
                    "sha256": "360626cc19063bc411bfed2914301b908a8f77a7919aaea007a977fa8fb3cde1",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-linux_x64",
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
                "output_tree_hash": "564e955d13b4964a9e290728fa27ac50b2578f552868bbe39217013e4a562b98"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_linux_aarch64",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.48-ca-jdk11.0.6/zulu11.37.48-ca-jdk11.0.6-linux_aarch64.tar.gz"
            ],
            "sha256": "a452f1b9682d9f83c1c14e54d1446e1c51b5173a3a05dcb013d380f9508562e4",
            "strip_prefix": "zulu11.37.48-ca-jdk11.0.6-linux_aarch64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.48-ca-jdk11.0.6/zulu11.37.48-ca-jdk11.0.6-linux_aarch64.tar.gz"
                    ],
                    "sha256": "a452f1b9682d9f83c1c14e54d1446e1c51b5173a3a05dcb013d380f9508562e4",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.48-ca-jdk11.0.6-linux_aarch64",
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
                "output_tree_hash": "c8558b88d3038b9056e820ed11e3c0ceed2d102fa67e375970875ed485c7252c"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_macos",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-macosx_x64.tar.gz"
            ],
            "sha256": "e1fe56769f32e2aaac95e0a8f86b5a323da5af3a3b4bba73f3086391a6cc056f",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-macosx_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-macosx_x64.tar.gz"
                    ],
                    "sha256": "e1fe56769f32e2aaac95e0a8f86b5a323da5af3a3b4bba73f3086391a6cc056f",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-macosx_x64",
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
                "output_tree_hash": "7ab7a00a16b43325d9c87ba37e51e3f64ddc8acb8e1ccc0299ffa131470bbfe4"
            }
        ]
    },
    {
        "original_rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
        "original_attributes": {
            "name": "remotejdk11_win",
            "urls": [
                "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-win_x64.zip"
            ],
            "sha256": "a9695617b8374bfa171f166951214965b1d1d08f43218db9a2a780b71c665c18",
            "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-win_x64",
            "build_file": "@local_jdk//:BUILD.bazel"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "",
                    "urls": [
                        "https://mirror.bazel.build/openjdk/azul-zulu11.37.17-ca-jdk11.0.6/zulu11.37.17-ca-jdk11.0.6-win_x64.zip"
                    ],
                    "sha256": "a9695617b8374bfa171f166951214965b1d1d08f43218db9a2a780b71c665c18",
                    "netrc": "",
                    "canonical_id": "",
                    "strip_prefix": "zulu11.37.17-ca-jdk11.0.6-win_x64",
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
                "output_tree_hash": "5aee9a49df795a67a19a36d839cf96b33209237e0aff14b887a0872143ba67e7"
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
            "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.15.1.tar.gz",
            "sha256": "6b9b9a88a700ae0cdeb75d787f55cab2e939e19af81345e68c9be34f733a2abb"
        },
        "repositories": [
            {
                "rule_class": "@bazel_tools//tools/build_defs/repo:http.bzl%http_archive",
                "attributes": {
                    "url": "https://mirror.bazel.build/bazel_android_tools/android_tools_pkg-0.15.1.tar.gz",
                    "urls": [],
                    "sha256": "6b9b9a88a700ae0cdeb75d787f55cab2e939e19af81345e68c9be34f733a2abb",
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
                "output_tree_hash": "8828795d0f8c6b773a6d93bfc80e6565dcd28344b40e67a02ef1ba91d8b0707a"
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
            "path": "/home/pete/.cache/bazel/_bazel_pete/install/4160a288ad7ebd1c653ffcc1508dbbfa/platforms"
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
