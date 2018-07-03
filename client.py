from __future__ import print_function
import grpc
from hello_pb2_grpc import GreeterStub
from hello_pb2 import HelloRequest

channel = grpc.insecure_channel('localhost:50051')
stub = GreeterStub(channel)
response = stub.SayHello(HelloRequest(name='Damien'))
print('Received:', response.message)