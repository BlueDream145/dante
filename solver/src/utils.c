/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
**
*/

#include "solver.h"

int my_strlen(const char *str)
{
	int len = 0;

	for (; str[len]; len++);
	return (len);
}

int string_len(char *str, char c)
{
	int len = 0;

	for (int i = 0; str[i]; i++)
		if (str[i] == c)
			len++;
	return (len);
}