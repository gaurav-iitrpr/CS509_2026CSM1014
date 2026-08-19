#include "kruskal.h"
#include <algorithm>
#include <vector>
using namespace std;


class DSU
{
private:

    vector<int> parent;
    vector<int> rank;

public:

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }


    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }


    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false;


        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};


vector<MSTEdge> kruskalMST(MSTCSR &csr, int vertices)
{
    vector<MSTEdge> edges;

    for (int u = 0; u < vertices; u++)
    {
        for (int i = csr.rowPtr[u];
             i < csr.rowPtr[u + 1];
             i++)
        {
            int v = csr.colIndex[i];
            int weight = csr.weights[i];


            int src = min(u, v);
            int dest = max(u, v);


            bool exists = false;


            for (int j = 0; j < (int)edges.size(); j++)
            {
                if (edges[j].src == src &&
                    edges[j].dest == dest)
                {

                    if (weight < edges[j].weight)
                    {
                        edges[j].weight = weight;
                    }

                    exists = true;
                    break;
                }
            }


            if (!exists)
            {
                MSTEdge edge;

                edge.src = src;
                edge.dest = dest;
                edge.weight = weight;

                edges.push_back(edge);
            }
        }
    }

    sort(
        edges.begin(),
        edges.end(),
        [](const MSTEdge &a, const MSTEdge &b)
        {
            return a.weight < b.weight;
        }
    );


    DSU dsu(vertices);

    vector<MSTEdge> mst;

    for (int i = 0; i < (int)edges.size(); i++)
    {
        if (dsu.unite(
                edges[i].src,
                edges[i].dest))
        {
            mst.push_back(edges[i]);


            if ((int)mst.size() == vertices - 1)
                break;
        }
    }


    return mst;
}