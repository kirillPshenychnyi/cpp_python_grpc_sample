#! /usr/bin/python3

"""python client for cpp-python grpc bundle"""

import hello_pb2
import hello_pb2_grpc

import grpc


def main() -> None:
    print('Connecting...')
    try:
        with grpc.insecure_channel('localhost:50051') as channel:
            stub = hello_pb2_grpc.GreeterStub(channel)
            request = hello_pb2.HelloRequest()

            request.name = 'John'
            print('Sending request...')
            response = stub.SayHello(request)

            print('Response received')
            print(response.response)
    except grpc.RpcError as error:
        print(error)


if __name__ == "__main__":
    main()


