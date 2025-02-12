# Black-Scholes & Monte Carlo Pricing

A simple C++ implementation of option pricing using the Black-Scholes formula and Monte Carlo simulation, featuring OpenMP parallelization, variance reduction techniques, and volatility calculations.

## Features
- Black-Scholes pricing for European call/put options
- Monte Carlo simulation with OpenMP parallelization
- Antithetic Variates for variance reduction
- **Volatility calculation for option pricing**

## Compilation
Run the following command to compile the project with OpenMP support:

```bash
g++ -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp src/main.cpp src/black_scholes.cpp src/monte_carlo.cpp src/volatility.cpp -o option_pricing
```

## Usage
```bash
./option_pricing
```

## Author
**Eli Asmar**

