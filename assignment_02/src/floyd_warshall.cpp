#include "floyd_warshall.h"

#include <climits>

using namespace std;
#define INF 1000000000
vector<vector<int>> floydWarshall(Graph &graph){
    vector<vector<int>> dist(graph.V, vector<int>(graph.V, INF));

for (int i = 0; i < graph.V; i++){
        dist[i][i] = 0;
    }

for (int i = 0; i < graph.E; i++){
        int u = graph.edges[i].src;
        int v = graph.edges[i].dest;
        int w = graph.edges[i].weight;

        dist[u][v] = w;
    }

    for (int k = 0; k < graph.V; k++){
        for (int i = 0; i < graph.V; i++){
            for (int j = 0; j < graph.V; j++){
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}