#include "matrix.h"
#include <iostream>
#include <fstream>

bool readMatrices(const std::string& filename,
                  Matrix& A,
                  Matrix& B,
                  int& M,
                  int& K,
                  int& N)
{
    std::ifstream fin(filename);

    if (!fin.is_open())
    {
        std::cout << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    // Read dimensions
  
        if (!(fin >> M >> K >> N))
{
    std::cout << "Error: Invalid or empty input file!" << std::endl;
    return false;
}

    // Resize matrices
    A.resize(M, std::vector<int>(K));
    B.resize(K, std::vector<int>(N));

    // Read Matrix A
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            fin >> A[i][j];
        }
    }

    // Read Matrix B
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> B[i][j];
        }
    }

    fin.close();

    return true;
}

void printMatrix(const Matrix& matrix)
{
    for (const auto& row : matrix)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}