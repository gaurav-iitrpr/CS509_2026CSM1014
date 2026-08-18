#include "mst_graph.h"
#include <fstream>
#include <iostream>

using namespace std;

bool readMSTGraph(string filename, Graph &graph)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Cannot open file : " << filename << endl;
        return false;
    }

    fin >> graph.V >> graph.E;

    graph.edges.clear();

    for (int i = 0; i < graph.V; i++)
    {
        int vertex;
        int degree;

        fin >> vertex >> degree;

        for (int j = 0; j < degree; j++)
        {
            int neighbour;
            int weight;

            fin >> neighbour >> weight;

            Edge edge;

            edge.src = vertex;
            edge.dest = neighbour;
            edge.weight = weight;

            graph.edges.push_back(edge);
        }
    }

    fin.close();

    return true;
}