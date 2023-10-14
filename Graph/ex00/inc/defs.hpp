#ifndef DEFS_HPP
# define DEFS_HPP

# define ZERO          0
# define FINISHED      true
# define NOT_FINISHED  false
# define EQUAL         1
# define NOT_EQUAL     0
# define BUFFER_SIZE 1024
# define PATTERN "\n"
# define TOKEN_OK false
# define TOKENIZER_OK false

//Errors
# define ERR_BAD_ARGUMENTS  true
# define ERR_STILL_USING    true

# define NO_TYPE_SET  true
# define NO_CALLBACK  true
# define NO_TYPE_FOUND true
# define NO_TYPE      NULL
# define ARRAY            '-'
# define ATTRIBUTE        ':'
# define TAB              '\t'
# define BAD_REGEX        true
# define INCORRECT_DEPTH  true
# define BAD_ARRAY        true
# define NO_KEYS          true
# define BAD_PARAMETER    true
# define IS_OBJECT        1
# define IS_ATTRIBUTE     2
# define IS_ARRAY         3
# define UNKNOWN          0
# define VALIDATED_PARAM  false
# define VALIDATE_CHAR_OK false
# define TYPE_FOUND       false

# define AIRPORT_NAME "airport:"
# define ISSPACE " \t\r\n:"

# define EXISTS true
# define SUCCESS false

typedef struct s_params {
  size_t  tabs;
  bool  attribute;
  bool  array;
} t_params;

#endif //REFS_HPP