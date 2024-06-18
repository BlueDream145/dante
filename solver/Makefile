##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

LIB	=	../common/src/string.c \
		../common/src/output.c \

SRC	=	$(LIB) \
		./src/engine.c \
		./src/instances.c \
		./src/main.c \
		./src/map.c \
		./src/math.c \
		./src/reader.c

OBJ		=	$(SRC:.c=.o)

CC		=	cc -o

## @Variables

NAME		=	solver

INCLUDE		=	-I include -I ../common/include

## @Flags

CFLAGS		+=	-Wall -Werror -Wextra

CPPFLAGS	+=	$(INCLUDE) -Ofast

LDFLAGS		+=	-lm

## @Make

REMOVE		=	rm -f

BUILD		=	make -C

M_CLEAN		=	clean

M_FCLEAN	=	fclean

ALL		=	all

## @Job

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDFLAGS)
		cp $(NAME) ../tournament/$(NAME)

clean:
		$(REMOVE) $(OBJ)

fclean:		$(M_CLEAN)
		$(REMOVE) $(NAME)
		$(REMOVE) ../tournament/$(NAME)

re:		$(M_FCLEAN) $(ALL)

.PHONY:		$(ALL) $(M_CLEAN) $(M_FCLEAN) re