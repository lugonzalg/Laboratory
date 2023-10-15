#include <iostream>
#include <cstring>

#include "Factory.hpp"

Factory::Factory(): _regex("poiuytrewqlkjhgfdsamnbvcxzPOIUYTREWQLKJHGFDSAMNBVCXZ:- \t0987654321_."), _status(true), _curr_type(NULL) {
}

Factory::~Factory() {
  _it_infra it;

  it = this->_map_infra.begin();
  for (; it != this->_map_infra.end(); it++)
    delete (*it).second;
}

bool  Factory::get_status() const { return this->_status; }

bool  Factory::_get_type(const std::string &token) {
  _it_infra         it;

  if (this->_curr_type)
    return TYPE_FOUND;

  it = this->_map_infra.find(token);
  if (it == this->_map_infra.end())
    return NO_TYPE_FOUND;

  this->_curr_type_name = it->second->get_type();
  return TYPE_FOUND;
}

bool  Factory::_validate_character(t_params &params, std::string::iterator it, const size_t depth) {
  if (this->_regex.find(*it) == static_cast<size_t>(-1))
    return BAD_REGEX;

  if (*it == TAB)
    params.tabs++;

  if (params.tabs > depth)
    return INCORRECT_DEPTH;
  else if (params.tabs and params.attribute and *it == ARRAY)
    return BAD_ARRAY;

  if (*it == ARRAY and !params.attribute)
    params.array = true;
  else if (*it == ATTRIBUTE)
    params.attribute = true;
  return VALIDATE_CHAR_OK;
}

size_t  Factory::_validate_param(std::string &src, const size_t depth) {
  std::string::iterator it;
  t_params  params;

  std::memset(&params, 0, sizeof(t_params));
  for (it = src.begin(); it != src.end(); it++) {
    if (this->_validate_character(params, it, depth))
      return BAD_PARAMETER;
  }

  if (!params.array and !params.attribute)
    return NO_KEYS;

  if (!params.array and (*(it--) == ATTRIBUTE))
    return IS_OBJECT;
  else if (params.attribute and !params.array and (*(it--) != ATTRIBUTE))
    return IS_ATTRIBUTE;
  else if (params.attribute and params.array)
    return IS_ARRAY;
  return UNKNOWN;
}

AInfrastructure  *Factory::create(Parser &parser, const std::string &token) {

  std::string param;
  AInfrastructure *holder;

  if (this->_get_type(token))
    return NULL;

  holder = NULL;
  //TODO create type
  while (true) {
    
    if (parser.get_token(param)) {
      this->_status = false;
      return this->_curr_type;
    }
    switch (this->_validate_param(param, 1))
    {
      case 0:
        /* code */
        std::cerr << "Error: unknown parameter!\r\n";
        break;

      case 1:
        /* code */
        this->_curr_type->fill(param, 1);
        break;

      case 2:
        /* code */
        this->_curr_type->fill(param, 2);
        break;

      case 3:
        if (this->_curr_type) {
          holder = this->_curr_type;
        }
        this->_curr_type = this->_map_infra[this->_curr_type_name]->clone();
        this->_curr_type->fill(param, 3);
        if (holder)
          return holder;
        break;
    
      default:
          break;
    }
  }

  return this->_curr_type;
}


bool  Factory::learn(AInfrastructure *infra) {
  _it_infra it;
  std::string type_name;

  type_name = infra->get_type();
  it = this->_map_infra.find(type_name);
  if (it != this->_map_infra.end())
    return EXISTS;

  this->_map_infra[type_name] = infra->clone();
  return SUCCESS;
}

