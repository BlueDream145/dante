/*
** EPITECH PROJECT, 2018
** engine_perfect.c
** File description:
**
*/

#include "generator.h"

struct cell *get_perfect_cell(struct request *req)
{
	struct cell *current = NULL;
	int len;
	int i = 0;

	while ((current = req->cells[rand() % req->len]) != NULL
		&& i < req->len * 2) {
		if (current->state != FILL)
			continue;
		len = 4;
		if (!(current->id + 1 < req->len &&
			req->cells[current->id + 1]->state == FILL))
			len--;
		if (!(current->id - 1 >= 0 &&
			req->cells[current->id - 1]->state == FILL))
			len--;
		if (!(current->id + req->map_width < req->len &&
			req->cells[current->id +
			req->map_width]->state == FILL))
			len--;
		if (!(current->id - (req->map_width) >= 0 &&
			req->cells[current->id -
			req->map_width]->state == FILL))
			len--;
		if (len == 3)
			return (current);
		i++;
	}
	return (NULL);
}

void clear_alone_cells(struct request *req)
{
	struct cell *current;
	int len = 4;

	for (int i = 0; i < req->len && (current = req->cells[i]) != NULL; i++) {
		if (current->state != FILL)
			continue;
		len = 4;
		if (current->id + 1 < req->len && req->cells[current->id + 1]->y == current->y &&
			req->cells[current->id + 1]->state == FILL)
			len--;
		if (current->id - 1 >= 0 && req->cells[current->id - 1]->y == current->y &&
			req->cells[current->id - 1]->state == FILL)
			len--;
		if (current->id + req->map_width < req->len &&
			req->cells[current->id +
			req->map_width]->state == FILL)
			len--;
		if (current->id - (req->map_width) >= 0 &&
			req->cells[current->id -
			req->map_width]->state == FILL)
			len--;
		if (len == 4)
			current->state = EMPTY;

	}
}