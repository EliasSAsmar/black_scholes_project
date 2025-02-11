#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

#include <cmath>

double normalCDF(double x);

double calculate_d1(double S, double X, double T, double r, double sigma);
double calculate_d2(double d1, double sigma, double T);

double blackScholesCall(double S, double X, double T, double r, double sigma);
double blackScholesPut(double S, double X, double T, double r, double sigma);

#endif // BLACK_SCHOLES_H
