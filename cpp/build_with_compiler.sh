#!/bin/bash

# 构建脚本 - 支持多种编译器选择
# 使用方法: 
#   ./build_with_compiler.sh gcc
#   ./build_with_compiler.sh clang
#   ./build_with_compiler.sh gcc clean
#   ./build_with_compiler.sh clang clean

COMPILER=${1:-gcc}
ACTION=${2:-build}

echo "=== 构建脚本 ==="
echo "编译器: $COMPILER"
echo "操作: $ACTION"

# 清理构建目录
if [ "$ACTION" = "clean" ]; then
    echo "清理构建目录..."
    rm -rf build
    exit 0
fi

# 创建构建目录
mkdir -p build
cd build

case $COMPILER in
    "gcc")
        echo "使用 GCC 编译器构建..."
        cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DCMAKE_C_COMPILER=/usr/bin/gcc ..
        ;;
    "clang")
        echo "使用 Clang 编译器构建..."
        cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang ..
        ;;
    *)
        echo "错误: 不支持的编译器 '$COMPILER'"
        echo "支持的编译器: gcc, clang"
        exit 1
        ;;
esac

# 构建项目
echo "开始构建..."
make -j$(nproc)

echo "构建完成！"
echo "可执行文件位置: $(pwd)/sysyc"
