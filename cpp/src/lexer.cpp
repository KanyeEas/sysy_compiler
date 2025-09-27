#include "lexer.hpp"

void Lexer::skipSpaces() {
  while (true) {
    char c = peek();
    if (c == ' ' || c == '\t' || c == '\r') {
      get();
      ++col_;
      continue;
    }
    if (c == '\n') {
      get();
      ++line_;
      col_ = 1;
      continue;
    }
    break;
  }
}

Token Lexer::next() {
  skipSpaces();
  Token tok;
  tok.line = line_;
  tok.column = col_;
  char c = peek();
  if (c == '\0') {
    tok.kind = TokenKind::End;
    return tok;
  }

  // Ident / keywords
  if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') {
    std::string s;
    while (std::isalnum(static_cast<unsigned char>(peek())) || peek() == '_') {
      s.push_back(get());
      ++col_;
    }
    tok.lexeme = s;
    if (s == "int") tok.kind = TokenKind::KwInt;
    else if (s == "return") tok.kind = TokenKind::KwReturn;
    else if (s == "main") tok.kind = TokenKind::KwMain;
    else tok.kind = TokenKind::Unknown; // 对最小子集足够
    return tok;
  }

  // Integer literal
  if (std::isdigit(static_cast<unsigned char>(c))) {
    std::string s;
    while (std::isdigit(static_cast<unsigned char>(peek()))) {
      s.push_back(get());
      ++col_;
    }
    tok.kind = TokenKind::Integer;
    tok.lexeme = s;
    return tok;
  }

  // Single-char tokens
  switch (c) {
    case '(': get(); ++col_; tok.kind = TokenKind::LParen; return tok;
    case ')': get(); ++col_; tok.kind = TokenKind::RParen; return tok;
    case '{': get(); ++col_; tok.kind = TokenKind::LBrace; return tok;
    case '}': get(); ++col_; tok.kind = TokenKind::RBrace; return tok;
    case ';': get(); ++col_; tok.kind = TokenKind::Semicolon; return tok;
  }

  // Unknown
  get();
  ++col_;
  tok.kind = TokenKind::Unknown;
  tok.lexeme = std::string(1, c);
  return tok;
}


