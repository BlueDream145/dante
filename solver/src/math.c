/*
** EPITECH PROJECT, 2018
** math.c
** File description:
**  
*/

#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#include "engine.h"

int manhattan_distance(const struct cell *start, const struct cell *end)
{
	double res = sqrt((start->x - end->x) * (start->x - end->x) +
		(start->y - end->y) * (start->y - end->y));

	return ((int)res);
}

bool contain_index(int *buffer, int size, int id)
{
	for (int i = 0; i < size; i++)
		if (buffer[i] == id)
			return (true);
	return (false);
}

struct cell *clean_bucket(const struct request *req, struct cell **bucket,
	const struct cell *end, const struct cell *current)
{
	static int *buffer = NULL;
	static int index = 0;

	const int bucket_size = 4;
	int dist = INT_MAX;
	struct cell *nearest = NULL;
	int len = 0;
	if (buffer == NULL)
		buffer = malloc(sizeof(int) * req->real_len);
	for (int i = 0; i < bucket_size; i++) {
		if (bucket[i] == NULL || bucket[i]->state != EMPTY ||
		!(bucket[i]->id >= 0 && bucket[i]->id <= req->real_len - 1)
		|| contain_index(buffer, index, bucket[i]->id))
			continue;
		if (bucket[i]->end == true)
			return (bucket[i]);
		if (manhattan_distance(bucket[i], end) < dist ||
			(manhattan_distance(bucket[i], end) <= dist
			&& rand() % 2 == 1)) {
			dist = manhattan_distance(bucket[i], end);
			nearest = bucket[i];
		}
		len++;
	}
	if (len > 1) {
		buffer[index] = current->id;
		index++;
	}
	return (nearest);
}