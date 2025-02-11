/**
 * @file monte_carlo.h
 * @author Eli Asmar
 *
 *
 */

#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <cmath>
#include <random>
#include <algorithm>
#include <omp.h>

std::vector<double> simulateStockPrice(double S, double T, double r, double sigma);

double monteCarloCall(int numSimulations, double S, double X, double T, double r, double sigma);
double monteCarloPut(int numSimulations, double S, double X, double T, double r, double sigma);

#endif // MONTE_CARLO_H
