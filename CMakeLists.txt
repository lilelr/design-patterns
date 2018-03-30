cmake_minimum_required(VERSION 3.7)
project(design_pattern_learning)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(object_behavior/observer)
add_subdirectory(abstract_factory)
add_subdirectory(object_behavior/chain_of_responsibility)
add_subdirectory(object_behavior/command)
add_subdirectory(object_behavior/intermediate)
add_subdirectory(object_behavior/visitor)

add_subdirectory(struct_pattern)




set(SOURCE_FILES main.cpp)
add_executable(design_pattern_learning ${SOURCE_FILES})

