#include <iostream>
#include <vector>
#include <string>

#include "driver.h"

#include "../common/mst_graph.h"
#include "../common/mst_csr.h"

#include "../../common/timer.h"

#include "../src/prims.h"
#include "../src/kruskal.h"

using namespace std;



void runPrim(const string &filename)
{
    Graph graph;

    if (!readMSTGraph(filename, graph))
        return;

    MSTCSR csr;

    csr.buildCSR(graph);

    Timer timer;

    timer.start();

    vector<int> parent = primMST(csr, graph.V);

    long long executionTime = timer.stop();

    int totalWeight = 0;

    cout << "\n=====================================\n";
    cout << "          Prim's MST\n";
    cout << "=====================================\n";

    cout << "\nInput File : " << filename << endl;

    cout << "\nMST edges:\n";

    for (int v = 1; v < graph.V; v++)
    {
        if (parent[v] != -1)
        {
            int u = parent[v];
            int weight = 0;

            for (int i = csr.rowPtr[u];
                 i < csr.rowPtr[u + 1];
                 i++)
            {
                if (csr.colIndex[i] == v)
                {
                    weight = csr.weights[i];
                    break;
                }
            }

            cout << u << " "
                 << v << " "
                 << weight << endl;

            totalWeight += weight;
        }
    }

    cout << "\nTotal MST weight: "
         << totalWeight << endl;

    cout << "Execution time: "
         << executionTime
         << " microseconds\n";
}



void runKruskal(const string &filename)
{
    Graph graph;

    if (!readMSTGraph(filename, graph))
        return;

    MSTCSR csr;

    csr.buildCSR(graph);

    Timer timer;

    timer.start();

    vector<MSTEdge> mst =
        kruskalMST(csr, graph.V);

    long long executionTime =
        timer.stop();

    int totalWeight = 0;

    cout << "\n=====================================\n";
    cout << "          Kruskal's MST\n";
    cout << "=====================================\n";

    cout << "\nInput File : " << filename << endl;

    cout << "\nMST edges:\n";

    for (int i = 0; i < (int)mst.size(); i++)
    {
        cout << mst[i].src << " "
             << mst[i].dest << " "
             << mst[i].weight << endl;

        totalWeight += mst[i].weight;
    }

    cout << "\nTotal MST weight: "
         << totalWeight << endl;

    cout << "Execution time: "
         << executionTime
         << " microseconds\n";
}


void runAssignment3()
{
    int choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "          Assignment 3\n";
        cout << "=====================================\n";

        cout << "1. Kruskal's MST\n";
        cout << "2. Prim's MST\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;


        switch (choice)
        {


            case 1:
            {
                int testChoice;

                cout << "\n========== KRUSKAL'S MST ==========\n";

                cout << "1. mst_10.txt\n";
                cout << "2. mst_100.txt\n";
                cout << "3. mst_10000.txt\n";
                cout << "4. mst_50000.txt\n";
                cout << "5. mst_100000.txt\n";
                cout << "6. generated_mst.txt\n";
                cout << "7. Run All Test Files\n";
                cout << "0. Back\n";

                cout << "\nEnter Choice : ";
                cin >> testChoice;


                switch (testChoice)
                {
                    case 1:
                        runKruskal(
                            "assignment_03/tests/mst_10.txt"
                        );
                        break;

                    case 2:
                        runKruskal(
                            "assignment_03/tests/mst_100.txt"
                        );
                        break;

                    case 3:
                        runKruskal(
                            "assignment_03/tests/mst_10000.txt"
                        );
                        break;

                    case 4:
                        runKruskal(
                            "assignment_03/tests/mst_50000.txt"
                        );
                        break;

                    case 5:
                        runKruskal(
                            "assignment_03/tests/mst_100000.txt"
                        );
                        break;

                    case 6:
                        runKruskal(
                            "assignment_03/tests/generated_mst.txt"
                        );
                        break;

                    case 7:

                        runKruskal(
                            "assignment_03/tests/mst_10.txt"
                        );

                        runKruskal(
                            "assignment_03/tests/mst_100.txt"
                        );

                        runKruskal(
                            "assignment_03/tests/mst_10000.txt"
                        );

                        runKruskal(
                            "assignment_03/tests/mst_50000.txt"
                        );

                        runKruskal(
                            "assignment_03/tests/mst_100000.txt"
                        );

                        runKruskal(
                            "assignment_03/tests/generated_mst.txt"
                        );

                        break;

                    case 0:
                        break;

                    default:
                        cout << "\nInvalid Choice!\n";
                }

                break;
            }



            case 2:
            {
                int testChoice;

                cout << "\n========== PRIM'S MST ==========\n";

                cout << "1. mst_10.txt\n";
                cout << "2. mst_100.txt\n";
                cout << "3. mst_10000.txt\n";
                cout << "4. mst_50000.txt\n";
                cout << "5. mst_100000.txt\n";
                cout << "6. generated_mst.txt\n";
                cout << "7. Run All Test Files\n";
                cout << "0. Back\n";

                cout << "\nEnter Choice : ";
                cin >> testChoice;


                switch (testChoice)
                {
                    case 1:
                        runPrim(
                            "assignment_03/tests/mst_10.txt"
                        );
                        break;

                    case 2:
                        runPrim(
                            "assignment_03/tests/mst_100.txt"
                        );
                        break;

                    case 3:
                        runPrim(
                            "assignment_03/tests/mst_10000.txt"
                        );
                        break;

                    case 4:
                        runPrim(
                            "assignment_03/tests/mst_50000.txt"
                        );
                        break;

                    case 5:
                        runPrim(
                            "assignment_03/tests/mst_100000.txt"
                        );
                        break;

                    case 6:
                        runPrim(
                            "assignment_03/tests/generated_mst.txt"
                        );
                        break;

                    case 7:

                        runPrim(
                            "assignment_03/tests/mst_10.txt"
                        );

                        runPrim(
                            "assignment_03/tests/mst_100.txt"
                        );

                        runPrim(
                            "assignment_03/tests/mst_10000.txt"
                        );

                        runPrim(
                            "assignment_03/tests/mst_50000.txt"
                        );

                        runPrim(
                            "assignment_03/tests/mst_100000.txt"
                        );

                        runPrim(
                            "assignment_03/tests/generated_mst.txt"
                        );

                        break;

                    case 0:
                        break;

                    default:
                        cout << "\nInvalid Choice!\n";
                }

                break;
            }


            case 0:
                return;


            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}