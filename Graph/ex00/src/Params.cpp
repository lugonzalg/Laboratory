#include "Params.hpp"

template<>
int AParam::get_value<int>() const { return this->int_value; }

template<>
std::string AParam::get_value<std::string>() const { return this->str_value; }

template<>
std::pair<float, float> AParam::get_value<std::pair<float, float> >() const { return this->pair_value; }
