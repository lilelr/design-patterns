set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(file_type_SRCS file_type.cpp)
add_executable(file_type ${file_type_SRCS})

set(decorator_SRCS decorator.cpp)
add_executable(decorator ${decorator_SRCS})

set(share_SRCS share.cpp)
add_executable(share ${share_SRCS})

