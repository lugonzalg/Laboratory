#include "Network.hpp"

Network::Network() {}
Network::~Network() {}

void    Network::add_airport(Airport *airport) {
    this->network.push_back(airport);
}