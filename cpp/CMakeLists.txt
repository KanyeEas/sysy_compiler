cmake_minimum_required(VERSION 3.16)

# 编译器选择配置
# 方法1: 通过命令行参数指定
# cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++ ..
# cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ ..

# 方法2: 通过环境变量指定
# export CXX=/usr/bin/g++ && cmake ..
# export CXX=/usr/bin/clang++ && cmake ..

# 方法3: 在CMakeLists.txt中硬编码（不推荐）
# set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(sysyc LANGUAGES CXX)

# 显示当前使用的编译器
message(STATUS "C++ 编译器: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ 编译器版本: ${CMAKE_CXX_COMPILER_VERSION}")

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