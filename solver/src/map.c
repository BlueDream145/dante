/*
** EPITECH PROJECT, 2018
** map.c
** File description:
**  
*/

#include <stdlib.h>
#include <stdbool.h>

#include "engine.h"
#include "string.h"

static const char cells_value[3] = { '*', 'X', 'o' };

int get_map_width(const char *str)
{
	for (int i = 0; str[i]; i++)
		if (str[i] == '\n')
			return (i);
	return (0);
}

int get_map_height(const char *str)
{
	return (string_len(str, '\n') + 2);
}

void clear_map(struct request *req)
{
	struct cell *start = req->cells[0];
	struct cell *end =  req->cells[req->real_len - 1];

	start->start = true;
	end->end = true;
	for (int i = 0; i < req->real_len; i++)
		if (req->cells[i]->state == USED)
			req->cells[i]->state = EMPTY;
}

struct cell *get_cell_by_id(const struct request *req, const int id)
{
	if (id >= 0 && id < req->real_len)
		return (req->cells[id]);
	return (NULL);
}

int get_state(const char c)
{
	const int state_len = 3;

	for (int i = 0; i < state_len; i++)
		if (cells_value[i] == c)
			return (i);
	return (-1);
}