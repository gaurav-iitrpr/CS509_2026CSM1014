#include <iostream>
#include "../../common/timer.h"
#include "driver.h"

#include "../src/matrix.h"
#include "../src/gemm_simple.h"
#include "../src/gemm_blocking.h"




using namespace std;


void runTest(const std::string& filename)
{
    Matrix A, B, C;

    int M, K, N;

    // Read matrices
    if (!readMatrices(filename, A, B, M, K, N))
    {
        return;
    }


  Timer timer;

// start timer
timer.start();

 // call algorithm
C = gemmSimple(A, B, M, K, N);

// stop timer
long long duration = timer.stop();

    cout << "\nRunning : " << filename << "\n\n";

    cout << "Algorithm : GEMM Simple\n\n";
    cout << "Result Matrix\n";
    printMatrix(C);

   cout <<"\nExecution Time : "<< duration << " microseconds\n";

    // Blocking GEMM

    Timer timer2;
// start timer
timer2.start();
 
// call algorithm
Matrix C2 = gemmBlocking(A, B, M, K, N, 16);

// stop timer
long long duration2 = timer2.stop();

    cout << "\nAlgorithm : GEMM Blocking\n\n";
    cout << "Result Matrix\n";
    printMatrix(C2);

    cout <<"\nExecution Time : "<<duration2 << " microseconds\n";
}

void runAssignment1()
{
    int choice;

    cout << "\n== Assignment 1 : GEMM ==\n";
    cout << "1. Run gemm_test_01.txt\n";
    cout << "2. Run gemm_test_02.txt\n";
    cout << "3. Run gemm_test_03.txt\n";
    cout << "4. Run generated_test.txt\n";
    cout << "5. Run All Test Files\n";
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
        runTest("assignment_01/tests/generated_test.txt");
        break;

        case 5:
            runTest("assignment_01/tests/gemm_test_01.txt");
            runTest("assignment_01/tests/gemm_test_02.txt");
            runTest("assignment_01/tests/gemm_test_03.txt");
             runTest("assignment_01/tests/generated_test.txt");
            break;

        case 0:
            return;

        default:
            cout << "Invalid Choice\n";
    }
}