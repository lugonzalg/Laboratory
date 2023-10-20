#include "Token.hpp"

Token::Token(const std::string &token, __uint8_t state_machine, __uint8_t indent): __token(token), __state_machine(state_machine), __indent(indent) {}

const std::string &Token::get_key() const {return this->__token;};
__uint8_t Token::get_sm() const {return this->__state_machine;};