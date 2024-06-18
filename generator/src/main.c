/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "generator.h"

int main(int ac, char **as)
{
	struct request *req = NULL;

	srand(time(NULL));
	if (check(ac, as) == false || (req = get_instance(ac, as)) == NULL)
		return (EXIT_FAIL);
	process(req);
	free_instance(req);
	return (EXIT_NORMAL);
}

int check(int ac, char **as)
{
	const char *perfect_value = "perfect";
	const char *imperfect_value = "imperfect";

	if (ac < 3 || ac > 4)
		return (false);
	if (my_getnbr(as[1]) <= 2 || my_getnbr(as[2]) <= 2)
		return (false);
	if (ac == 4 && my_strcmp(as[3], perfect_value) != 0 &&
		my_strcmp(as[3], imperfect_value) != 0)
		return (false);
	return (true);
}