/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
**  
*/

#include <stdlib.h>
#include <stdbool.h>

#include "solver.h"
#include "engine.h"

struct request *get_instance(const char *file_name)
{
	struct request *req = malloc(sizeof(struct request));
	char *content = read_file(file_name);

	if (req == NULL || content == NULL)
		return (NULL);
	req->map_width = get_map_width(content);
	req->map_height = get_map_height(content);
	req->cells_len = req->map_width * req->map_height;
	req->real_len = 0;
	if (req->cells_len == 0)
		return (NULL);
	req->cells = malloc(sizeof(struct cell*) * req->cells_len);
	if (req->cells == NULL)
		return (NULL);
	if (serialize_instance(req, content) == false)
		return (NULL);
	free(content);
	return (req);
}

struct cell *get_cell(int id, int x, int y, int state)
{
	struct cell *cell = malloc(sizeof(struct cell));

	if (cell == NULL)
		return (NULL);
	cell->id = id;
	cell->x = x;
	cell->y = y;
	cell->state = state;
	cell->start = false;
	cell->end = false;
	return (cell);
}

int serialize_instance(struct request *req, char *content)
{
	int x = 0;
	int y = 0;

	for (int i = 0; content[i] && i < req->cells_len; i++) {
		req->cells[i] = get_cell(i, x, y, get_state(content[i]));
		if (req->cells[i] == NULL)
			return (false);
		if (i != 0 && x != 0 && content[i] == '\n') {
			x = 0;
			y++;
		} else
			x++;
		req->real_len++;
	}
	return (true);
}

void free_instance(struct request *req)
{
	if (req->cells != NULL) {
		for (int i = 0; i < req->real_len && req->cells[i]; i++)
			free(req->cells[i]);
		free(req->cells);
	}
	free(req);
}