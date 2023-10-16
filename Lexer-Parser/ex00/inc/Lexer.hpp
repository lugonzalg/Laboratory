#ifndef LEXER_HPP
# define LEXER_HPP

#include <string>
#include <map>

#include "Token.hpp"
#include "defs.hpp"

class Lexer
{

    public:

        Lexer();
        ~Lexer();

        Token    *read(const std::string src);

    protected:

    private:

        const std::string   _regex;
        size_t              _start;
        size_t              _depth;
        __uint8_t           _space;
        __uint8_t           _tab;

        Token   *create_token(t_params &params);

};

#endif //LEXER_HPP