#include "driver.h"
#include "../../common/graph.h"
#include "../../common/csr.h"
#include "../../common/timer.h"
#include "../vertex_coloring/vertex_coloring.h"
#include "../pagerank/pagerank.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
static bool readVC(const string &f, Graph &g)
{
    ifstream in(f);
    if (!in)
    {
        cout << "Cannot open file : " << f << "\n";
        return false;
    }
    int V, E;
    if (!(in >> V >> E) || V <= 0 || E < 0)
        return false;
    g.V = V;
    g.edges.clear();
    for (int i = 0; i < V; i++)
    {
        int u, d;
        if (!(in >> u >> d) || u < 0 || u >= V || d < 0)
            return false;
        for (int j = 0; j < d; j++)
        {
            int v;
            if (!(in >> v) || v < 0 || v >= V || v == u)
                return false;
            g.edges.push_back({u, v, 1});
        }
    }
    g.E = g.edges.size();
    return g.E == 2 * E;
}
static bool readPR(const string &f, Graph &g, double &d, double &tol, int &mi)
{
    ifstream in(f);
    if (!in)
    {
        cout << "Cannot open file : " << f << "\n";
        return false;
    }
    int V, E;
    if (!(in >> V >> E) || V <= 0 || E < 0)
        return false;
    g.V = V;
    g.edges.clear();
    for (int i = 0; i < V; i++)
    {
        int u, n;
        if (!(in >> u >> n) || u < 0 || u >= V || n < 0)
            return false;
        for (int j = 0; j < n; j++)
        {
            int v;
            if (!(in >> v) || v < 0 || v >= V)
                return false;
            g.edges.push_back({u, v, 1});
        }
    }
    string label;
    if (!(in >> label >> d) || label != "DAMPING")
        return false;
    if (!(in >> label >> tol) || label != "TOLERANCE")
        return false;
    if (!(in >> label >> mi) || label != "MAX_ITERATIONS")
        return false;
    if (d <= 0 || d >= 1 || tol <= 0 || mi <= 0)
        return false;
    g.E = g.edges.size();
    return g.E == E;
}
static void runVC(const string &f)
{
    Graph g;
    CSR c;
    if (!readVC(f, g))
    {
        cout << "Invalid Vertex Coloring input\n";
        return;
    }
    c.buildCSR(g);
    Timer t;
    t.start();
    auto colors = greedyVertexColoring(c);
    auto us = t.stop();
    cout << "\nAlgorithm: Greedy Vertex Coloring\nVertex colors:\n";
    for (int i = 0; i < g.V; i++)
        cout << i << " " << colors[i] << "\n";
    cout << "Colors used: " << countColors(colors) << "\nValid: " << (validateColoring(c, colors) ? "true" : "false") << "\nExecution time: " << us << " microseconds\n";
}
static void runPR(const string &f)
{
    Graph g;
    CSR c;
    double d, tol;
    int mi;
    if (!readPR(f, g, d, tol, mi))
    {
        cout << "Invalid PageRank input\n";
        return;
    }
    c.buildCSR(g);
    Timer t;
    t.start();
    auto r = pageRank(c, d, tol, mi);
    auto us = t.stop();
    double sum = 0;
    cout << "\nAlgorithm: PageRank\nDamping: " << d << "\nVertex ranks:\n";
    for (int i = 0; i < g.V; i++)
    {
        cout << i << " " << r.ranks[i] << "\n";
        sum += r.ranks[i];
    }
    cout << "Sum of ranks: " << sum << "\nIterations: " << r.iterations << "\nConverged: " << (r.converged ? "true" : "false") << "\nExecution time: " << us << " microseconds\n";
}
static void vcMenu()
{
    int c;
    while (true)
    {
        cout << "\nVertex Coloring\n1. color_10.txt\n2. color_100.txt\n3. color_10000.txt\n4. color_50000.txt\n5. color_100000.txt\n0. Back\nEnter Choice : ";
        cin >> c;
        if (c == 0)
            return;
        int n = c == 1 ? 10 : c == 2 ? 100
                          : c == 3   ? 10000
                          : c == 4   ? 50000
                                     : 100000;
        if (c >= 1 && c <= 5)
            runVC("assignment_04/tests/vertex_coloring/color_" + to_string(n) + ".txt");
        else
            cout << "Invalid Choice\n";
    }
}
static void prMenu()
{
    int c;
    while (true)
    {
        cout << "\nPageRank\n1. pagerank_10.txt\n2. pagerank_100.txt\n3. pagerank_1000.txt\n4. pagerank_10000.txt\n5. pagerank_50000.txt\n0. Back\nEnter Choice : ";
        cin >> c;
        if (c == 0)
            return;
        int n = c == 1 ? 10 : c == 2 ? 100
                          : c == 3   ? 1000
                          : c == 4   ? 10000
                                     : 50000;
        if (c >= 1 && c <= 5)
            runPR("assignment_04/tests/pagerank/pagerank_" + to_string(n) + ".txt");
        else
            cout << "Invalid Choice\n";
    }
}
void runAssignment4Individual()
{
    int c;
    while (true)
    {
        cout << "\n=====================================\n Assignment 4 Individual Tasks\n=====================================\n1. Vertex Coloring\n2. PageRank\n0. Back\nEnter Choice : ";
        cin >> c;
        if (c == 0)
            return;
        if (c == 1)
            vcMenu();
        else if (c == 2)
            prMenu();
        else
            cout << "Invalid Choice\n";
    }
}
