#ifndef DEFS_HPP
# define DEFS_HPP

typedef enum e_types {
    NONE,
    ATTRIBUTE,
    ITEM,
    OBJECT
}   t_types;

typedef struct s_pattern {
    int alpha;
    int indent;
    int dash;
    int two_point;
}   t_pattern;


#endif //DEFS_HPP