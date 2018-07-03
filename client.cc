#include <iostream>

#include "hello.grpc.pb.h"

#include <grpc++/channel.h>
#include <grpc++/create_channel.h>

int main() {
  auto channel = grpc::CreateChannel("localhost:50051",
                                     grpc::InsecureChannelCredentials());

  auto stub = HelloWorld::Greeter::NewStub(channel);
  grpc::ClientContext context;

  HelloWorld::HelloRequest request;
  request.set_name("Damien");
  HelloWorld::HelloReply reply;
  if (auto status = stub->SayHello(&context, request, &reply); !status.ok()) {
    std::cout << "Error " << status.error_message() << '\n';
    return EXIT_FAILURE;
  }

  std::cout << "Reply: " << reply.message() << '\n';
}