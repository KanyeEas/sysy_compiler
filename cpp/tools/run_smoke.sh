#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"

cmake -S "$ROOT_DIR" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR"

echo 'int main(){return 7;}' > "$BUILD_DIR/_smoke.sy"
echo '--- IR ---'
"$BUILD_DIR/sysyc" "$BUILD_DIR/_smoke.sy" | sed -n '1,20p'
echo '--- ASM ---'
"$BUILD_DIR/sysyc" --emit asm "$BUILD_DIR/_smoke.sy" | sed -n '1,20p'

echo 'OK'


