/*
** EPITECH PROJECT, 2018
** map.c
** File description:
**
*/

#include "generator.h"

static const char cells_state[2] = { '*', 'X' };

char get_state_value(int state)
{
	const int state_len = 2;

	for (int i = 0; i < state_len; i++)
		if (i == state)
			return (cells_state[i]);
	return (-1);
}

struct cell *get_cell_by_id(struct request *req, int id)
{
	if (id >= 0 && id < req->len)
		return (req->cells[id]);
	return (NULL);
}

void clear_map(struct request *req)
{
	for (int i = 0; i < req->len; i++)
		req->cells[i]->state = EMPTY;
}

void fill_map(struct request *req)
{
	for (int i = 0; i < req->len; i++)
		req->cells[i]->state = FILL;
	req->cells[0]->state = EMPTY;
	req->cells[1]->state = EMPTY;
	req->cells[req->map_width]->state = EMPTY;
	req->cells[req->len - 1]->state = EMPTY;
	req->cells[req->len - 2]->state = EMPTY;
	req->cells[req->len - 1 - req->map_width]->state = EMPTY;
}

void clear_map_finder(struct request *req)
{
	struct cell *start = req->cells[0];
	struct cell *end =  req->cells[req->len - 1];

	start->start = true;
	end->end = true;
	for (int i = 0; i < req->len; i++)
		if (req->cells[i]->state == USED)
			req->cells[i]->state = EMPTY;
}