#ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <map>

#include "Lexer.hpp"
#include "AInfrastructure.hpp"

class Parser
{

    public:

        Parser(const std::string &src, const char *regex_start, const char *regex_end);
        ~Parser();

        void    parse(std::deque<Token *> &token_list);
        void    create_connections(std::deque<AInfrastructure *> &ap_list);
        void    reload(const std::string &src);
        //bool    group(std::deque<Token *> tokens, std::map<std::string, std::deque<Token *> elements);


    protected:

    private:

        std::string       __src;
        Lexer             __lexer;

        Parser();
};

#endif //PARSER_HPP