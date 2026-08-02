#include <iostream>
#include <chrono>
#include "driver.h"

#include "../src/matrix.h"
#include "../src/gemm_simple.h"
#include "../src/gemm_blocking.h"


using namespace std;
using namespace std::chrono;

void runTest(const std::string& filename)
{
    Matrix A, B, C;

    int M, K, N;

    // Read matrices
    if (!readMatrices(filename, A, B, M, K, N))
    {
        return;
    }


    // Start timer
    auto start = high_resolution_clock::now();

    // Call algorithm
    C = gemmSimple(A, B, M, K, N);

    // Stop timer
    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    cout << "\nRunning : " << filename << "\n\n";

    cout << "Algorithm : GEMM Simple\n\n";
    cout << "Result Matrix\n";
    printMatrix(C);

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds\n";

    // Blocking GEMM

    auto start2 = high_resolution_clock::now();

    Matrix C2 = gemmBlocking(A, B, M, K, N, 2);

    auto stop2 = high_resolution_clock::now();

    auto duration2 =
        duration_cast<microseconds>(stop2 - start2);

    cout << "\nAlgorithm : GEMM Blocking\n\n";
    cout << "Result Matrix\n";
    printMatrix(C2);

    cout << "\nExecution Time : "
         << duration2.count()
         << " microseconds\n";
}

void runAssignment1()
{
    int choice;

    cout << "\n===== Assignment 1 : GEMM =====\n";
    cout << "1. Run gemm_test_01.txt\n";
    cout << "2. Run gemm_test_02.txt\n";
    cout << "3. Run gemm_test_03.txt\n";
    cout << "4. Run All Test Files\n";
    cout << "0. Back\n";

    cout << "Enter Choice : ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            runTest("assignment_01/tests/gemm_test_01.txt");
            break;

        case 2:
            runTest("assignment_01/tests/gemm_test_02.txt");
            break;

        case 3:
            runTest("assignment_01/tests/gemm_test_03.txt");
            break;

        case 4:
            runTest("assignment_01/tests/gemm_test_01.txt");
            runTest("assignment_01/tests/gemm_test_02.txt");
            runTest("assignment_01/tests/gemm_test_03.txt");
            break;

        case 0:
            return;

        default:
            cout << "Invalid Choice\n";
    }
}