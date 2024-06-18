/*
** EPITECH PROJECT, 2018
** my_engine.c
** File description:
**
*/

#include "torus.h"

void process(struct request *request)
{
	if (request->opt == 1)
		bissection(request);
	else if (request->opt == 2)
		newton(request);
	else
		secante(request);
}

void bissection(struct request *request)
{
	double first_pt = 0;
	double scd_pt = 1;
	double first_xm;
	double scd_xm;
	double xm;

	for (int i = 1; i < 300; ++i) {
		xm = (first_pt + scd_pt) / 2;
		if (i <= request->precision)
			printf("x = %.*f\n", i, xm);
		else
			printf("x = %.*f\n", request->precision, xm);
		first_xm = (request->coef[4] * pow(xm, 4)) +
		(request->coef[3] * pow(xm, 3)) +
		(request->coef[2] * pow(xm, 2)) +
		(request->coef[1] * xm) + request->coef[0];
		scd_xm = ((request->coef[4] * pow(first_pt, 4)) +
		(request->coef[3] * pow(first_pt, 3)) +
		(request->coef[2] * pow(first_pt, 2)) +
		(request->coef[1] * first_pt) + request->coef[0]);
		if (scd_xm * first_xm < 0)
			scd_pt = xm;
		else
			first_pt = xm;
		if (round(first_pt * pow(10, request->precision)) ==
			round(scd_pt * pow(10, request->precision)))
			break;
	}
}

void newton(struct request *request)
{
	double xn_ = 0.5;
	double first_xn;
	double scd_xn;
	double xn;

	for (int i = 1; i < 300; ++i) {
		first_xn = (request->coef[4] * pow(xn_, 4)) +
		(request->coef[3] * pow(xn_, 3)) +
		(request->coef[2] * pow(xn_, 2)) +
		(request->coef[1] * xn_) + request->coef[0];
		scd_xn = (4 * (request->coef[4] * pow(xn_, 3))) +
		(3 * (request->coef[3] * pow(xn_, 2))) +
		(2 * request->coef[2] * xn_) + request->coef[1];
		if (scd_xn == 0)
			report_error("Division by zero.\n");
		xn = xn_ - (first_xn / scd_xn);
		if (round(xn_ * pow(10, request->precision)) ==
			round(xn * pow(10, request->precision)))
			break;
		if (i == 1)
			printf("x = %.1f\n", xn);
		printf("x = %.*f\n", request->precision, xn);
		xn_ = xn;
	}
}

void secante(struct request *request)
{
	double first_pt = 0;
	double scd_pt = 1;
	double first_xn;
	double scd_xn;
	double xn;

	for (int i = 1; i < 300; ++i) {
		if (round(first_pt * pow(10, request->precision)) ==
			round(scd_pt * pow(10, request->precision)))
			break;
		first_xn = (request->coef[4] * pow(first_pt, 4)) +
		(request->coef[3] * pow(first_pt, 3)) +
		(request->coef[2] * pow(first_pt, 2)) +
		(request->coef[1] * first_pt) + request->coef[0];
		scd_xn = (request->coef[4] * pow(scd_pt, 4)) +
		(request->coef[3] * pow(scd_pt, 3)) +
		(request->coef[2] * pow(scd_pt, 2)) +
		(request->coef[1] * scd_pt) + request->coef[0];
		if ((scd_xn - first_xn) == 0)
			report_error("Division by zero.\n");
		xn = scd_pt - ((scd_xn) *
		(scd_pt - first_pt) /
		(scd_xn - first_xn));
		if (i == 1)
			printf("x = %.1f\n", xn);
		else
			printf("x = %.*f\n", request->precision, xn);
		first_pt = scd_pt;
		scd_pt = xn;
	}
}