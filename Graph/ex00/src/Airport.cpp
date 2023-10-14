#include <sstream>

#include "Airport.hpp"
#include "Parser.hpp"

bool  Airport::fill(const std::string &param, const size_t type) {
  Parser  parser;
  _it_callback  it;
  std::string key;
  std::string value;

  parser.set_tokenizer(param, ISSPACE);
  if (type == 3)
    parser.get_token(key);

  parser.get_token(key);
  it = this->_map_fill_callback.find(key);
  if (it == this->_map_fill_callback.end())
    return true;

  parser.get_token(value);
  (this->*(it->second))(value);

  return false;
}
Airport *Airport::clone() { return new Airport; }

Airport::Airport(): AInfrastructure(AIRPORT_NAME) {
  this->_map_fill_callback["id"] = &Airport::_set_id;
  this->_map_fill_callback["name"] = &Airport::_set_name;
  this->_map_fill_callback["city"] = &Airport::_set_city;
  this->_map_fill_callback["country"] = &Airport::_set_country;
  this->_map_fill_callback["iata_code"] = &Airport::_set_iata_code;
  this->_map_fill_callback["longitude"] = &Airport::_set_longitude;
  this->_map_fill_callback["latitude"] = &Airport::_set_latitude;
}

//setters

void  Airport::_set_id(const std::string &param) { this->_id = std::atoi(param.c_str()); }
void  Airport::_set_name(const std::string &param) { this->_name = param; }
void  Airport::_set_city(const std::string &param) { this->_city = param; }
void  Airport::_set_country(const std::string &param) { this->_country = param; }
void  Airport::_set_iata_code(const std::string &param) { this->_iata_code = param; }
void  Airport::_set_latitude(const std::string &param) { this->_latitude = std::atof(param.c_str()); }
void  Airport::_set_longitude(const std::string &param) { this->_longitude = std::atof(param.c_str()); }
  
std::string Airport::get_log() {
    std::stringstream ss;

    ss << "Airport Details:\n";
    ss << "----------------\n";
    ss << "ID: " << this->_id << "\n";
    ss << "Name: " << this->_name << "\n";
    ss << "City: " << this->_city << "\n";
    ss << "Country: " << this->_country << "\n";
    ss << "IATA Code: " << this->_iata_code << "\n";
    ss << "Latitude: " << this->_latitude << "\n";
    ss << "Longitude: " << this->_longitude << "\n";

    return ss.str();
}

std::ostream &operator<<(std::ostream &os, Airport &ap) {
    os << ap.get_log();
    return os;
}