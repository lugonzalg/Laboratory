#include <stdexcept>

#include "Airport.hpp"

Airport::Airport() {
    this->kv_callback["id"] = &Airport::set_id;
}

Airport::~Airport() {}

void    Airport::handle_keyword(std::deque<std::string> *keywords) {
    std::string     key;
    it_key_value    kv_it;
    AParam          test;

    key = keywords->front();
    keywords->pop_front();
    kv_it = this->kv_callback.find(key);
    test.set_value(keywords->front());
    keywords->pop_front();

    if (kv_it != this->kv_callback.end())
        (this->*(kv_it->second))(test);
}

//SETTERS

void  Airport::set_id(const AParam &param) {this->id = param.get_value<int>();}
void  Airport::set_name(const AParam &param) {this->name = param.get_value<std::string>();}
void  Airport::set_city(const AParam &param) {this->city = param.get_value<std::string>();}
void  Airport::set_country(const AParam &param) {this->country = param.get_value<std::string>();}
void  Airport::set_iata_code(const AParam &param) {this->iata_code = param.get_value<std::string>();}
void  Airport::set_coordinates(const AParam &param) {this->coordinates = param.get_value<std::pair<float, float> >();}