echo "# Black-Scholes & Monte Carlo Pricing" >> README.md
echo "A simple C++ implementation of option pricing using the Black-Scholes formula and Monte Carlo simulation with OpenMP parallelization and variance reduction." >> README.md
echo "## Features" >> README.md
echo "- Black-Scholes pricing for European call/put options" >> README.md
echo "- Monte Carlo simulation with OpenMP parallelization" >> README.md
echo "- Antithetic Variates for variance reduction" >> README.md
echo "## Compilation" >> README.md
echo '```sh' >> README.md
echo "g++ -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp src/main.cpp src/black_scholes.cpp src/monte_carlo.cpp -o option_pricing" >> README.md
echo '```' >> README.md
echo "## Usage" >> README.md
echo "./option_pricing" >> README.md
echo "## Next Steps" >> README.md
echo "- Implement Implied Volatility Calculation using Newton-Raphson method" >> README.md
echo "- Add support for American options using Least Squares Monte Carlo" >> README.md
echo "## Author" >> README.md
echo "Eli Asmar" >> README.md
