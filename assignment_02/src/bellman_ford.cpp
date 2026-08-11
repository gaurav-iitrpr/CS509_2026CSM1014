#include "bellman_ford.h"

#include <iostream>
#include <climits>

using namespace std;

vector<int> bellmanFord(Graph &graph, CSR &csr, int source){
    vector<int> distance(graph.V, INT_MAX);
    distance[source] = 0;

for (int i = 0; i < graph.V - 1; i++){
     for (int u = 0; u < graph.V; u++){
            for (int j = csr.rowPtr[u]; j < csr.rowPtr[u + 1]; j++){
                int v = csr.colIndex[j];
                int w = csr.weights[j];

                if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }
    for (int u = 0; u < graph.V; u++){
        for (int j = csr.rowPtr[u]; j < csr.rowPtr[u + 1]; j++) {
            int v = csr.colIndex[j];
            int w = csr.weights[j];

            if (distance[u] != INT_MAX &&
                distance[u] + w < distance[v])
            {
                cout << "\nNegative Weight Cycle Detected!\n";
                break;
            }
        }
    }

    return distance;
}