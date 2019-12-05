cmake_minimum_required(VERSION 3.15)
project(Baseball_Elimination)

set(CMAKE_CXX_STANDARD 17)

add_executable(Baseball_Elimination main.cpp flowEdge.cpp flowEdge.h flowGraph.cpp flowGraph.h fordFulkerson.cpp fordFulkerson.h)