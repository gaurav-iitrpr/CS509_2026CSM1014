#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void generateGraph(string filename, int vertices){
    ofstream file(filename);
    if (!file){
        cout << "Error opening file.\n";
        return;
    }
    int edges = vertices * 5;
    file <<vertices << " " <<edges<<endl;
    srand((unsigned)time(0));
    for (int i = 0; i < edges; i++){
        int source = rand() % vertices;
        int destination = rand() % vertices;
        while (destination == source){
            destination = rand() % vertices;
        }
        int weight = 1 + rand() % 20;
        file << source << " "<< destination << " "<< weight << endl;
    }
    file.close();
    cout << "\nGraph generated successfully!\n";
    cout << "Vertices : " << vertices << endl;
    cout << "Edges    : " << edges << endl;
    cout << "File     : " << filename << endl;
}
int main(){
    int vertices;
    cout << "=====================================\n";
    cout << "     Random Graph Generator\n";
    cout << "=====================================\n";
    cout << "Enter number of vertices: ";
    cin >> vertices;
    if (vertices < 2){
        cout << "Number of vertices must be at least 2.\n";
        return 1;
    }
    generateGraph( "assignment_02/tests/generated_test.txt",vertices);
    return 0;
}