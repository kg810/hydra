cmake_minimum_required(VERSION 2.8.9)
project(CTP_Trade)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall")

include_directories(./include
  ../../CedarInclude/CTP
  ../CedarHelper/include
  ../ProtoBufMsgHub/include
  ../CedarJsonConfig/include
  ../ProtoBufMsg)

set(PROTOBUF ../ProtoBufMsg/CPlusPlusCode/ProtoBufMsg.pb.cc)
file(GLOB SOURCES "src/*.cpp")

LINK_DIRECTORIES(../../CedarLib)
add_executable(CTP_Trade ${SOURCES} ${PROTOBUF})
TARGET_LINK_LIBRARIES(CTP_Trade zmq thosttraderapi jsoncpp protobuf pthread)
