#pragma once
#include <string>
#include <vector>
#include <string>
#include "SearchResult.h"

using namespace std;

class Graph 
{
public:
    // Constructor, should have overload indicating number of verticies
    Graph(int num_verticies);
    // Constructor that takes in a file name 
    Graph(const string& filename);
    // Add the Edge (i,j) to E
    bool addEdge(int i, int j);
    // Remove Edge (i,j) from E
    bool removeEdge(int i, int j);
    // Check if E has the Edge (i,j)
    bool hasEdge(int i, int j);
    // Returns a list of all integers j such that edge (i,j) ∈ E.
    string outEdges(int i);
    // Return a list of all integers j such that edge (j,i) ∈ E.
    string inEdges(int i);
    // Prints a grid of the graph
    void PrintOutAdjacencyMatrix();
    // i is the start node, j is the target
    // Returns the SearchResult with a bool to say if it was found and a string with the path from i to the target
    SearchResult DepthFirstSearch(int i, int j);
    // i is the start node, j is the target
    // Returns the SearchResult with a bool to say if it was found and a string with the path from i to the target
    SearchResult BreadthFirstSearch(int i, int j);
    // Destructor
    ~Graph();

private:
    int num_verticies;
    vector<vector<int>> E;
    SearchResult DFSTool(int current, int target, vector<bool>& found, string& path);
};
