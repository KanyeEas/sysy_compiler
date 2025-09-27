#pragma once

#include "token.hpp"
#include <cctype>
#include <string>

class Lexer {
public:
  explicit Lexer(const std::string &source)
      : source_(source) {}

  Token next();

private:
  char peek() const { return pos_ < source_.size() ? source_[pos_] : '\0'; }
  char get() { return pos_ < source_.size() ? source_[pos_++] : '\0'; }
  void skipSpaces();

  std::string source_;
  size_t pos_ { 0 };
  int line_ { 1 };
  int col_ { 1 };
};


