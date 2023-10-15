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

        t_types             _type;
        const int           _diff;
        const std::string   _regex;
        size_t              _start;

        Token   *_create_tokem(t_pattern &pattern);

};

#endif //LEXER_HPP