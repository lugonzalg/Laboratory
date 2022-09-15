#!/bin/bash

echo \
"NAME	= auto

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3
SNTZ	= -fsanitize=address

FILES	= main

SRC 	= \$(addsuffix .c, \$(FILES))
OBJ 	= \$(addsuffix .o, \$(FILES))

.c.o:
	\$(CC) \$(CFLAGS) \$(SNTZ) -o \$@ -c $^

\$(NAME): \$(OBJ)
	\$(CC) \$(CFLAGS) \$(SNTZ) -o \$(NAME) \$(OBJ)

all: \$(NAME)

clean:
	\$(RM) \$(OBJ)

fclean: clean
	\$(RM) \$(NAME)

re: fclean all

.PHONY: all clean fclean re" > Makefile

vim Makefile
