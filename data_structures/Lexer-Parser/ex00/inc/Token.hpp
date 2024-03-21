#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <iostream>
#include <string>
#include <deque>

#include "defs.hpp"

class Token
{

    public:

        Token(const std::string &token, __uint8_t state_machine, __uint8_t indent);

        const std::string   &get_key() const;
        __uint8_t           get_sm() const;
        __uint8_t           get_indent() const;
    protected:

    private:

        Token();

        const std::string __token;
        __uint8_t   __state_machine;
        __uint8_t   __indent;

};

#endif //TOKEN_HPP