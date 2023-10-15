#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <string>

#include "defs.hpp"

class Token
{

    public:

        Token(t_types type, t_params &params);

    protected:

    private:

        Token();

        const t_types     _type;
        const std::string _key;
        const std::string _value;
        const int         _start;
        const int         _end;

};

#endif //TOKEN_HPP