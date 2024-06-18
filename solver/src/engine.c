/*
** EPITECH PROJECT, 2018
** engine.c
** File description:
**  
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "engine.h"
#include "output.h"

static const char cells_value[3] = { '*', 'X', 'o' };
static const char *no_solution = "no solution found\n";

void process(struct request *req)
{
	struct cell *start = req->cells[0];
	struct cell *end =  req->cells[req->real_len - 1];
	int call = false;

	if (start == NULL || end == NULL)
		return;
	if (end->state != EMPTY || start->state != EMPTY) {
		my_put_str(no_solution);
		return;
	}
	for (int i = 0; i < req->map_width * req->map_height * 4; i++) {
		clear_map(req);
		call = find_path(req, start, end);
		if (call == 0 && i + 1 >=
			req->map_width * req->map_height * 4) {
			my_put_str(no_solution);
			return;
		} else if (call == true)
			break;
	}
	compute_result(req);
}

int find_path(struct request *req, struct cell *start, struct cell *end)
{
	struct cell *current = start;
	int turn = 0;

	start->state = USED;
	while (current->end != true) {
		current = find_nearest(req, current, end);
		if (current == NULL || turn > req->cells_len)
			break;
		current->state = USED;
		if (current->end == true)
			return (true);
		turn++;
	}
	return (false);
}

struct cell *find_nearest(struct request *req, struct cell *current,
	struct cell *end)
{
	const int bucket_size = 4;
	struct cell **bucket = malloc(sizeof(struct cell*) * bucket_size);
	struct cell *nearest = NULL;

	if (current->id + 1 <= req->real_len - 1 &&
		current->y == req->cells[current->id + 1]->y)
		bucket[0] = get_cell_by_id(req, current->id + 1);
	else
		bucket[0] = NULL;
	if (current->id - 1 >= 0 &&
		current->y == req->cells[current->id - 1]->y)
		bucket[1] = get_cell_by_id(req, current->id - 1);
	else
		bucket[1] = NULL;
	bucket[2] = get_cell_by_id(req, current->id + req->map_width + 1);
	bucket[3] = get_cell_by_id(req, current->id - (req->map_width + 1));
	nearest = clean_bucket(req, bucket, end, current);
	free(bucket);
	return (nearest);
}

void compute_result(struct request *req)
{
	char *result = malloc(sizeof(char) * (req->real_len + 2));
	int i = 0;

	if (result == NULL)
		return;
	for (; i < req->real_len && req->cells[i]; i++)
		if (req->cells[i]->state < 0)
			result[i] = '\n';
		else
			result[i] = cells_value[req->cells[i]->state];
	result[i++] = '\n';
	result[i++] = '\0';
	write(1, result, req->real_len + 2);
	free(result);
}