NAME		= Airport

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -g3 -std=c++98
SANITIZE	= -fsanitize=address
INC			= -I inc
RM			= rm -rf

FILES = src/main \
		src/Airport \
		src/Handler \
		src/Network 

SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

.cpp.o:
	$(CC) $(CFLAGS) $(SANITIZE) $(INC) -o $@ -c $^

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SANITIZE) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
