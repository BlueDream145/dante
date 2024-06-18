/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**  
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

#include "solver.h"
#include "string.h"
#include "engine.h"

static const char cells_value[3] = { '*', 'X', 'o' };
static const int exit_normal = 0;
static const int exit_fail = 84;

int main(int ac, char **as)
{
	struct request *req = NULL;
	char *file_name = as[1];
	char *content = read_file(file_name);

	srand(time(NULL));
	if (ac != 2 || !file_name ||
		open(file_name, O_RDONLY) <= 0 ||
		check_file(content) == false ||
		(req = get_instance(file_name)) == NULL ||
		!req->cells[0] || !req->cells[req->real_len - 1])
		return (exit_fail);
	process(req);
	free_instance(req);
	if (content != NULL)
		free(content);
	return (exit_normal);
}

int check_file(char *content)
{
	int map_width = 0;
	int line = 0;
	int tmp = 0;

	if (content == NULL || my_strlen(content) < 5)
		return (false);
	map_width = get_map_width(content);
	for (int i = 0; content[i]; i++) {
		if (content[i] != cells_value[EMPTY] &&
			content[i] != cells_value[FILL] && content[i] != '\n')
			return (false);
		if (content[i] == '\n')
			line++;
		if (line != 0 && content[i] == '\n'
			&& i - (line * map_width) - tmp != 0)
			return (false);
		if (line != 0 && content[i] == '\n')
			tmp++;
	}
	return (true);
}