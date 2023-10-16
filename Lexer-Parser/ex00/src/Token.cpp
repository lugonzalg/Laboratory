#include "Token.hpp"

Token::Token(): _type(NONE), _key("undefuned"), _value("undefuned") {}

Token::Token(t_types type, t_params &params):
    _type(type), _key(params.key), _value(params.value)
    {}

void    Token::add_edge(Token *token) {this->_edges.push_front(token);}

void    Token::delete_edge(Token *token) {
    std::deque<Token *>::iterator it;
    
    it = this->_edges.begin();
    for (; it != this->_edges.end(); it++) {
        if (token == (*it)) {
            this->_edges.erase(it);
            return ;
        }
    }
}

const std::string &Token::get_key() const {return this->_key;};
const std::string &Token::get_value() const {return this->_value;};

std::ostream    &operator<< (std::ostream &os, Token *token) {
    if (token == NULL) {
        os << "Empty token!\n";
        return os;
    }
    os << "Key: " << token->get_key();
    os << "\nValue: " << token->get_value() << std::endl;
    return os;
}