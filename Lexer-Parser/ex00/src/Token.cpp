#include "Token.hpp"

Token::Token(): _type(NONE), _key("undefuned"), _value("undefuned"), _start(0), _end(0) {}

Token::Token(t_types type, const std::string &key, const std::string &value, size_t start, size_t end):
    _type(type), _key(key), _value(value), _start(start), _end(end)
    {}