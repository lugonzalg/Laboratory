#ifndef PARAMS_HPP
# define PARAMS_HPP

#include <string>
#include <stdexcept>

class AParam {
    public:
        virtual ~AParam() {}

        template<typename T>
        T get_value() const { throw std::runtime_error("Error: unsuported type!"); }

        void set_value(int value) { this->int_value = value; }

        void set_value(const std::string &value) { this->str_value = value; }

        void set_value(const std::pair<float, float> &value) { this->pair_value = value; }

        int int_value;
        std::string str_value;
        std::pair<float, float> pair_value;
};

#endif //PARAMS