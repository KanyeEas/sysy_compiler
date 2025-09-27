#!/bin/bash

# 编译器配置脚本
# 使用方法: ./configure_compiler.sh [gcc|clang]

COMPILER=${1:-gcc}

echo "=== 编译器配置脚本 ==="
echo "选择的编译器: $COMPILER"

case $COMPILER in
    "gcc")
        echo "使用 GCC 编译器"
        export CC=/usr/bin/gcc
        export CXX=/usr/bin/g++
        export CMAKE_CXX_COMPILER=/usr/bin/g++
        export CMAKE_C_COMPILER=/usr/bin/gcc
        ;;
    "clang")
        echo "使用 Clang 编译器"
        export CC=/usr/bin/clang
        export CXX=/usr/bin/clang++
        export CMAKE_CXX_COMPILER=/usr/bin/clang++
        export CMAKE_C_COMPILER=/usr/bin/clang
        ;;
    *)
        echo "错误: 不支持的编译器 '$COMPILER'"
        echo "支持的编译器: gcc, clang"
        exit 1
        ;;
esac

echo "环境变量设置:"
echo "  CC=$CC"
echo "  CXX=$CXX"
echo "  CMAKE_CXX_COMPILER=$CMAKE_CXX_COMPILER"
echo "  CMAKE_C_COMPILER=$CMAKE_C_COMPILER"

echo ""
echo "验证编译器版本:"
$CXX --version

echo ""
echo "现在可以运行以下命令来配置和构建:"
echo "  mkdir -p build"
echo "  cd build"
echo "  cmake .."
echo "  make"
