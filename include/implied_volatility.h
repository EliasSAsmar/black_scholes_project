#ifndef IMPLIED_VOLATILITY_H
#define IMPLIED_VOLATILITY_H
#include <cmath>
#include <math.h>
double impliedVolatility(double marketPrice, double S, double X, double T, double r, 
                         double initialGuess = 0.2, double tol = 1e-6, int maxIterations = 100);

#endif
