#include <iostream>

#include "Parser.hpp"

Parser::Parser(const std::string &src, const char *lexer): _src(src), __lexer(lexer) {}

Parser::~Parser() {}

void    Parser::parse() {
    std::deque<Token *> token_list;

    this->__lexer.read(token_list, this->_src);
    std::cout << 1;
}