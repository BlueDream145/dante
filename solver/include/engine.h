/*
** EPITECH PROJECT, 2018
** ENGINE_H
** File description:
** Engine
*/

#ifndef ENGINE_H_
	#define ENGINE_H_

#include "solver.h"

// engine.c
void process(struct request *req);
int find_path(struct request *req, struct cell *start, struct cell *end);
struct cell *find_nearest(struct request *req, struct cell *current,
	struct cell *end);
void compute_result(struct request *req);

// map.c
int get_map_width(const char *str);
int get_map_height(const char *str);
void clear_map(struct request *req);
struct cell *get_cell_by_id(const struct request *req, const int id);
int get_state(const char c);

// math.c
int manhattan_distance(const struct cell *start, const struct cell *end);
struct cell *clean_bucket(const struct request *req, struct cell **bucket,
	const struct cell *end, const struct cell *current);
bool contain_index(int *buffer, int size, int id);

#endif /* !ENGINE_H_ */
