#pragma once

#include <cstddef>

/**
 * @brief Multiplies a row-major matrix A by a row-major matrix B.
 * 
 * Overwrites C = A*B.
 * 
 * Matrices use 2D indexing.
 * 
 * @tparam T: element type
 * @param A: Input matrix (row-major)
 * @param B: Input matrix (row-major)
 * @param C: Output Matrix (row-major) C = A*B
 * @param N: Row/Column size
 */
template<typename T>
void rowMajor_by_rowMajor(const T &A, const T &B, T &C, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            for(std::size_t k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/**
 * @brief Multiplies a row-major matrix A by a column-major matrix B.
 * 
 * Overwrites C = A*B.
 * 
 * Matrices use 2D indexing.
 * 
 * @tparam T: element type
 * @param A: Input matrix (row-major)
 * @param B: Input matrix (column-major)
 * @param C: Output Matrix (row-major) C = A*B
 * @param N: Row/Column size
 */
template<typename T>
void rowMajor_by_colMajor(const T &A, const T &B, T &C, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            for(std::size_t k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }
}

/**
 * @brief Transposes a matrix A in a cache inefficient way.
 * 
 * Matrices use 2D indexing.
 * 
 * @tparam T: element type
 * @param A: Input Matrix
 * @param B: Output Matrix = A transposed
 * @param N: column / row size.
 */
template<typename T>
void trivial_transpose(const T &A, T &B, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            B[i][j] = A[j][i];
        }
    }
}

/**
 * @brief Transposes a matrix A in a cache inefficient way.
 * 
 * Matrices use 1D indexing.
 * 
 * @tparam T: element type
 * @param A: Input Matrix
 * @param B: Output Matrix = A transposed
 * @param N: column / row size.
 */
template<typename T>
void trivial_transpose_flat(T &A, T &B, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            B[i*N + j] = A[j*N + i];
        }
    }
}


/**
 * @brief Multiplies a row-major matrix A by a row-major matrix B.
 * 
 * Overwrites C = A*B.
 * 
 * Matrices use 1D indexing.
 * 
 * @tparam T: element type
 * @param A: Input matrix (row-major)
 * @param B: Input matrix (row-major)
 * @param C: Output Matrix (row-major) C = A*B
 * @param N: Row/Column size
 */
template<typename T>
void rowMajor_by_rowMajor_flat(const T &A, const T &B, T &C, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            for(std::size_t k = 0; k < N; k++)
            {
                C[i*N + j] += A[i*N + k] * B[k*N + j];
            }
        }
    }
}

/**
 * @brief Multiplies a row-major matrix A by a column-major matrix B.
 * 
 * Overwrites C = A*B.
 * 
 * Matrices use 1D indexing.
 * 
 * @tparam T: element type
 * @param A: Input matrix (row-major)
 * @param B: Input matrix (column-major)
 * @param C: Output Matrix (row-major) C = A*B
 * @param N: Row/Column size
 */
template<typename T>
void rowMajor_by_colMajor_flat(const T &A, const T &B, T &C, std::size_t N)
{
    for(std::size_t i = 0; i < N; i++)
    {
        for(std::size_t j = 0; j < N; j++)
        {
            for(std::size_t k = 0; k < N; k++)
            {
                C[i*N + j] += A[i*N + k] * B[j*N + k];
            }
        }
    }
}