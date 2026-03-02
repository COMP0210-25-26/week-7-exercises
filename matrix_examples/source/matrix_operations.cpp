#include "matrix_maths.h"
#include "matrix_utils.h"
#include <random>
#include <vector>
#include <iostream>
#include <chrono>
#include <functional>

using std::vector;
typedef std::chrono::high_resolution_clock timingClock;

/**
 * @brief Convenience function for working out time in seconds between two clock measurements
 * 
 * @param t1: Starting clock measurement 
 * @param t2: Ending clock measurement
 * @return double: Time elapsed between measurements in seconds
 */
double t_seconds(std::chrono::time_point<timingClock> t1, std::chrono::time_point<timingClock> t2)
{
    return (t2 - t1).count() / 1e9;
}

int main()
{
    // Setting up random numbers; calling genRand() will generate a random double.
    std::mt19937_64 rng;
    std::uniform_real_distribution<double> dist(0,1);
    auto genRand = std::bind(dist, rng);
    
    const std::size_t N = 1500;

    // Examples of how to generate a randomised matrix; you may also choose another compatible matrix rep if you want to!
    std::vector<double> matrixA = generate_random_square_matrix_flat<double>(N, genRand);   
    std::vector<double> matrixB = generate_random_square_matrix_flat<double>(N, genRand);
    // std::vector<vector<double>> fragmented_matrix = generate_random_square_matrix<double>(N, genRand);
    
    // Example of how to generate a matrix with all zero values (faster than generating random!)
    std::vector<double> matrixC = generate_zeroed_square_matrix_flat<double>(N);

    // Examples of how to call matrix multiplication methods; note that matrixC gets overwritten for the result
    auto t1 = timingClock::now();
    rowMajor_by_rowMajor_flat(matrixA, matrixB, matrixC, N);
    auto t2 = timingClock::now();

    std::cout << "t row major = " << t_seconds(t1, t2) << std::endl;

    t1 = timingClock::now();
    rowMajor_by_colMajor_flat(matrixA, matrixB, matrixC, N);
    t2 = timingClock::now();

    std::cout << "t col major = " << t_seconds(t1, t2) << std::endl;


    return 0;
}