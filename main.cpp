#include <iostream>
#include <vector>
#include "Graph.h"
#include "SearchResult.h"

using namespace std;

int main() 
{
    int nodeInput;
    int actionInput;
    
    cout << "How many nodes are in the graph?" << endl;
    cin >> nodeInput;

    auto testGraph = Graph(nodeInput);

    while(actionInput!=7)
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Press 1 to add an edge to graph" << endl;
        cout << "Press 2 remove an edge from graph" << endl;
        cout << "Press 3 Find an edge in the graph" << endl;
        cout << "Press 4 Find the out edges of a vertices" << endl;
        cout << "Press 5 Find the in edges of a vertices" << endl;
        cout << "Press 6 To Print out Adjacency Matrix (Change for Lab11)" << endl;
        cout << "Press 7 to quit. (Changing it again for Lab11)" << endl;
        cout << "----------------------------------------" << endl;
        cin >> actionInput;
        
        int userEdge1;
        int userEdge2;
        bool actionCompleted;

        switch(actionInput)
        {
            case 1:
                cout << "\nEnter the Edge you want to add (ex 1 3)" << endl;
                cin >> userEdge1 >> userEdge2;
                
                testGraph.addEdge(userEdge1, userEdge2);
                break;
            case 2:
                cout << "\nEnter the Edge you want to remove (ex 1 3)" << endl;
                cin >> userEdge1 >> userEdge2;
                
                testGraph.removeEdge(userEdge1, userEdge2);
                break;
            case 3:
                cout << "\nEnter the Edge you want to check is present (ex 1 3)" << endl;
                cin >> userEdge1 >> userEdge2;
                
                actionCompleted = testGraph.hasEdge(userEdge1, userEdge2);

                if (actionCompleted)
                    cout << "Edge has been found!" << endl;
                else 
                    cout << "Edge does not exist" << endl;
                break;
            case 4:
                cout << "\nEnter a vertice to find its out edges (ex 1)" << endl;
                cin >> userEdge1;

                cout << testGraph.outEdges(userEdge1);
                break;
            case 5:
                cout << "\nEnter a vertice to find its in edges (ex 1)" << endl; 
                cin >> userEdge1;

                cout << testGraph.inEdges(userEdge1);
                break;
            case 6:
                cout << "\nHere is the printed adjacency matrix" << endl; 

                testGraph.PrintOutAdjacencyMatrix();
                break;
            case 7:
                cout << "\n Program has ended" << endl;
                break;
        }

        if (actionInput == 7)
            break;
    }

    auto fart = testGraph.BreadthFirstSearch(1,3).nodes_searched;

    cout << fart;

    return 0;
}