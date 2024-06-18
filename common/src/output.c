/*
** EPITECH PROJECT, 2018
** output.c
** File description:
**  
*/

#include <unistd.h>

#include "string.h"

void my_put_char(char c)
{
	write(1, &c, 1);
}

void my_put_str(const char *str)
{
	write(1, str, my_strlen(str));
}