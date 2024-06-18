/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef torus_
#define torus_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

struct request {
	double opt;
	int precision;
	double *coef;
};

// main.c
void check(int ac, char **as);

// my_engine.c
void process(struct request *request);
void bissection(struct request *request);
void newton(struct request *request);
void secante(struct request *request);

// my_error.c
void report_malloc();
void report_bad_usage();
void report_bad_syntax();
void report_error(const char *str);

// my_get.c
struct request *get_request(char **as);

// my_string.c
int my_str_isnum(char const *str);

#endif /* torus */