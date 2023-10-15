#include "Lexer.hpp"

#include <cstring>

# define REGEX "POIUYTREWQLKJHGFDSAMNBVCXZpoiuytrewqlkjhgfdsamnbvcxz"

Lexer::Lexer(): _type(NONE), _diff(-1), _regex(REGEX), _start(0){}

Lexer::~Lexer() {}

Token   *Lexer::_create_tokem(t_pattern &pattern) {
    if (pattern.alpha and pattern.two_point and !pattern.dash)
        return new Token(OBJECT)
}

Token    *Lexer::read(const std::string src) {
    t_pattern    pattern;
    size_t  i;

    std::memset(&pattern, 0, sizeof(t_pattern));
    for (i = this->_start; i < src.size() and src[i] != '\n'; i++) {
        if (src[i] == '\t')
            pattern.indent++;
        else if (src[i] == ':')
            pattern.two_point++;
        else if (src[i] == '-')
            pattern.dash++;
        else if (this->_regex.find(src[i] != this->_diff))
            pattern.alpha++;
    }
    return this->_create_token(pattern);
}