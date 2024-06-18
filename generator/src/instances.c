/*
** EPITECH PROJECT, 2018
** instances.c
** File description:
**
*/

#include "generator.h"

struct request *get_instance(int ac, char **as)
{
	const char *perfect_value = "perfect";
	struct request *req = malloc(sizeof(struct request));

	if (req == NULL)
		return (NULL);
	req->map_width = my_getnbr(as[1]);
	req->map_height = my_getnbr(as[2]);
	req->perfect = false;
	if (ac == 4 && my_strcmp(as[3], perfect_value) == 0)
		req->perfect = true;
	req->len = req->map_width * req->map_height;
	req->cells = malloc(sizeof(struct cell*) * req->len);
	if (req->cells == NULL || serialize_instance(req) == false)
		return (NULL);
	return (req);
}

int serialize_instance(struct request *req)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < req->len; i++) {
		if ((req->cells[i] = malloc(sizeof(struct cell))) == NULL)
			return (false);
		if (i != 0 && i % req->map_width == 0) {
			x = 0;
			y++;
		}
		req->cells[i]->id = i;
		req->cells[i]->x = x;
		req->cells[i]->y = y;
		req->cells[i]->state = EMPTY;
		req->cells[i]->start = false;
		req->cells[i]->end = false;
		x++;
	}
	return (true);
}

void free_instance(struct request *req)
{
	if (req->cells != NULL) {
		for (int i = 0; i < req->len; i++)
			free(req->cells[i]);
		free(req->cells);
	}
	free(req);
}