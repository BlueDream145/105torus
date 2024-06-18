/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "torus.h"

int main(int ac, char **as)
{
	const int exit_success = 0;
	struct request *request;

	check(ac, as);
	request = get_request(as);
	process(request);
	free(request);
	return (exit_success);
}

void check(int ac, char **as)
{
	const int false = 0;
	const int args_count = 8;

	if (ac != args_count)
		report_bad_usage();
	if (atoi(as[1]) != 1 && atoi(as[1]) != 2 && atoi(as[1]) != 3)
		report_bad_syntax();
	for (int i = 1; i < ac; i++)
		if (my_str_isnum(as[i]) == false)
			report_bad_syntax();
}