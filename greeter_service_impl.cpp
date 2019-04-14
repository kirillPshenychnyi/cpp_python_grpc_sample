#include "greeter_service_impl.h"

Status GreetingServiceImpl::SayHello(ServerContext *context, const HelloRequest *request, HelloResponce *response) {
    response->set_response("Hello, " + request->name() + "!");
    return Status::OK;
}