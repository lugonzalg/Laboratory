#ifndef FACTORY_HPP
# define FACTORY_HPP

#include <string>
#include <deque>
#include <map>

#include "Token.hpp"
#include "AInfrastructure.hpp"

class Factory
{
    public:

        Factory();
        ~Factory();

        bool    learn(AInfrastructure *infra);
        bool    create(std::deque<Token *> &tokens, std::deque<AInfrastructure *> &elements);
    protected:

    private:
        std::map<std::string, AInfrastructure *>                    __map_builder;
        std::map<std::string, AInfrastructure *>::iterator          __it_builder;
        typedef std::map<std::string, AInfrastructure *>::iterator  __it_infra;

        AInfrastructure *__curr_builder;

        bool                __set_builder(const std::string &key);
        AInfrastructure     *__new_infra();
};

#endif //FACTORY_HPP