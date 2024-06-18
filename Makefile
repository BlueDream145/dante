##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

GENERATOR	=	generator/

SOLVER		= 	solver/

OUTPUT		=	tournament/

all:
		mkdir -p $(OUTPUT)
		make -C $(GENERATOR)
		make -C $(SOLVER)

clean:
		make -C $(GENERATOR) clean
		make -C $(SOLVER) clean

fclean:		clean
		make -C $(GENERATOR) fclean
		make -C $(SOLVER) fclean

re:		fclean all

.PHONY:		all clean fclean re
