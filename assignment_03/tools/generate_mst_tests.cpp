#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;
};

int main()
{
    srand((unsigned)time(NULL));

    int vertices;
    int edges;

    cout << "Enter number of vertices : ";
    cin >> vertices;

    long long maxEdges =
        1LL * vertices * (vertices - 1) / 2;

    cout << "Maximum possible edges : "
         << maxEdges << endl;

    cout << "Enter number of edges : ";
    cin >> edges;

    if (vertices < 2)
    {
        cout << "Vertices must be at least 2.\n";
        return 0;
    }

    if (edges < vertices - 1 ||
        (long long)edges > maxEdges)
    {
        cout << "For a connected graph, edges must be between "
             << vertices - 1 << " and "
             << maxEdges << ".\n";

        return 0;
    }


    /*
        Adjacency list
    */

    vector<vector<pair<int, int>>> adj(vertices);


    /*
        Set is used to avoid duplicate edges.

        We store only the generated edges,
        NOT all possible edges.
    */

    set<pair<int, int>> usedEdges;


    /*
        Step 1:
        Create a connected graph.

        0 - 1
        1 - 2
        2 - 3
        ...
        V-2 - V-1
    */

    for (int i = 0; i < vertices - 1; i++)
    {
        int u = i;
        int v = i + 1;

        int weight = 1 + rand() % 100;

        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));

        usedEdges.insert(make_pair(u, v));
    }


    /*
        Step 2:
        Add remaining random edges.

        Only generate the number of edges
        that we actually need.
    */

    while ((int)usedEdges.size() < edges)
    {
        int u = rand() % vertices;
        int v = rand() % vertices;

        if (u == v)
            continue;

        if (u > v)
        {
            int temp = u;
            u = v;
            v = temp;
        }

        pair<int, int> edge = make_pair(u, v);

        if (usedEdges.find(edge) != usedEdges.end())
            continue;

        int weight = 1 + rand() % 100;

        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));

        usedEdges.insert(edge);
    }


    /*
        Output file
    */

    string filename =
        "assignment_03/tests/generated_mst.txt";

    ofstream fout(filename);

    if (!fout)
    {
        cout << "Cannot create file : "
             << filename << endl;

        return 0;
    }


    /*
        First line:

        V E
    */

    fout << vertices << " "
         << edges << endl;


    /*
        Format:

        vertex degree neighbour weight ...
    */

    for (int i = 0; i < vertices; i++)
    {
        fout << i << " "
             << adj[i].size();

        for (int j = 0;
             j < (int)adj[i].size();
             j++)
        {
            fout << " "
                 << adj[i][j].first
                 << " "
                 << adj[i][j].second;
        }

        fout << endl;
    }

    fout.close();


    cout << "\n=====================================\n";
    cout << "     MST Test Case Generated\n";
    cout << "=====================================\n";

    cout << "File : "
         << filename << endl;

    cout << "Vertices : "
         << vertices << endl;

    cout << "Edges : "
         << edges << endl;

    cout << "Status : Success\n";

    return 0;
}