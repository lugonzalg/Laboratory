#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <map>

#include "Lexer.hpp"

class Parser
{

    public:

        Parser(const std::string &src, const char *lexer);
        ~Parser();

        void    parse();


    protected:

    private:

        const std::string _src;
        Lexer      __lexer;

        Parser();

        std::map<std::string, std::string>  map_tokens;
        typedef std::map<std::string, Token *>::iterator it_tokens;

};

#endif //PARSER_HPP