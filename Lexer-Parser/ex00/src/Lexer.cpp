#include <stdlib.h>
#include <cstring>
#include <iostream>

#include "Token.hpp"
#include "Lexer.hpp"

Lexer::Lexer(const char *regex): __regex(regex) {}

Lexer::~Lexer() {}

# define SPLIT_PATTERN " \n"
# define SPACE 32
# define TAB 9
# define START 1
# define END 0

static size_t get_boundary(
    const std::string &src,
    size_t i,
    const std::string pattern,
    const bool mode) {

    for (; i < src.size() and (pattern.find(src[i]) != (size_t)-1) == mode; i++);
    return i;
}

static size_t  split(
    std::deque<std::string> &tokens,
    const std::string &src,
    size_t i,
    const std::string &pattern
    ) {

    size_t  start;
    size_t  end;
    std::string token;

    for (; i < src.size(); i++) {

        start = get_boundary(src, i, pattern, START);
        end = get_boundary(src, start, pattern, END);

        if (start >= end)
            break ;
        
        token = src.substr(start, end - start);
        tokens.push_back(token);

        if (src[end] == '\n')
            break ;

        i = end;
    }
    return end + 1;
}

//DASH START, ALPHA 1
# define SM_EMPTY   0b00000000

//ALPHA 1
//state machine, dash start
# define SM_DS 0b10000000

//COLON
# define SM_AS 0b00100000

//ALPHA 2
# define SM_ASDC

//DASH MIDDLE, ALPHA END
//state machine, alpha_start + colon
# define SM_ASC     0b00110000

//COLON
//state machine, dash start + alpha start
# define SM_DSAS 0b10100000

//DASD MIDDLE, ALPHA 2
//state machine, dash start + alpha start + colon
# define SM_DSASC 0b10110000

//ALPHA 2
//state machine, dash start, colon, dash middle
# define SM_DSASCDM 0b11110000

//ALPHA 2
//state machine, alpha start, colon, middle dash
# define SM_ASCDM 0b01110000


# define DASH_CHAR   '-'
# define DASH_START  0b10000000
# define DASH_MIDDLE 0b01000000

# define ALPHA_START 0b00100000
# define ALPHA_END   0b00001000

# define COLON_CHAR  ':'
# define COLON       0b00010000

Token    *Lexer::read(std::deque<Token *> &token_list, std::string src) {
    Token   *token;
    size_t  i;
    __uint8_t      indent;
    bool        space;
    bool        tab;
    const std::string indent_pattern = " \t";
    std::deque<std::string> tokens;

    i = 0;
    while (true) {
        indent = 0;
        for (; i < src.size() and indent_pattern.find(src[i]) != (size_t)-1; i++) {

            if (src[i] == SPACE)
                space = true;

            else if (src[i] == TAB)
                tab = true;

            if (tab and space)
                return NULL;
            indent++;
        }
        __uint8_t   state_machine;

        i = split(tokens, src, i, SPLIT_PATTERN);
        for (size_t j = 0; j < tokens.size(); j++) {
            state_machine = 0;
            for (size_t k = 0; k < tokens[j].size(); k++) {
                switch (tokens[j][k])
                {
                    case SPACE:{
                        indent++;
                        break ;
                    }
                    case DASH_CHAR:
                    {
                        if (state_machine == SM_EMPTY
                        or state_machine == SM_ASC
                        or state_machine == SM_DSASC)
                            state_machine |= DASH_MIDDLE;
                        else
                            std::cerr << "Bad dash\n";
                        break;
                    }
                    case COLON_CHAR:
                    {
                        if (state_machine == SM_DSAS or state_machine == SM_AS)
                            state_machine |= COLON;
                        else
                            std::cerr << "Bad colon\n";
                        break ;
                    }
                    default:
                        if (this->__regex.find(tokens[j][k]) == (size_t)-1) {
                            std::cerr << "Bad character\n";
                            std::cerr << tokens[j][k] << std::endl;
                            break ;
                        } else if (state_machine == SM_EMPTY or state_machine == SM_DS)
                            state_machine |= ALPHA_START;
                        else if (state_machine == SM_ASC)
                            state_machine |= ALPHA_END;
                        break;
                }
                
            }
            token = new Token(tokens[j], state_machine, indent);
            token_list.push_back(token);
        }
        tokens.clear();
        if (i >= src.size())
            break ;
    }

    return NULL;
}

/*
    t_params    params;
    params.state_machine = 0;
    params.tabs = 0;
    params.spaces = 0;
    params.key = "";
    params.value = "";
    for (i = this->_start; i < src.size(); i++) {
        switch (src[i])
        {
            case SPACE_CH:
                this->_space = 1;
                if (params.state_machine != 0)
                    break ;

                if (this->_tab) {
                    std::cerr << "Error: mixed tabs and spaces\n";
                    exit(1);
                }
                params.spaces++;
                break ;

            case TAB_CH:
                this->_tab = 1;
                if (params.state_machine != 0)
                    break ;

                if (this->_space) {
                    std::cerr << "Error: mixed tabs and spaces\n";
                    exit(1);
                }
                params.tabs++;
                break ;

            case DASH_CH:

                //TODO negative numbers ??
                if (this->_depth - params.tabs > 1)
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
                this->_start = i + 1;
                if (params.state_machine == 0)
                    return NULL;
                params.state_machine |= NL_BIT;
                return this->create_token(params);
            default:
                if (this->_regex.find(src[i]) == (size_t)-1)
                    return NULL;
                    
                if (!(params.state_machine & COLON_BIT)) {
                    params.key += src[i];
                    params.state_machine |= ALPHA_1_BIT;
                } else {
                    params.value += src[i];
                    params.state_machine |= ALPHA_2_BIT;
                }
                break;
        }

    }
    */