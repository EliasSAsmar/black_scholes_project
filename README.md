

# **Black-Scholes & Monte Carlo Pricing**

A simple C++ implementation of option pricing using the **Black-Scholes formula** and **Monte Carlo simulation** with **OpenMP parallelization** and **variance reduction**.

## **Features**
-  Black-Scholes pricing for European call/put options  
-  Monte Carlo simulation with OpenMP parallelization  
-  Antithetic Variates for variance reduction  

## **Compilation**
Run the following command to compile the project with OpenMP support:
```sh
g++ -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp src/main.cpp src/black_scholes.cpp src/monte_carlo.cpp -o option_pricing
```

## **Usage**
```sh
./option_pricing
```



## **Author**
[Eli Asmar]([https://github.com/your-github-username](https://github.com/EliasSAsmar))

