cmake_minimum_required(VERSION 3.16)
project(black_scholes_project)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check if we're on macOS with ARM64
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    # Manually specify OpenMP paths for Apple Silicon
    set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
    set(OpenMP_C_LIB_NAMES "omp")
    set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
    set(OpenMP_CXX_LIB_NAMES "omp")
    set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")
endif()

# Find OpenMP package
find_package(OpenMP REQUIRED)

# Set compiler flags
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    # Force CMake to use these flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/opt/libomp/lib -lomp")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files
set(SOURCES
    src/main.cpp
    src/black_scholes.cpp
    src/monte_carlo.cpp
    src/implied_volatility.cpp
)

# Create executable
add_executable(option_pricing ${SOURCES})

# Link OpenMP
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    target_link_libraries(option_pricing PRIVATE "/opt/homebrew/opt/libomp/lib/libomp.dylib")
else()
    target_link_libraries(option_pricing PRIVATE OpenMP::OpenMP_CXX)
endif()
