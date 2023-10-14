#include "AInfrastructure.hpp"

const std::string &AInfrastructure::get_type() {
  return this->_type;
}

AInfrastructure::AInfrastructure(const std::string &type): _type(type) {}
