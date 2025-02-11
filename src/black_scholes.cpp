/**
 * @file black_scholes.cpp
 * @author Eli Asmar
 */

#include <iostream>
#include <cmath>

double normalCDF(double x)
{
    return .5 * (1+ std::erf(x/std::sqrt(2)));
    
}


double calculate_d1(double S, double X, double T, double r, double sigma)
{
    return (std::log(S / X) + (r + .5* std::pow(sigma,2))*T) / (sigma * std::sqrt(T));
}


double calculate_d2(double d1, double sigma, double T)
{
    return d1 - sigma * std::sqrt(T);
}

double blackScholesCall(double S, double X, double T, double r, double sigma)
{
    double d1 = calculate_d1(S, X, T, r, sigma);
    double d2 = calculate_d2(d1, sigma, T);
    return S * normalCDF(d1) - X * exp(-r * T) * normalCDF(d2);
}


double blackScholesPut(double S, double X, double T, double r, double sigma)
{
    double d1 = calculate_d1(S, X, T, r, sigma);
    double d2 = calculate_d2(d1, sigma, T);
    return X * exp(-r * T)* normalCDF(-d2) - S * normalCDF(-d1);

}

