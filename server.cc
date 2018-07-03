#include <iostream>
#include <memory>
#include <string>

#include <grpc++/server.h>
#include <grpc++/server_builder.h>

#include "hello.grpc.pb.h"

class HelloImpl final : public HelloWorld::Greeter::Service {
 public:
  grpc::Status SayHello(::grpc::ServerContext* context,
                        const ::HelloWorld::HelloRequest* request,
                        ::HelloWorld::HelloReply* response) override {
    std::cout << "Received request from " << request->name() << '\n';
    response->set_message("Hello " + request->name());
    return grpc::Status::OK;
  }
};

int main() {
  std::string server_address{"0.0.0.0:50051"};
  HelloImpl service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << '\n';
  server->Wait();

  return 0;
}