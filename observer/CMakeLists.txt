

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




set(stock_investor_SRCS stock_investor.cpp )
add_executable(stock_investor ${stock_investor_SRCS})

set(observer_SRCS  observer.cpp)
add_executable(observer ${observer_SRCS})



