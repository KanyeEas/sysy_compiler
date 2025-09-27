# SysY to RISC-V Compiler (C++)

用法：

```bash
cmake -S . -B build
cmake --build build
./build/sysyc ../sample.sy           # 输出极简 IR
./build/sysyc --emit asm ../sample.sy # 输出极简 RISC-V
```

最小支持：
- 解析 `int main(){ return <int>; }`
- 生成极简 Koopa IR 与 RISC-V 汇编
