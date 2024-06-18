##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/main.c \
		src/my_engine.c \
		src/my_error.c \
		src/my_get.c \
		src/my_string.c

CFLAGS	=	-Wall -Wextra

INCLUDE =	-I include -o

LIB	=	-g -lm

NAME	=	105torus

TESTS	=	tests

all:	$(NAME)

$(NAME):
	make -C $(TESTS)
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
