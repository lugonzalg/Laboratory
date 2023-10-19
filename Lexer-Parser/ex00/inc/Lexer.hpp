#ifndef LEXER_HPP
# define LEXER_HPP

#include <string>
#include <map>

#include "Token.hpp"
#include "defs.hpp"

class Lexer
{

    public:

        Lexer(const char *);
        ~Lexer();

        Token    *read(std::deque<Token *> &tokens, std::string src);

    protected:

    private:

        const std::string   __regex;
};

#endif //LEXER_HPP