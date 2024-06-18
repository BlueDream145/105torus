/*
** EPITECH PROJECT, 2018
** my_error.c
** File description:
**
*/

#include "torus.h"

void report_malloc()
{
	const char *error = "Fatal error: malloc failed.\n";

	report_error(error);
}

void report_bad_usage()
{
	const char *error = "Bad usage.\n";

	report_error(error);
}

void report_bad_syntax()
{
	const char *error = "Bad syntax.\n";

	report_error(error);
}

void report_error(const char *str)
{
	const int output_error = 2;
	int len = 0;

	for (len = 0; str[len]; len++);
	write(output_error, str, len);
	exit(84);
}