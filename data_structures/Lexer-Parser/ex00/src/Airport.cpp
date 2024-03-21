#include <sstream>
#include <cstdlib>

#include "Airport.hpp"
#include "Parser.hpp"

Airport *Airport::clone() { return new Airport; }

void  Airport::set_value(const std::string &value) {
  this->__curr_setter = this->__setters.find(value);
}

void  Airport::add_value(const std::string &value) {
  if (this->__curr_setter != this->__setters.end())
    (this->*(__curr_setter->second))(value);
}

Airport::Airport(): AInfrastructure(AIRPORT_NAME) {
  this->__setters["id:"] = &Airport::__set_id;
  this->__setters["description:"] = &Airport::__set_description;
  this->__setters["city:"] = &Airport::__set_city;
  this->__setters["country:"] = &Airport::__set_country;
  this->__setters["iata_code:"] = &Airport::__set_iata_code;
  this->__setters["longitude:"] = &Airport::__set_longitude;
  this->__setters["latitude:"] = &Airport::__set_latitude;

  this->__curr_setter = this->__setters.end();
}

//setters

void  Airport::__set_id(const std::string &param) { this->__id = std::atoi(param.c_str()); }
void  Airport::__set_description(const std::string &param) { this->__description = param; }
void  Airport::__set_city(const std::string &param) { this->__city = param; }
void  Airport::__set_country(const std::string &param) { this->__country = param; }
void  Airport::__set_iata_code(const std::string &param) { this->__name = param; }
void  Airport::__set_latitude(const std::string &param) { this->__latitude = std::atof(param.c_str()); }
void  Airport::__set_longitude(const std::string &param) { this->__longitude = std::atof(param.c_str()); }
  
std::string Airport::get_log() {
    std::stringstream ss;

    ss << "Airport Details:\n";
    ss << "----------------\n";
    ss << "Name: " << this->__name << "\n";
    ss << "ID: " << this->__id << "\n";
    ss << "City: " << this->__city << "\n";
    ss << "Country: " << this->__country << "\n";
    ss << "Description: " << this->__description << "\n";
    ss << "Latitude: " << this->__latitude << "\n";
    ss << "Longitude: " << this->__longitude << "\n";

    return ss.str();
}

std::ostream &operator<<(std::ostream &os, Airport &ap) {
    os << ap.get_log();
    return os;
}