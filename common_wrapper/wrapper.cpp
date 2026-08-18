#include <iostream>
#include "../assignment_01/driver/driver.h"
#include "../assignment_02/driver/driver.h"
#include "../assignment_03/driver/driver.h"
using namespace std;

void showMenu()
{
    int choice;
    do
    {
        cout << "\n=====================================\n";
        cout << "      CS509 Assignment Menu\n";
        cout << "=====================================\n";
        cout << "1. Assignment 1 - GEMM\n";
        cout << "2. Assignment 2 -Graph Algorithms\n";
        cout << "3. Assignment 3-\n";
        cout << "0. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                runAssignment1();
                break;

            case 2:
                runAssignment2();
                break;
   
                case 3:
            runAssignment3();
                break;
            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 0);
}

int main()
{
    showMenu();
    return 0;
}