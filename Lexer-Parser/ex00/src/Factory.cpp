
#include <stack>

#include "Factory.hpp"

Factory::Factory() {

}
Factory::~Factory() {}

bool  Factory::learn(AInfrastructure *infra) {
  __it_infra  it;
  std::string type_name;

  type_name = infra->get_type();
  it = this->__map_builder.find(type_name);
  if (it != this->__map_builder.end())
    return EXISTS;

  this->__map_builder[type_name] = infra->clone();
  return SUCCESS;
}

bool    Factory::__set_builder(const std::string &key) {
    __it_infra    it;

    it = this->__map_builder.find(key);
    if (it == this->__map_builder.end())
        return BUILDER_NOT_FOUND;

    this->__curr_builder = (*it).second;
    return BUILDER_FOUND;
}

AInfrastructure *Factory::__new_infra() { return this->__curr_builder->clone();}

bool    Factory::create(std::deque<Token *> &tokens, std::deque<AInfrastructure *> &elements) {
    std::deque<AInfrastructure *>   holder;
    Token                           *token;
    std::string                     key;
    std::deque<Token *>::iterator   it;
    __uint8_t                       curr_indent;
    AInfrastructure                 *curr_infra;

    (void)elements;
    curr_infra = NULL;
    curr_indent = 255;
    it = tokens.begin();
    for (; it != tokens.end(); it++) {
        token = *it;
        key = token->get_key();

        switch (token->get_sm())
        {
            case 48:
            {
                    if (token->get_indent() != curr_indent) {
                        this->__set_builder(key);
                    } else {
                        curr_infra->set_value(key);
                    }
                break ;
            }
            case 56:
            {
                curr_infra->add_value(key);
                break ;
            }
            case 112:
            {
                curr_infra->add_value(key);
                break ;
            }
            case 128:
            {
                if (curr_infra != NULL)
                    elements.push_back(curr_infra);
                curr_infra = this->__new_infra();
                break ;
            }
            case 176:
            {
                curr_infra->set_value(key);
                break ;
            }
            case 184:
            {
                curr_infra->add_value(key);
                break ;
            }
                /* code */
            break;
            
                default:
                    break;
        }
    }
    return true;
}