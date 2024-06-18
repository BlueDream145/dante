/*
** EPITECH PROJECT, 2018
** string.c
** File description:
**  
*/

#include "string.h"

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

int string_len(const char *str, const char c)
{
	int len = 0;

	for (int i = 0; str[i]; i++)
		if (str[i] == c)
			len++;
	return (len);
}