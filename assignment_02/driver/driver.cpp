#include <iostream>
#include <climits>
#include "driver.h"
#include "../../common/graph.h"
#include "../../common/csr.h"
#include "../src/bellman_ford.h"
#include "../src/floyd_warshall.h"

#include "../../common/timer.h"
using namespace std;

void runBellmanFord(string filename){
    Graph graph;
    CSR csr;

    if (!graph.readGraph(filename)){
        return;
    }

    csr.buildCSR(graph);
 Timer timer;

    timer.start();

    vector<int> distance = bellmanFord(graph, csr, 0);
 long long executionTime = timer.stop();
cout << "\n===== Bellman Ford Result =====\n\n";
cout << "Source Vertex : 0\n\n";

    for (int i = 0; i < graph.V; i++){
        cout << "Vertex " << i << " : ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }

    cout << "\nExecution Time : "
         << executionTime
         << " microsecond\n";
}
void runFloydWarshall(string filename){
    Graph graph;

    if (!graph.readGraph(filename)) {
        return;
    }

    Timer timer;

    timer.start();

    vector<vector<int>> distance = floydWarshall(graph);

    long long executionTime = timer.stop();

    cout << "\n=====================================\n";
    cout << "       Floyd-Warshall Result\n";
    cout << "=====================================\n";

    cout << "\nFile : " << filename << endl;
    cout << "\nAll-Pairs Shortest Path Matrix\n\n";

    for (int i = 0; i < graph.V; i++)
    {
        for (int j = 0; j < graph.V; j++)
        {
            if (distance[i][j] >= 1000000000)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }

        cout << endl;
    }
 cout << "\nExecution Time : "
         << executionTime
         << " microseconds\n";
}
void runAssignment2()
{
    int choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "        Assignment 2\n";
        cout << "=====================================\n";

        cout << "1. Bellman Ford\n";
        cout << "2. Floyd Warshall\n";
        cout << "0. Back\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int testChoice;

                cout << "\n===== Bellman Ford =====\n";

                cout << "1. Run bf_test_01.txt\n";
                cout << "2. Run generated test file\n";
                cout << "0. Back\n";

                cout << "Enter Choice : ";
                cin >> testChoice;

                switch (testChoice)
                {
                    case 1:
                        runBellmanFord("assignment_02/tests/bf_test_01.txt");
                        break;

                    case 2:
                        runBellmanFord("assignment_02/tests/generated_test.txt");
                        break;

                    case 0:
                        break;

                    default:
                        cout << "\nInvalid Choice\n";
                }

                break;
            }

            case 2:
            {
                int testChoice;

                cout << "\n===== Floyd Warshall =====\n";

                cout << "1. Run fw_test_01.txt\n";
                cout << "2. Run generated test\n";
                cout << "0. Back\n";

                cout << "Enter Choice : ";
                cin >> testChoice;

                switch (testChoice)
                {
                case 1:
                   runFloydWarshall("assignment_02/tests/fw_test_01.txt");
                    break;

                    case 2:
                    runFloydWarshall("assignment_02/tests/generated_test.txt");
                
                default:
                   cout << "\nInvalid Choice\n";
                    break;
                }
                break;
            }
            case 0:
                return;

            default:
                cout << "\nInvalid Choice\n";
                break;
        }
    }
}