licenses(["notice"])  # Apache 2

load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_cc_test",
    "envoy_package",
)
load(
    "@envoy//bazel/wasm:wasm.bzl",
    "envoy_wasm_cc_binary",
)

envoy_package()

envoy_cc_library(
    name = "example_plugin",
    srcs = [
        "plugin.cc",
    ],
    hdrs = [
        "plugin.h",
    ],
    repository = "@envoy",
    visibility = ["//visibility:public"],
    deps = [
        "@proxy_wasm_cpp_host//:null_lib",
        "@proxy_wasm_cpp_sdk//contrib:contrib_lib",
    ],
)

envoy_cc_test(
    name = "plugin_test",
    size = "small",
    srcs = ["plugin_test.cc"],
    repository = "@envoy",
    deps = [
        ":example_plugin",
        "@envoy//source/extensions/common/wasm:wasm_lib",
        "@io_istio_proxy//external:abseil_hash_testing",
    ],
)

envoy_wasm_cc_binary(
    name = "example.wasm",
    srcs = [
        "plugin.cc",
        "plugin.h",
    ],
)
