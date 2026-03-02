#pragma once

#include <vector>
#include <cstddef>
#include <random>
#include <iostream>

/**
 * @brief Generate a random NxN matrix in flat memory layout.
 * 
 * @tparam T: type of element
 * @tparam RNG: callable random number generator rng() -> T  
 * @param N: Size of rows/columns
 * @param rng: random number generation function
 * @return std::vector<T>: randomised matrix of NxN numbers
 */
template<typename T, typename RNG>
std::vector<T> generate_random_square_matrix_flat(const std::size_t N, RNG &rng)
{
    std::vector<T> M(N*N, 0);
    for(T& x : M)
    {
        x = rng();
    }
    return M;
}

/**
 * @brief Generates NxN square matrix in flat layout populated with 0s
 * 
 * @tparam T: Element type
 * @param N: size of row/column 
 * @return std::vector<T>: zeroed NxN matrix
 */
template<typename T>
std::vector<T> generate_zeroed_square_matrix_flat(const std::size_t N)
{
    std::vector<T> M(N*N, 0);
    return M;
}

/**
 * @brief Generate a random NxN matrix in 2D (fragmented) memory layout.
 * 
 * @tparam T: type of element
 * @tparam RNG: callable random number generator rng() -> T  
 * @param N: Size of rows/columns
 * @param rng: random number generation function
 * @return std::vector<T>: randomised matrix of NxN numbers
 */
template<typename T, typename RNG>
std::vector<std::vector<T>> generate_random_square_matrix(const std::size_t N, RNG &rng)
{
    std::vector<std::vector<T>> M(N, std::vector<T>(N, 0));
    for(auto& x : M)
    {
        for(auto& y: x)
        {
            y = rng();
        }
    }
    return M;
}

/**
 * @brief Generates NxN square matrix in 2D (fragmented) layout populated with 0s
 * 
 * @tparam T: Element type
 * @param N: size of row/column 
 * @return std::vector<T>: zeroed NxN matrix
 */
template<typename T>
std::vector<std::vector<T>> generate_zeroed_square_matrix(const std::size_t N)
{
    std::vector<std::vector<T>> M(N, std::vector<T>(N, 0));
    return M;
}


/**
 * @brief Print 2d (fragmented) matrix data
 * 
 * @tparam T: element type
 * @param M: Matrix
 * @param N: Size of row/column
 */
template<typename T>
void print_matrix(const T &M, const std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Print flat matrix data
 * 
 * @tparam T: element type
 * @param M: matrix
 * @param N: size of row/column
 */
template<typename T>
void print_matrix_flat(const T &M, const std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            std::cout << M[i*N + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}