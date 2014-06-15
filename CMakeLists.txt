cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-DLIBSSRCKDTREE_HAVE_BOOST)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

add_executable(test main.cpp)

