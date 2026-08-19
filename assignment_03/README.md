# CS509 Assignment 3

## Minimum Spanning Tree using Prim's and Kruskal's Algorithms

### Project Overview

This assignment implements two Minimum Spanning Tree (MST) algorithms
for undirected weighted graphs:

1.  Prim's Algorithm
2.  Kruskal's Algorithm

The assignment uses a CSR (Compressed Sparse Row) representation for the
graph and a common Timer implementation for measuring algorithm
execution time.

------------------------------------------------------------------------

## Author

| Name             | Roll Number     |
| ---------------- | --------------- |
| **Gaurav Kumar** | **2026CSM1014** |

---
## Folder Structure

The complete project follows this structure:

``` text
CS509_2026CSM1014/
│
├── assignment_01/
│
├── assignment_02/
│
├── assignment_03/
│   │
│   ├── common/
│   │   ├── mst_csr.cpp
│   │   ├── mst_csr.h
│   │   ├── mst_graph.cpp
│   │   └── mst_graph.h
│   │
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   │
│   ├── outputs/
│   │
│   ├── src/
│   │   ├── kruskal.cpp
│   │   ├── kruskal.h
│   │   ├── prims.cpp
│   │   └── prims.h
│   │
│   ├── tests/
│   │   ├── mst_10.txt
│   │   ├── mst_100.txt
│   │   ├── mst_10000.txt
│   │   ├── mst_50000.txt
│   │   ├── mst_100000.txt
│   │   └── generated_mst.txt
│   │
│   └── tools/
│       └── generate_mst_tests.cpp
│
├── common/
│   ├── graph.cpp
│   ├── graph.h
│   ├── csr.cpp
│   ├── csr.h
│   ├── timer.cpp
│   └── timer.h
│
└── common_wrapper/
    ├── wrapper.cpp
    └── wrapper.h
```

The `common/` directory contains components shared with the other
assignments, while Assignment 3 keeps its own MST-specific graph and CSR
implementation inside `assignment_03/common/`.

## Algorithms

### Prim's Algorithm

Prim's algorithm starts from a source vertex and repeatedly selects the
minimum-weight edge connecting a vertex already in the MST to a vertex
outside the MST.

The implementation uses:

-   `key[]`
-   `parent[]`
-   `inMST[]`
-   CSR graph representation

### Kruskal's Algorithm

Kruskal's algorithm:

1.  Extracts the undirected edges from CSR.
2.  Sorts the edges by weight.
3.  Adds an edge if it does not create a cycle.
4.  Uses Disjoint Set Union (DSU) for cycle detection.

The DSU implementation uses:

-   Path compression
-   Union by rank

------------------------------------------------------------------------

## Graph Representation

Assignment 3 uses a separate MST-specific CSR representation:

``` text
rowPtr
colIndex
weights
```

Since the graph is undirected, both directions of every edge are stored.

For example, one undirected edge:

``` text
0 -- 1  (weight 4)
```

is represented as:

``` text
0 -> 1  4
1 -> 0  4
```

The input value `E` represents the number of unique undirected edges.

------------------------------------------------------------------------

## Input Format

The first line contains:

``` text
V E
```

where:

-   `V` = number of vertices
-   `E` = number of undirected edges

Each following line contains:

``` text
vertex degree neighbour weight neighbour weight ...
```

Example:

``` text
10 16
0 3 1 4 2 3 3 8
1 3 0 4 2 2 4 7
2 4 0 3 1 2 3 1 5 6
...
```

Each undirected edge is listed in both directions.

------------------------------------------------------------------------

## Test Cases

The following test cases were executed for Assignment 3:

  | Test Case       |   Vertices |    Edges
  |-----------------| ---------- |---------
  |`mst_10.txt`     |         10 |       14
  |`mst_100.txt`    |        100 |      300
  |`mst_10000.txt`  |    10,000  |  30,000
  |`mst_50000.txt`  |     50,000 |  100,000
  |`mst_100000.txt` |    100000  |  200000

The graphs are connected so that an MST exists.

## Test Case Generator

The test case generator is located at:

``` text
assignment_03/tools/generate_mst_tests.cpp
```

Compile it using:

``` bash
g++ assignment_03/tools/generate_mst_tests.cpp -o generate_mst_tests.exe
```

Run:

``` bash
generate_mst_tests.exe
```

The generator asks for:

``` text
Enter number of vertices :
Enter number of edges :
```

Example:

``` text
Enter number of vertices : 50000
Maximum possible edges : 1249975000
Enter number of edges : 100000
```

The generated file is:

``` text
assignment_03/tests/generated_mst.txt
```

The generator creates only the required number of edges rather than
storing all possible edges in memory, allowing large sparse graphs to be
generated.

------------------------------------------------------------------------

## Compilation

From the project root:

``` bash
g++ common_wrapper/wrapper.cpp common/timer.cpp common/graph.cpp common/csr.cpp assignment_01/driver/driver.cpp assignment_01/src/matrix.cpp assignment_01/src/gemm_simple.cpp assignment_01/src/gemm_blocking.cpp assignment_02/driver/driver.cpp assignment_02/src/bellman_ford.cpp assignment_02/src/floyd_warshall.cpp assignment_03/driver/driver.cpp assignment_03/common/mst_graph.cpp assignment_03/common/mst_csr.cpp assignment_03/src/prims.cpp assignment_03/src/kruskal.cpp -o assignment3.exe
```

------------------------------------------------------------------------

## Running the Program

Run:

``` bash
assignment3.exe
```

Select Assignment 3 from the common wrapper menu.

The Assignment 3 menu is:

``` text
=====================================
          Assignment 3
=====================================
1. Kruskal's MST
2. Prim's MST
0. Back
```

After selecting an algorithm, choose the required test case.

------------------------------------------------------------------------

## Output

The program displays:

-   Input file
-   MST edges
-   Total MST weight
-   Execution time

Example:

``` text
=====================================
          Kruskal's MST
=====================================

Input File : assignment_03/tests/mst_10.txt

MST edges:
8 9 1
2 3 2
6 7 2
1 2 3
5 6 3
0 1 4
4 5 4
7 8 4
3 5 5

Total MST weight: 28
Execution time: 0 microseconds
```

Prim's algorithm may display the MST edges in a different order, but the
total MST weight should be the same.

------------------------------------------------------------------------

## Execution Time

The common `Timer` implementation is used to measure algorithm execution
time.

CSR construction is treated as preprocessing and is not included in the
algorithm execution time. The measured times below are the observed
execution times from the test runs.

  Test Case        |   Vertices  |  Edges  |  Kruskal (µs) |   Prim (µs)|
  -----------------| ----------  |-------- |-------------- |------------|
  `mst_10.txt`     |         10  |    14   |          0    |        0   |
  `mst_100.txt`    |        100  |    300  |      2031     |        0   |
  `mst_10000.txt`  |     10,000  |  30,000 |    472902     |  3323058   |
  `mst_50000.txt`  |     50,000  |  100,000|    160794069  |  89546205  |     
 `mst_100000.txt`  |     100000  |  200000 |    3883929    | 3883929    |
 
For small inputs, the execution time can be reported as `0 microseconds`
because the measured execution is shorter than the timer's displayed
microsecond resolution.

The measured times include only the corresponding MST algorithm:

``` text
Kruskal's MST
Prim's MST
```

and do not include CSR construction.

## Prim vs Kruskal

  Feature                Prim's Algorithm             Kruskal's Algorithm
  ---------------------- ---------------------------- ----------------------------
  Approach               Grows one MST                Selects edges globally
  Main Structure         Key/Parent arrays            DSU
  Edge Selection         Minimum adjacent edge        Minimum sorted edge
  Cycle Handling         `inMST[]`                    DSU
  Graph Representation   CSR                          CSR
  Output                 MST edges and total weight   MST edges and total weight

------------------------------------------------------------------------

## Important Notes

-   The graph is undirected and weighted.
-   The graph must be connected for an MST to exist.
-   `E` counts unique undirected edges.
-   Both directions of an undirected edge are stored in CSR.
-   Prim's and Kruskal's algorithms should produce the same minimum
    total MST weight.
-   The order of MST edges can be different between the two algorithms.
-   Larger test cases are useful for meaningful execution-time
    comparison.

------------------------------------------------------------------------

## Conclusion

This assignment implements Prim's and Kruskal's algorithms for finding a
Minimum Spanning Tree of an undirected weighted graph.

Both algorithms use the same MST-specific CSR representation and are
tested on graphs of different sizes. Their execution times can be
compared using the common Timer implementation.

---

##  Authors

**Gaurav Kumar**
`2026CSM1014`


---

##  Course Information

**Course:** CS509-Pg Software Lab
**IIT ROPAR**
**Assignment:** Assignment 3
