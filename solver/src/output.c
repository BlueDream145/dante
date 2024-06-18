/*
** EPITECH PROJECT, 2018
** output.c
** File description:
**
*/

#include "solver.h"

void my_put_char(char c)
{
	write(1, &c, 1);
}

void my_put_str(const char *str)
{
	for (int i = 0; str[i]; i++)
		my_put_char(str[i]);
}