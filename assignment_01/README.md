# Assignment 01 - General Matrix Multiplication (GEMM)

## CS509 - High Performance Computing

**Language:** C++

**Compiler:** g++ (MinGW)

**Platform:** Windows

---

## Project Overview

This project implements two approaches for General Matrix Multiplication (GEMM):

- Simple GEMM
- Blocked GEMM

The objective is to compare the performance of both implementations by executing them on different matrix sizes and measuring their execution time.

The project follows a modular design in which different functionalities are separated into individual source files for better readability, maintainability, and code reuse.

## Features

- Implementation of Simple GEMM
- Implementation of Blocked GEMM
- Reads matrices from input test files
- Supports execution of multiple test cases
- Measures execution time using a reusable Timer class
- Includes a random test file generator for creating large input matrices

## Directory Structure

CS509_2026CSM1014/
│
├── assignment_01/
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   |__Ouput/
│   ├── src/
│   │   ├── gemm_blocking.cpp
│   │   ├── gemm_blocking.h
│   │   ├── gemm_simple.cpp
│   │   ├── gemm_simple.h
│   │   ├── matrix.cpp
│   │   └── matrix.h
│   │
│   ├── tests/
│   │   ├── gemm_test_01.txt
│   │   ├── gemm_test_02.txt
│   │   ├── gemm_test_03.txt
│   │   └── generated_test.txt
│   │
│   
│
├── common/
│   ├── test_generator.cpp
│   ├── test_generator.h
│   ├── timer.cpp
│   └── timer.h
│
├── common_wrapper/
│   ├── wrapper.cpp
│   └── wrapper.h
│
├── tools/
│   └── generate_tests.cpp
│
└── README.md

## File Description

### assignment_01/driver

- **driver.cpp**  
  Controls the execution of Assignment 01. It reads test files, invokes GEMM algorithms, measures execution time, and displays the results.

- **driver.h**  
  Contains function declarations used by the driver.

---

### assignment_01/src

- **matrix.cpp / matrix.h**  
  Implements matrix utilities such as reading matrices from input files and printing result matrices.

- **gemm_simple.cpp / gemm_simple.h**  
  Implements the standard three-loop General Matrix Multiplication algorithm.

- **gemm_blocking.cpp / gemm_blocking.h**  
  Implements the blocked version of GEMM for improved cache utilization.

---

### assignment_01/tests

Contains input test files used to verify correctness and performance.

---

### assignment_01/outputs

Reserved for storing output files if required.

---

### common

- **timer.cpp / timer.h**  
  Provides a reusable Timer class for measuring execution time.

- **test_generator.cpp / test_generator.h**  
  Implements functions for generating random matrix test files.

---

### tools

- **generate_tests.cpp**  
  Utility program used to generate random GEMM input files.

---

### common_wrapper

- **wrapper.cpp / wrapper.h**  
  Provides a common menu interface for executing the assignment.

  ## Algorithms Implemented

### 1. Simple GEMM

Simple GEMM performs matrix multiplication using the standard three nested loops.

For two matrices:

- Matrix A of size **M × K**
- Matrix B of size **K × N**

The resultant matrix C has size **M × N**.

### Algorithm

for i = 0 to M-1
    for j = 0 to N-1
        C[i][j] = 0
        for k = 0 to K-1
            C[i][j] += A[i][k] * B[k][j]


### Characteristics

- Easy to understand and implement.
- Performs a large number of memory accesses.
- Cache utilization is relatively poor for large matrices.

### Time Complexity
O(M × K × N)


---

## 2. Blocked GEMM

Blocked GEMM divides the matrices into smaller blocks and performs multiplication block by block instead of processing the entire matrices at once.

This approach improves cache locality by reusing data already loaded into the cache, resulting in better performance for larger matrices.

### Algorithm

    
for ii = 0 to M-1 step BlockSize
    for jj = 0 to N-1 step BlockSize
        for kk = 0 to K-1 step BlockSize

            Multiply the current sub-blocks

            Update the corresponding block of Matrix C


### Characteristics

- Better cache utilization.
- Reduces cache misses.
- Faster than Simple GEMM for large matrices.
- Requires selecting an appropriate block size.

### Time Complexity

O(M × K × N)

Although both algorithms have the same theoretical time complexity, Blocked GEMM generally achieves better practical performance because of improved cache efficiency.

## Compilation
Compile the project using the following command:

```bash
g++ common_wrapper/wrapper.cpp common/timer.cpp assignment_01/driver/driver.cpp assignment_01/src/matrix.cpp assignment_01/src/gemm_simple.cpp assignment_01/src/gemm_blocking.cpp -o assignment1.exe

```

## Execution

Run the executable:

```bash
assignment01.exe
```

After execution, the following menu is displayed:

```text
=====================================
      CS509 Assignment Menu
=====================================
1. Assignment 1 - GEMM
0. Exit
Enter Choice :
```

Selecting **Assignment 1** displays:

```text
== Assignment 1 : GEMM ==

1. Run gemm_test_01.txt
2. Run gemm_test_02.txt
3. Run gemm_test_03.txt
4. Run generated_test.txt
5. Run All Test Files
0. Back

Enter Choice :
```

The program then:

- Reads the selected input test file.
- Executes both **Simple GEMM** and **Blocked GEMM**.
- Prints the resultant matrix.
- Displays the execution time of each algorithm.

## Input Format

Each input test file contains two matrices in the following format:

```text
M K N

Matrix A (M × K)

Matrix B (K × N)
```

Where:

- **M** = Number of rows in Matrix A
- **K** = Number of columns in Matrix A (and rows in Matrix B)
- **N** = Number of columns in Matrix B

### Example Input

```text
2 3 2

1 2 3
4 5 6

7 8
9 10
11 12
```

---

## Output Format

For each selected test case, the program displays:

- Name of the input test file
- Result using **Simple GEMM**
- Execution time of **Simple GEMM**
- Result using **Blocked GEMM**
- Execution time of **Blocked GEMM**

### Sample Output

```text
Running : assignment_01/tests/gemm_test_01.txt

Algorithm : GEMM Simple

Result Matrix
58 64
139 154

Execution Time : 15 microseconds

Algorithm : GEMM Blocking

Result Matrix
58 64
139 154

Execution Time : 10 microseconds
```

## test  case outputs 
# Performance Analysis

|    test           | matrix size         | Simple GEMM         |Blocked GEMM         |
|------------------ |-------------------  |--------------------:|----------------     |  
| gemm_test_01      | 2 3 2               |    0 microseconds   |0 microsecond        |
| gemm_test_02      | 3 3 3               |    0 microseconds   |0 microsecond        |
| gemm_test_03      | 4 2 4               |    0 microseconds   |0 microsecond        |
| generated test    | 100 100 100         |  53,856 microseconds|24,932 microsecond   |


## Conclusion

This assignment demonstrates the implementation and comparison of two General Matrix Multiplication (GEMM) algorithms.

The project follows a modular design by separating the implementation into reusable components such as drivers, matrix utilities, timer, and algorithm modules. Execution time measurements allow performance comparison between the standard and blocked implementations.

---

## Author

**Name:** Gaurav Kumar

**Entry No:** 2026CSM1014

**Course:** CS509 PG Software Lab

**Institute:** IIT Ropar

**Language:** C++

**Compiler:** g++ (MinGW)

---