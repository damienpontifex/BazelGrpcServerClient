package(default_visibility = ["//visibility:public"])

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cc_proto_library")
load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_library")

cc_proto_library(
    name = "hello_cc_proto",
    protos = ["hello.proto"],
    with_grpc = True,
)

cc_binary(
    name = "server",
    srcs = ["server.cc"],
    deps = [":hello_cc_proto"],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    copts = [
        "-std=c++17",
    ],
    deps = [":hello_cc_proto"],
)

py_proto_library(
    name = "hello_py_proto",
    protos = ["hello.proto"],
    with_grpc = True,
)

py_binary(
    name = "py_client",
    srcs = ["client.py"],
    main = "client.py",
    deps = [
        "hello_py_proto",
    ],
)
