#pragma once

#include <string>

enum class TokenKind {
  End,
  KwInt,
  KwReturn,
  KwMain,
  LParen,
  RParen,
  LBrace,
  RBrace,
  Semicolon,
  Integer,
  Unknown,
};

struct Token {
  TokenKind kind { TokenKind::Unknown };
  std::string lexeme {};
  int line { 1 };
  int column { 1 };
};


