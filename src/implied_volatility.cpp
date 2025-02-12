#include "../include/implied_volatility.h"
#include "../include/black_scholes.h"  // Needed for Black-Scholes functions


// Implement Newton-Raphson method here
double impliedVolatility(double marketPrice, double S, double X, double T, double r, 
                         double initialGuess, double tol, int maxIterations)
{   
    double sigma = initialGuess;
    int iteration = 0;
    double f_sigma = blackScholesCall(S, X, T, r, sigma) - marketPrice;
    
    while (std::abs(f_sigma) > tol && iteration < maxIterations)
    {   
        double d1 = calculate_d1(S, X, T, r, sigma);
        double vega = S * std::sqrt(T) * (std::exp(-0.5 * d1 * d1) / std::sqrt(2 * M_PI));

        // Avoid division by zero or near-zero values
        if (std::abs(vega) < 1e-8) {
            break;
        }

        sigma = sigma - f_sigma / vega;

        // Ensure sigma is always positive
        if (sigma <= 0) {
            sigma = 1e-4;
        }

        f_sigma = blackScholesCall(S, X, T, r, sigma) - marketPrice;
        iteration++;
    }
    
    return sigma;
}

