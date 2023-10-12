#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <deque>

#include "Airport.hpp"

class Network
{
    public:

        Network();
        ~Network();

        std::deque<Airport *>   network;

        void    add_airport(Airport *airport);

    protected:

    private:

};

#endif //NETOWRK_HPP