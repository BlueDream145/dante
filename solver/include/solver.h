/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef SOLVER_
	#define SOLVER_

struct request {
	struct cell **cells;
	int cells_len;
	int real_len;
	int map_width;
	int map_height;
};

struct cell {
	int id;
	int x;
	int y;
	int start;
	int end;
	int state;
};

enum cell_state {
	EMPTY,
	FILL,
	USED
};

// instances.c
struct request *get_instance(const char *file_name);
struct cell *get_cell(int id, int x, int y, int state);
int serialize_instance(struct request *req, char *content);
void free_instance(struct request *req);

// main.c
int check_file(char *content);

// reader.c
char *read_file(const char *file_name);
char *get_line(const char *str, const int start);

#endif /* SOLVER */