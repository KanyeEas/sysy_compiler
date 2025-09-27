#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "lexer.hpp"
#include "parser.hpp"
#include "ir.hpp"
#include "codegen_rvv.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: sysyc [--emit ir|asm] <source.sy>\n";
    return 1;
  }

  std::string mode = "ir";
  std::string input_path;
  if (argc >= 4 && std::string(argv[1]) == "--emit") {
    mode = argv[2];
    input_path = argv[3];
  } else {
    input_path = argv[1];
  }

  // 读取源代码
  std::ifstream in(input_path);
  if (!in) {
    std::cerr << "error: cannot open file: " << input_path << "\n";
    return 1;
  }
  std::ostringstream ss;
  ss << in.rdbuf();
  const std::string source = ss.str();

  // 前端: 词法分析和语法分析
  Lexer lex(source);
  Parser parser(std::move(lex));
  auto ast = parser.parse();
  if (!ast) {
    std::cerr << "error: parse failed\n";
    return 1;
  }

  // 后续阶段：根据开关输出 IR 或 RISC-V
  if (mode == "ir") {
    std::cout << emit_ir_return_const(ast->value);
  } else if (mode == "asm") {
    std::cout << emit_riscv_return_const(ast->value);
  } else {
    std::cerr << "error: unknown emit mode: " << mode << "\n";
    return 1;
  }
  return 0;
}