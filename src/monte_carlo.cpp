/**
 * @file monte_carlo.cpp
 * @author Eli Asmar
 */

#include "../include/monte_carlo.h"

std::random_device rd;  
std::mt19937 generator(rd());
std::normal_distribution<> distribution(0.0, 1.0); 
std::vector<double> simulateStockPrice(double S, double T, double r, double sigma) {

    double Z = distribution(generator); // Generate a standard normal variable
    double S_T1 = S * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * -Z);
    double S_T2 = S * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * Z);
    
    return std::vector<double> (S_T1,S_T2);
}

double monteCarloCall(int numSimulations, double S, double X, double T, double r, double sigma)
{
    double summation = 0.0;
    #pragma omp parallel for reduction(+:summation)
    for (int i = 0; i < numSimulations;  i++)
    {
        std::vector<double> S_T = simulateStockPrice(S,T,r,sigma);
        double payoff1 = std::max(S_T[0] - X, 0.0);
        double payoff2 = std::max(S_T[1] - X, 0.0);

        summation += (payoff1 + payoff2)/2.0;

    }
    return std::exp(-r*T) * (1.0 /numSimulations) * summation;

}
double monteCarloPut(int numSimulations, double S, double X, double T, double r, double sigma)
{
      double summation = 0.0;
    #pragma omp parallel for reduction(+:summation)
    for (int i = 0; i < numSimulations;  i++)
    {
        std::vector<double> S_T = simulateStockPrice(S,T,r,sigma);
        double payoff1 = std::max(X- S_T[0] , 0.0);
        double payoff2 = std::max(X- S_T[1] , 0.0);
        summation += (payoff1 + payoff2)/2.0;

    }
    return std::exp(-r*T) * (1.0 /numSimulations) * summation;

}

