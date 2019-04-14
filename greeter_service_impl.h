#ifndef GRPC_CMAKE_EXAMPLE_GREETINGSERVICEIMPL_H
#define GRPC_CMAKE_EXAMPLE_GREETINGSERVICEIMPL_H

#include "hello.grpc.pb.h"

#include <grpc++/grpc++.h>
#include <string>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using greeter::HelloRequest;
using greeter::HelloResponce;

class GreetingServiceImpl final : public greeter::Greeter::Service {

public:
    ~GreetingServiceImpl() = default;

    Status SayHello(ServerContext* context, const HelloRequest* request, HelloResponce* response) final;
};


#endif //GRPC_CMAKE_EXAMPLE_GREETINGSERVICEIMPL_H
