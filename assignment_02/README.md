# CS509 Assignment 2 – Graph Algorithms

##  Overview

This assignment implements two fundamental shortest-path algorithms for directed weighted graphs:

* **Bellman-Ford Algorithm**
* **Floyd-Warshall Algorithm**

The project also implements **Compressed Sparse Row (CSR)** representation for efficient graph storage and includes a graph test-case generator and execution-time measurement.

---

## Author

| Name             | Roll Number     |
| ---------------- | --------------- |
| **Gaurav Kumar** | **2026CSM1014** |

---

## 🧠 Algorithms Implemented

### 1. Bellman-Ford Algorithm

The Bellman-Ford algorithm finds the shortest path from a **single source vertex** to all other vertices.

#### Features

* Supports directed weighted graphs
* Supports negative edge weights
* Detects negative-weight cycles
* Uses CSR representation
* Source vertex: `0`

#### Time Complexity

```text
O(V × E)
```

where:

* `V` = number of vertices
* `E` = number of edges

---

### 2. Floyd-Warshall Algorithm

The Floyd-Warshall algorithm finds the shortest paths between **every pair of vertices**.

#### Features

* Computes all-pairs shortest paths
* Supports negative edge weights
* Uses dynamic programming
* Stores distances in a matrix

#### Time Complexity

```text
O(V³)
```

where `V` is the number of vertices.

---

#  Graph Representation

For the Bellman-Ford implementation, the graph is represented using **Compressed Sparse Row (CSR)**.

CSR uses three main arrays:

```text
rowPtr
colIndex
weights
```

### `rowPtr`

Stores the starting position of the outgoing edges of each vertex.

### `colIndex`

Stores the destination vertex of each edge.

### `weights`

Stores the weight of each edge.

CSR provides an efficient representation for sparse graphs and avoids storing a complete `V × V` matrix.

---

#  Project Structure


```text
CS509_2026CSM1014/
│
├── assignment_01/
│
├── assignment_02/
│   │
│   ├── driver/
│   │   ├── driver.cpp
│   │   └── driver.h
│   │
│   ├── src/
│   │   ├── graph.cpp
│   │   ├── graph.h
│   │   ├── csr.cpp
│   │   ├── csr.h
│   │   ├── bellman_ford.cpp
│   │   ├── bellman_ford.h
│   │   ├── floyd_warshall.cpp
│   │   └── floyd_warshall.h
│   │
│   ├── tests/
│   │   ├── bf_test_01.txt
│   │   ├── fw_test_01.txt
│   │   └── generated_test.txt
│   │
│   └── tools/
│       └── generate_graph_tests.cpp
│
├── common/
│   ├── timer.cpp
│   ├── timer.h
│   ├── test_generator.cpp
│   └── test_generator.h
│
├── common_wrapper/
│   ├── wrapper.cpp
│   └── wrapper.h
│
└── README.md
```

---

#  Input Format

Each graph input file follows this format:

```text
V E
u1 v1 w1
u2 v2 w2
u3 v3 w3
...
```

Where:

| Symbol | Meaning            |
| ------ | ------------------ |
| `V`    | Number of vertices |
| `E`    | Number of edges    |
| `u`    | Source vertex      |
| `v`    | Destination vertex |
| `w`    | Edge weight        |

### Example

```text
5 7
0 1 4
0 2 2
1 2 3
1 3 2
2 3 1
3 4 5
4 1 -2
```

This represents a directed weighted graph with:

```text
Vertices = 5
Edges    = 7
```

---

# Test Cases

The project contains predefined and generated test cases.

### Bellman-Ford Test

```text
assignment_02/tests/bf_test_01.txt
```

### Floyd-Warshall Test

```text
assignment_02/tests/fw_test_01.txt
```

### Generated Test

```text
assignment_02/tests/generated_test.txt
```

Generated test cases are used to evaluate the performance of the algorithms on larger graphs.

---

#  Test Case Generator

The project contains a graph test generator:

```text
assignment_02/tools/generate_graph_tests.cpp
```

### Compile

```bash
g++ assignment_02/tools/generate_graph_tests.cpp -o generate_graph_tests.exe
```

### Run

```bash
generate_graph_tests.exe
```

The program asks for the number of vertices.

Example:

```text
Enter number of vertices: 500
```

A graph with approximately `500` vertices and `2500` edges can be generated.

---

#  Compilation

## Windows / MinGW

Compile the CS509_2026CSM1014 source files using:

```bash
g++ common_wrapper/wrapper.cpp common/timer.cpp assignment_01/driver/driver.cpp assignment_01/src/matrix.cpp assignment_01/src/gemm_simple.cpp assignment_01/src/gemm_blocking.cpp assignment_02/driver/driver.cpp assignment_02/src/graph.cpp assignment_02/src/csr.cpp assignment_02/src/bellman_ford.cpp assignment_02/src/floyd_warshall.cpp -o assignment.exe
```

Then run:

```bash
assignment.exe
```

---

#  Running the Program

The project provides a menu-driven interface.

Example:

```text
========================================
          CS509 ASSIGNMENT MENU
========================================

1. Assignment 1 - GEMM
2. Assignment 2 - Graph Algorithms
0. Exit

Enter Choice:
```

Select:

```text
2
```

to open Assignment 2.

---

# Assignment 2 Menu

After selecting Assignment 2:

```text
========================================
          ASSIGNMENT 2
========================================

1. Bellman Ford
2. Floyd Warshall
0. Back

Enter Choice:
```

---

#  Bellman-Ford Execution


```text


===== Bellman Ford =====
1. Run bf_test_01.txt
2. Run generated test file
0. Back
Enter Choice :

The program calculates the shortest distance from **source vertex 0** to all other vertices.

Example output:
```
```text
========================================
        BELLMAN-FORD RESULT
========================================

Source Vertex : 0

Vertex 0 : 0
Vertex 1 : ...
Vertex 2 : ...
Vertex 3 : ...
Vertex 4 : ...

Execution Time : ... microseconds
```

If a vertex is unreachable:

```text
INF
```

If a negative-weight cycle is detected:

```text
Negative Weight Cycle Detected!
```

---

#  Floyd-Warshall Execution

Select:

```text
2. Floyd Warshall
```

The program calculates the shortest distance between every pair of vertices.

Example output:

```text
========================================
       FLOYD-WARSHALL RESULT
========================================

All-Pairs Shortest Path Matrix

0    4    2    3    8
...
```

`INF` indicates that no path exists between the corresponding pair of vertices.

---

#  Execution Time Measurement

The project contains a reusable timer:

```text
common/timer.h
common/timer.cpp
```

The timer uses:

```cpp
std::chrono::high_resolution_clock
```

Execution time is measured in:

```text
microseconds
```

This allows the performance of the algorithms to be compared for different graph sizes.

---

#  Execution Results

The following execution results were obtained by running the **Bellman-Ford** and **Floyd-Warshall** algorithms on different graph sizes.

| Test Case            | Vertices | Edges | Source Vertex | Algorithm      |Execution Time |
| -------------------- | -------: | ----: | ------------: | -------------- |---------------|
| `bf_test_01.txt`     |      200 |  1000 |             0 | Bellman-Ford   |    **5364us** |
| `fw_test_01.txt`     |      100 |   500 |             — | Floyd-Warshall |  **26925 us** |
| `generated_test.txt` |      500 |  2500 |             0 | Bellman-Ford   |  **35902 us** |
| `generated_test.txt` |      500 |  2500 |             — | Floyd-Warshall | **3285826 us** |





#  Algorithm Comparison

| Feature                      | Bellman-Ford                | Floyd-Warshall              |
| ---------------------------- | --------------------------- | --------------------------- |
| **Problem Type**             | Single-Source Shortest Path | All-Pairs Shortest Path     |
| **Output**                   | Distance from one source    | Distance between every pair |
| **Time Complexity**          | `O(V × E)`                  | `O(V³)`                     |
| **Negative Edges**           |  Supported                  |  Supported                  |
| **Negative Cycle Detection** |  Yes                        | —                           |
| **Graph Representation**     | CSR                         | Distance Matrix             |
| **Source Vertex**            | `0`                         | All vertices                |

---

#  Implementation Details

## Bellman-Ford

The implementation follows these steps:

1. Initialize all distances to `INF`.
2. Set the source vertex distance to `0`.
3. Relax all edges `V - 1` times.
4. Perform one additional pass to check for a negative-weight cycle.
5. Print the shortest distances.

---

## Floyd-Warshall

The implementation follows these steps:

1. Initialize the distance matrix with `INF`.
2. Set diagonal elements to `0`.
3. Insert the weights of direct edges.
4. Consider every vertex as an intermediate vertex.
5. Update the distance using:

```text
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
```

6. Print the final shortest-path matrix.

---

# Requirements

The project requires:

* **C++11 or later**
* **G++ / MinGW**
* Standard C++ Library
* Windows CMD or Linux Terminal


---



---

#  Conclusion

This assignment implements and demonstrates two important shortest-path algorithms:

**Bellman-Ford** for single-source shortest paths and **Floyd-Warshall** for all-pairs shortest paths.

The project also uses **CSR representation**, **automated test generation**, and **execution-time measurement** to study the correctness and performance of graph algorithms on different input sizes.

---

##  Authors

**Gaurav Kumar**
`2026CSM1014`


---

##  Course Information

**Course:** CS509-Pg Software Lab
**IIT ROPAR**
**Assignment:** Assignment 2 – Graph Algorithms
