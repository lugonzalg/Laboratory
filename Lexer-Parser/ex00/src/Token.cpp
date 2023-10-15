#include "Token.hpp"

Token::Token(): _type(NONE), _key("undefuned"), _value("undefuned"), _start(0), _end(0) {}

Token::Token(t_types type, t_params &params):
    _type(type), _key(params.key), _value(params.value), _start(params.start), _end(params.end)
    {}