/*
** EPITECH PROJECT, 2017
** pathfinder.c
** File description:
**
*/

#include "generator.h"

int path_possible(struct request *req)
{
	struct cell *start = req->cells[0];
	struct cell *end =  req->cells[req->len - 1];
	int len = req->map_width + req->map_height;
	int call = false;

	if (len > 300)
		len = 200;
	if (start == NULL || end == NULL)
		return (false);
	if (end->state != EMPTY || start->state != EMPTY)
		return (false);
	for (int i = 0; i < len; i++) {
		clear_map_finder(req);
		call = find_path(req, start, end);
		if (call == 0 && i + 1 >= req->map_width+ req->map_height)
			return (false);
		else if (call == true)
			return (true);
	}
	return (false);
}

int find_path(struct request *req, struct cell *start, struct cell *end)
{
	struct cell *current = start;
	int turn = 0;

	start->state = USED;
	while (current->end != true) {
		current = find_nearest(req, current, end);
		if (current == NULL || turn > req->len)
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

	if (current->id + 1 <= req->len - 1 &&
		current->y == req->cells[current->id + 1]->y)
		bucket[0] = get_cell_by_id(req, current->id + 1);
	else
		bucket[0] = NULL;
	if (current->id - 1 >= 0 &&
		current->y == req->cells[current->id - 1]->y)
		bucket[1] = get_cell_by_id(req, current->id - 1);
	else
		bucket[1] = NULL;
	bucket[2] = get_cell_by_id(req, current->id + req->map_width);
	bucket[3] = get_cell_by_id(req, current->id - (req->map_width));
	nearest = clean_bucket(req, bucket, end);
	free(bucket);
	return (nearest);
}

struct cell *clean_bucket(struct request *req, struct cell **bucket,
	struct cell *end)
{
	const int bucket_size = 4;
	int dist = INT_MAX;
	struct cell *nearest = NULL;

	for (int i = 0; i < bucket_size; i++) {
		if (bucket[i] == NULL || bucket[i]->state != EMPTY ||
		!(bucket[i]->id >= 0 && bucket[i]->id <= req->len - 1))
			continue;
		if (bucket[i]->end == true)
			return (bucket[i]);
		if (manhattan_distance(bucket[i], end) < dist ||
			(manhattan_distance(bucket[i], end) <= dist
			&& rand() % 2 == 1)) {
			dist = manhattan_distance(bucket[i], end);
			nearest = bucket[i];
		}
	}
	return (nearest);
}

int manhattan_distance(struct cell *start, struct cell *end)
{
	double res = sqrt((start->x - end->x) * (start->x - end->x) +
		(start->y - end->y) * (start->y - end->y));

	return ((int)res);
}