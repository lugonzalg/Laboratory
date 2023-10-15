#include "Token.hpp"
#include "Lexer.hpp"

#include <cstring>
#include <iostream>

# define REGEX "POIUYTREWQLKJHGFDSAMNBVCXZpoiuytrewqlkjhgfdsamnbvcxz"

Lexer::Lexer(): _regex(REGEX), _start(0) {}

Lexer::~Lexer() {}

# define TAB_CH '\t'
# define COLON_CH ':'
# define DASH_CH '-'
# define NL_CH '\n'

# define TAB_BIT 0b01000000
# define DASH_BIT 0b00100000
# define ALPHA_1_BIT 0b00010000
# define COLON_BIT 0b00001000
# define ALPHA_2_BIT 0b00000100
# define NL_BIT 0b00000010

# define IS_OBJECT 0b00011010
# define IS_ATTR 0b00011110
# define IS_ITEM_OBJ 0b00111010
# define IS_ITEM_ATTR 0b00111110

Token   *Lexer::create_token(t_params &params) {

    switch (params.state_machine)
    {
        case IS_OBJECT:
            std::cout << "Is a object!" << std::endl;
            return new Token(OBJECT, params);
        case IS_ATTR:
            std::cout << "Is a attribute!" << std::endl;
            return new Token(ATTRIBUTE, params);
        case IS_ITEM_OBJ:
            std::cout << "Is a item object!" << std::endl;
            return new Token(OBJECT,  params);
        case IS_ITEM_ATTR:
            std::cout << "Is a item attr!" << std::endl;
            return new Token(ATTRIBUTE,  params);
        
        default:
            return NULL;
    }
    return NULL;
}

Token    *Lexer::read(const std::string src, size_t depth) {
    size_t  i;
    t_params    params;

    params.state_machine = 0;
    params.start = this->_start;
    params.end = 0;
    params.tabs = 0;
    params.key = "";
    params.value = "";
    for (i = this->_start; i < src.size(); i++) {
        switch (src[i])
        {
            case TAB_CH:
                params.state_machine |= TAB_BIT;
                params.tabs++;
                if (params.tabs > depth)
                    return NULL;
                break;
            case DASH_CH:
                //TODO negative numbers ??
                if (params.tabs != depth)
                    return NULL;
                params.state_machine |= DASH_BIT;
                break;
            case COLON_CH:
                if (params.state_machine & COLON_BIT)
                    return NULL;
                params.state_machine |= COLON_BIT;
                break;
            case NL_CH:
                //TODO create object
                params.end = i;
                params.state_machine |= NL_BIT;
                return this->create_token(params);
                break ;
            default:
                if (this->_regex.find(src[i]) == (size_t)-1)
                    return NULL;
                    
                //TODO review
                if (!(params.state_machine & ALPHA_1_BIT)) {
                    params.key += src[i];
                    if (params.tabs != depth)
                        return NULL;
                    params.state_machine |= ALPHA_1_BIT;
                } else if (params.state_machine & COLON_BIT and !(params.state_machine & ALPHA_2_BIT)) {
                    params.value += src[i];
                    params.state_machine |= ALPHA_2_BIT;
                } else if (params.state_machine & ALPHA_1_BIT)
                    params.key += src[i];
                else if (params.state_machine & ALPHA_2_BIT)
                    params.value += src[i];

                break;
        }

    }
    return NULL;
}