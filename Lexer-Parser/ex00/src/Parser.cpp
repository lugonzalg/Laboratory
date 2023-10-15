#include "Parser.hpp"

Parser::Parser(): _src(NULL) {}
Parser::Parser(const std::string src): _src(src) {}

Parser::~Parser() {}

void    Parser::parse() {
    Token   *token;

    while (true) {
        token = this->_lexer.read(this->_src);
        if (token == NULL)
            break ;
    }
}