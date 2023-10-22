#include "AInfrastructure.hpp"

const std::string &AInfrastructure::get_name() {
  return this->__name;
}

const std::string &AInfrastructure::get_type() {
  return this->__type;
}

AInfrastructure::AInfrastructure(const std::string &type): __type(type) {}
