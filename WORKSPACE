# Required for protobuf library support
# http_archive(
#     name = "com_google_protobuf",
#     urls = [
#         "https://mirror.bazel.build/github.com/google/protobuf/archive/v3.6.0.tar.gz",
#         "https://github.com/google/protobuf/archive/v3.6.0.tar.gz",
#     ],
#     sha256 = "50a5753995b3142627ac55cfd496cebc418a2e575ca0236e29033c67bd5665f4",
#     strip_prefix = "protobuf-3.6.0",
# )

http_archive(
    name = "org_pubref_rules_protobuf",
    sha256 = "012267bf3e2cad7a30d4e56ed4764b5457d7a829c8f037f94507222836e9a7be",
    strip_prefix = "rules_protobuf-0.8.2",
    urls = [
        "https://github.com/pubref/rules_protobuf/archive/v0.8.2.tar.gz",
    ],
)

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cpp_proto_repositories")

cpp_proto_repositories()

load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_repositories")

py_proto_repositories()
