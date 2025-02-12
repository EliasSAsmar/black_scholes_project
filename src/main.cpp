#include <iostream>
#include <omp.h>
#include "../include/black_scholes.h"
#include "../include/monte_carlo.h"
#include "../include/implied_volatility.h"


int main() {
    // Sample option parameters
    double S = 100.0;   // Stock price
    double X = 100.0;   // Strike price
    double T = 1.0;     // Time to expiration (in years)
    double r = 0.05;    // Risk-free interest rate (5%)
    double sigma = 0.2; // Volatility (20%)
    int numSimulations = 1000000; // Number of Monte Carlo simulations

    // Black-Scholes Prices
    double bsCall = blackScholesCall(S, X, T, r, sigma);
    double bsPut = blackScholesPut(S, X, T, r, sigma);

    // Monte Carlo Call Pricing with Timing
    double startCall = omp_get_wtime();
    double mcCall = monteCarloCall(numSimulations, S, X, T, r, sigma);
    double endCall = omp_get_wtime();
    
    // Monte Carlo Put Pricing with Timing
    double startPut = omp_get_wtime();
    double mcPut = monteCarloPut(numSimulations, S, X, T, r, sigma);
    double endPut = omp_get_wtime();

    // Print results
    std::cout << "Black-Scholes Call Price: " << bsCall << std::endl;
    std::cout << "Monte Carlo Call Price:  " << mcCall << std::endl;
    // std::cout << "Execution Time (Monte Carlo Call): " << (endCall - startCall) << " seconds" << std::endl;

    std::cout << "Black-Scholes Put Price: " << bsPut << std::endl;
    std::cout << "Monte Carlo Put Price:   " << mcPut << std::endl;
    // std::cout << "Execution Time (Monte Carlo Put): " << (endPut - startPut) << " seconds" << std::endl;


    
    double marketPrice = 10.5;  // Example market-observed call option price
    double iv = impliedVolatility(marketPrice, S, X, T, r);
    std::cout << "Implied Volatility: " << iv << std::endl;
    return 0;
}
