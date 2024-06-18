/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**
*/

#include "generator.h"

void process(struct request *req)
{
	if (req->perfect == false)
		process_imperfect(req);
	else
		process_perfect(req);
}

void process_perfect(struct request *req)
{
	struct cell *current = NULL;

	fill_map(req);
	while (true) {
		current = get_perfect_cell(req);
		if (current == NULL)
			break;
		current->state = EMPTY;
	}
	clear_alone_cells(req);
	if (path_possible(req) == false) {
		process_perfect(req);
		return;
	}
	clear_map_finder(req);
	compute_result(req);
}

void process_imperfect(struct request *req)
{
	struct cell *current = req->cells[rand() % req->len];
	int callback = false;

	while (true) {
		clear_map(req);
		req->cells[0]->state = EMPTY;
		for (int i = 0; i < req->len / 3.3; i++) {
			while (current->state != EMPTY || current->id == 0 ||
				current->id == req->len - 1)
				current = req->cells[rand() % req->len];
			current->state = FILL;
		}
		if ((callback = path_possible(req)) == true)
			break;
	}
	clear_map_finder(req);
	compute_result(req);
}

void compute_result(struct request *req)
{
	char *result = malloc(sizeof(char) * (req->len + req->map_width));
	int i = 0;
	int tmp = 0;

	if (result == NULL)
		return;
	for (; i - tmp < req->len && req->cells[i - tmp]; i++) {
		if (i != 0 && (i - tmp) % req->map_width == 0) {
			result[i] = '\n';
			i++;
			tmp++;
		}
		result[i] = get_state_value(req->cells[i - tmp]->state);
	}
	result[i++] = '\0';
	write(1, result, req->len + req->map_width);
	free(result);
}