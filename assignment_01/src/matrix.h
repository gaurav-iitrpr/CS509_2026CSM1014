#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<int>>;

// read matrices from input file
bool readMatrices(const std::string& filename,
                  Matrix& A,
                  Matrix& B,
                  int& M,
                  int& K,
                  int& N);

// print matrix
void printMatrix(const Matrix& matrix);

#endif