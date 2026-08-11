#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};
class Graph{
public:
int V;          
int E;          

    vector<Edge> edges;
    bool readGraph(string filename);
};

#endif