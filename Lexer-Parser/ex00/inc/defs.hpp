#ifndef DEFS_HPP
# define DEFS_HPP

typedef enum e_types {
    NONE,
    ATTRIBUTE,
    OBJECT,
    ITEM_ATTR,
    ITEM_OBJECT
}   t_types;

typedef struct s_pattern {
    int alpha;
    int indent;
    int dash;
    int two_point;
}   t_pattern;

typedef struct s_params
{
    __uint8_t state_machine;
    __uint8_t tabs;
    __uint8_t spaces;
    std::string key;
    std::string value;
}   t_params;

#endif //DEFS_HPP