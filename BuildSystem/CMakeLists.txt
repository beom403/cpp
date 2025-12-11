cmake_minimum_required(VERSION 4.2.0)

project(
    build_test
    VERSION 1.0.0
    DESCRIPTION "Build System Test Project"
    LANGUAGES CXX
)

add_executable(program Source/App/main.cpp)