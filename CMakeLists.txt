cmake_minimum_required(VERSION 3.7)
project(design_pattern_learning)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(observer)
add_subdirectory(abstract_factory)

set(SOURCE_FILES main.cpp)
add_executable(design_pattern_learning ${SOURCE_FILES})

