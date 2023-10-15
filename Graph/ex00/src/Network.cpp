#include <iostream>

#include "Network.hpp"

Network::~Network() {}

void    Network::erase() {
    it_infra it;

    it = this->_infra.begin();
    for (; it != this->_infra.end(); it++)
    {
        std::cout << "destroy: " << (*it).second;
        delete (*it).second;
    }

}

AInfrastructure    *Network::get_infra(const std::string &name) const {
    cit_infra    it;

    it = this->_infra.find(name);
    if (it != this->_infra.end())
        return (*it).second;
    return NULL;
};

//TODO handle existing infra
void    Network::set_infra(AInfrastructure *infra) {
    std::string name;

    name = infra->get_name();
    this->_infra[name] = infra;
}

void    Network::delete_infra(const std::string &name) {
    it_infra    it;

    it = this->_infra.find(name);
    if (it != this->_infra.end())
        this->_infra.erase(it);
}