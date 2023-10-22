#ifndef LEXER_HPP
# define LEXER_HPP

#include <string>
#include <map>

#include "Token.hpp"
#include "defs.hpp"

class Lexer
{

    public:

        Lexer(const char *, const char *);
        ~Lexer();

        Token    *read(std::deque<Token *> &tokens, std::string src);

    protected:

    private:

        __uint8_t           __sm;
        const std::string   __regex_alpha_start;
        const std::string   __regex_alpha_end;
        bool                __space;
        bool                __tab;

        void    __handle_alpha_start(const std::string &src, size_t i);
        void    __handle_alpha_end(const std::string &src, size_t i);
        Token   *__create_token(std::string token, size_t indent);
        int     __count_indent(const std::string &src, size_t i);
};

#endif //LEXER_HPP