#pragma once

#include "lexer.hpp"
#include <optional>

// 最小 AST：只支持 int main() { return <int>; }
struct ASTReturnConst {
  int value { 0 };
};

class Parser {
public:
  explicit Parser(Lexer lex) : lex_(std::move(lex)) { cur_ = lex_.next(); }

  std::optional<ASTReturnConst> parse();

private:
  void advance() { cur_ = lex_.next(); }
  bool accept(TokenKind k);
  bool expect(TokenKind k, const char* msg);

  Lexer lex_;
  Token cur_;
};


