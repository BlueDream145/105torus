/*
** EPITECH PROJECT, 2018
** my_get.c
** File description:
**
*/

#include "torus.h"

struct request *get_request(char **as)
{
	const int coef_len = 5;
	struct request *request = malloc(sizeof(struct request));

	request->coef = malloc(sizeof(double) * coef_len);
	if (request == NULL || request->coef == NULL)
		report_malloc();
	request->opt = atof(as[1]);
	for (int i = 0; i < coef_len; i++)
		request->coef[i] = atoi(as[i + 2]);
	request->precision = atof(as[7]);
	return (request);
}