/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef GENERATOR_
	#define GENERATOR_

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <time.h>
	#include <math.h>
	#include <limits.h>

	#define EXIT_NORMAL (0)
	#define EXIT_FAIL (84)

struct request {
	struct cell **cells;
	int len;
	int map_width;
	int map_height;
	int perfect;
};

struct cell {
	int id;
	int x;
	int y;
	int state;
	int start;
	int end;
};

enum cell_state {
	UNINITIALIZED = -1,
	EMPTY,
	FILL,
	USED
};

// engine_perfect.c
struct cell *get_perfect_cell(struct request *req);
void clear_alone_cells(struct request *req);

// engine.c
void process(struct request *req);
void process_perfect(struct request *req);
void process_imperfect(struct request *req);
void compute_result(struct request *req);

// instances.c
struct request *get_instance(int ac, char **as);
int serialize_instance(struct request *req);
void free_instance(struct request *req);

// main.c
int check(int ac, char **as);

// map.c
char get_state_value(int state);
struct cell *get_cell_by_id(struct request *req, int id);
void fill_map(struct request *req);
void clear_map(struct request *req);
void clear_map_finder(struct request *req);

// output.c
void my_put_char(char c);
void my_put_str(const char *str);

// pathfinder.c
int path_possible(struct request *req);
int find_path(struct request *req, struct cell *start, struct cell *end);
struct cell *find_nearest(struct request *req, struct cell *current,
	struct cell *end);
struct cell *clean_bucket(struct request *req, struct cell **bucket,
	struct cell *end);
int manhattan_distance(struct cell *start, struct cell *end);

// string.c
int my_strlen(const char *str);
int my_strcmp(const char *s1, const char *s2);

// utils.c
int my_getnbr(char *str);

#endif /* GENERATOR */