cmake_minimum_required(VERSION 3.16)
project(sysyc LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(SYSYC_BUILD_TESTS "Build tests" ON)

add_executable(sysyc
  src/main.cpp
  src/lexer.cpp
  src/parser.cpp
)

target_include_directories(sysyc PRIVATE src)

# Install
install(TARGETS sysyc RUNTIME DESTINATION bin)