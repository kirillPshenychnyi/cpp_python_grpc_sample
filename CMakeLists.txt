project(grpc-cmake-example)

cmake_minimum_required(VERSION 3.2)

add_compile_options("-std=c++11")

# GRPC and Protocol Buffers libraries location
list(APPEND CMAKE_PREFIX_PATH "/opt/grpc" "/opt/protobuf")

# Cmake find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(GRPC REQUIRED)
find_package(Protobuf REQUIRED)

set(PROTOS ${CMAKE_CURRENT_SOURCE_DIR}/protos/hello.proto)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})
include_directories(${PROTO_SRC_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${PROTOS})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTOS})

#protobuf_generate_python(PROTO_PYTHON_SRCS ${PROTOS})
grpc_generate_python(GRPC_PYTHON_SRCS ${PROTOS})

# Building server
add_executable(greeter_server
        ${CMAKE_CURRENT_SOURCE_DIR}/greeter_service_impl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/greeter_service_impl.h
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${PROTO_SRCS}
        ${GRPC_SRCS}
        ${GRPC_PYTHON_SRCS})

target_link_libraries(greeter_server  gRPC::grpc++_reflection  protobuf::libprotobuf)