#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <map>
#include <string>

#include "AInfrastructure.hpp"

class Network
{
    public:

        typedef std::map<const std::string, AInfrastructure *>::const_iterator cit_infra;
        typedef std::map<std::string, AInfrastructure*>::iterator it_infra;

        Network() {}
        ~Network();

        AInfrastructure    *get_infra(const std::string &name) const;
        void    set_infra(AInfrastructure *infra);
        void    delete_infra(const std::string &name);
        void    erase();

    protected:

    private:

        std::map<const std::string, AInfrastructure *> _infra;
};

#endif //NETWORK_HPP