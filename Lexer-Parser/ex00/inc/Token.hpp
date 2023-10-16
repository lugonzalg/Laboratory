#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <iostream>
#include <string>
#include <deque>

#include "defs.hpp"

class Token
{

    public:

        Token(t_types type, t_params &params);
        void    add_edge(Token *token);
        void    delete_edge(Token *token);

        //getters
        const std::string &get_key() const;
        const std::string &get_value() const;

    protected:

    private:

        Token();

        const t_types     _type;
        const std::string _key;
        const std::string _value;

        std::deque<Token *> _edges;

};

std::ostream    &operator<< (std::ostream &os, Token *token);

#endif //TOKEN_HPP