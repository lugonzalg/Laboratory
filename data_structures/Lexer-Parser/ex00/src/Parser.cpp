#include <iostream>

#include "Airport.hpp"
#include "Parser.hpp"
#include "Factory.hpp"

Parser::Parser(const std::string &src, const char *regex_start, const char *regex_end): __src(src), __lexer(regex_start, regex_end) {}

Parser::~Parser() {}

void    Parser::parse(std::deque<Token *> &token_list) {
    this->__lexer.read(token_list, this->__src);
}

void    Parser::reload(const std::string &src) {this->__src = src;}

//bool    Parser::group(std::deque<Token *> &tokens, std::map<std::string, std::deque<Token *> >&elements) {
//    if (elemnts.size() != 0)
//        return true;
//}