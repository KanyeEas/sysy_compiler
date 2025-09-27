#include "parser.hpp"
#include <cstdlib>
#include <iostream>

bool Parser::accept(TokenKind k) {
  if (cur_.kind == k) { advance(); return true; }
  return false;
}

bool Parser::expect(TokenKind k, const char* msg) {
  if (!accept(k)) {
    std::cerr << "parse error: expected " << msg << " at line " << cur_.line
              << ", column " << cur_.column << "\n";
    return false;
  }
  return true;
}

std::optional<ASTReturnConst> Parser::parse() {
  // int main() { return <int>; }
  if (!expect(TokenKind::KwInt, "'int'")) return std::nullopt;
  if (!expect(TokenKind::KwMain, "'main'")) return std::nullopt;
  if (!expect(TokenKind::LParen, "'('")) return std::nullopt;
  if (!expect(TokenKind::RParen, "')'")) return std::nullopt;
  if (!expect(TokenKind::LBrace, "'{'")) return std::nullopt;
  if (!expect(TokenKind::KwReturn, "'return'")) return std::nullopt;
  if (cur_.kind != TokenKind::Integer) {
    std::cerr << "parse error: expected integer literal at line " << cur_.line
              << ", column " << cur_.column << "\n";
    return std::nullopt;
  }
  int val = std::atoi(cur_.lexeme.c_str());
  advance();
  if (!expect(TokenKind::Semicolon, "';'")) return std::nullopt;
  if (!expect(TokenKind::RBrace, "'}'")) return std::nullopt;
  ASTReturnConst ast { val };
  return ast;
}


