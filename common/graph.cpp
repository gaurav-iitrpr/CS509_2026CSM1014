#include "graph.h"

#include <fstream>
#include <iostream>

using namespace std;
bool Graph::readGraph(string filename){
    ifstream fin(filename);
if (!fin){
        cout << "Cannot open file : " << filename << endl;
        return false;
    }
fin >>V>>E;
edges.clear();
for (int i = 0; i < E; i++){
        Edge temp;

        fin >> temp.src
            >> temp.dest
            >> temp.weight;

        edges.push_back(temp);
    }

    fin.close();

    return true;
}