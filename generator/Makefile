##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	./src/engine_perfect.c \
		./src/engine.c \
		./src/instances.c \
		./src/main.c \
		./src/map.c \
		./src/output.c \
		./src/pathfinder.c \
		./src/string.c \
		./src/utils.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Werror -Wextra -pedantic -std=c99 \
		-I include -ggdb3 -Ofast

LDFLAGS	+=	-lm

NAME	=	generator

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)
		cp $(NAME) ../tournament/$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f ../tournament/$(NAME)

re:		fclean all

.PHONY:		all clean fclean re
