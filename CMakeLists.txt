cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        account.cpp
        account.h
        item.cpp
        item.h
        employee.cpp
        employee.h
        customer.cpp
        customer.h)
