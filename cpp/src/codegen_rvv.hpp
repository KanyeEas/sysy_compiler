#pragma once

#include <string>

inline std::string emit_riscv_return_const(int value) {
  std::string s;
  s += ".text\n";
  s += ".globl main\n";
  s += "main:\n";
  s += "  addi sp, sp, -16\n";
  s += "  sw ra, 12(sp)\n";
  s += "  li a0, " + std::to_string(value) + "\n";
  s += "  lw ra, 12(sp)\n";
  s += "  addi sp, sp, 16\n";
  s += "  ret\n";
  return s;
}


