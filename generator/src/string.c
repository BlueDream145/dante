/*
** EPITECH PROJECT, 2018
** string.c
** File description:
**
*/

#include "generator.h"

int my_strlen(const char *str)
{
	int len = 0;

	for (; str[len]; len++);
	return (len);
}

int my_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++);
	return (s1[i] - s2[i]);
}