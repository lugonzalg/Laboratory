#include <stdlib.h>
#include <cstring>
#include <iostream>

#include "Token.hpp"
#include "Lexer.hpp"

Lexer::Lexer(const char *regex_start, const char *regex_end): __regex_alpha_start(regex_start), __regex_alpha_end(regex_end) {}

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
# define OBJECT      0b00000100

int  Lexer::__count_indent(const std::string &src, size_t i) {
    const std::string indent_pattern = " \t";
    int  indent;

    indent = 0;
    for (; i < src.size() and indent_pattern.find(src[i]) != (size_t)-1; i++) {

        if (src[i] == SPACE)
            this->__space = true;

        else if (src[i] == TAB)
            this->__tab = true;

        if (this->__tab and this->__space)
            return -1;
        indent++;
    }
    return indent;
}

void    Lexer::__handle_alpha_start(const std::string &src, size_t i) {
    if (this->__regex_alpha_start.find(src[i]) == (size_t)-1)
        return ;
    this->__sm |= ALPHA_START;
}

void    Lexer::__handle_alpha_end(const std::string &src, size_t i) {
    if (this->__regex_alpha_end.find(src[i]) == (size_t)-1)
        return ;
    this->__sm |= ALPHA_END;
}

Token *Lexer::__create_token(std::string token, size_t indent) {

    for (size_t i = 0; i < token.size(); i++) {
        switch (token[i])
        {
            case SPACE:{
                indent++;
                break ;
            }
            case DASH_CHAR:
            {
                if (this->__sm == SM_EMPTY)
                    this->__sm |= DASH_START;
                else if (this->__sm & SM_ASC)
                    this->__sm |= DASH_MIDDLE;
                else
                    std::cerr << "Bad dash\n";
                break;
            }
            case COLON_CHAR:
            {
                if (this->__sm & SM_AS)
                    this->__sm |= COLON;
                else
                    std::cerr << "Bad colon\n";
                break ;
            }
            default:
                if (!(this->__sm & ALPHA_START) and (this->__sm == SM_EMPTY or this->__sm == SM_DS))
                    this->__handle_alpha_start(token, i);
                else if (!(this->__sm & ALPHA_END) and (this->__sm == SM_ASC or this->__sm == SM_DSASC))
                    this->__handle_alpha_end(token, i);
                break;
        }
        
    }
    return (new Token(token, this->__sm, indent));
}

Token    *Lexer::read(std::deque<Token *> &token_list, std::string src) {
    Token   *token;
    size_t  i;
    __uint8_t               indent;
    std::deque<std::string> tokens;

    i = 0;
    while (true) {
        indent = this->__count_indent(src, i);
        i = split(tokens, src, i, SPLIT_PATTERN);

        this->__sm = 0;
        for (size_t j = 0; j < tokens.size(); j++) {
            token = this->__create_token(tokens[j], indent);
            token_list.push_back(token);
        }
        tokens.clear();
        if (i >= src.size())
            break ;
    }
    return NULL;
}