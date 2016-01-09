cmake_minimum_required(VERSION 3.3)
project(linkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    List.cpp
    List.hpp
    main.cpp
    Node.cpp
    Node.hpp)

add_executable(linkedList ${SOURCE_FILES})