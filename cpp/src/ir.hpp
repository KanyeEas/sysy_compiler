#pragma once

#include <string>

// 极简 Koopa IR 片段（仅 main 返回常量）
inline std::string emit_ir_return_const(int value) {
  // 真实 Koopa IR 更复杂，此处仅输出最小可读示例
  std::string ir;
  ir += "fun @main(): i32 {\n";
  ir += "%entry:\n";
  ir += "  ret " + std::to_string(value) + "\n";
  ir += "}\n";
  return ir;
}


