/*
** EPITECH PROJECT, 2018
** my_string.c
** File description:
**
*/

#include "torus.h"

int my_str_isnum(char const *str)
{
	const int true = 1;
	const int false = 0;
	int i = 0;
	int result = false;

	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] <= '9' && str[i] >= '0')
			|| str[i] == '-')
			result = true;
		else
			return (false);
	}
	return (result);
}