cmake_minimum_required(VERSION 3.7)
project(design_pattern_learning)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(observer)
add_subdirectory(abstract_factory)
add_subdirectory(chain_of_responsibility)
add_subdirectory(command)
add_subdirectory(intermediate)
add_subdirectory(visitor)



set(SOURCE_FILES main.cpp)
add_executable(design_pattern_learning ${SOURCE_FILES})

