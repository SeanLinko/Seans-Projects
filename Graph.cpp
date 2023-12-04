#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include "Graph.h"
#include "SearchResult.h"

using namespace std;

Graph::Graph(int num_verticies)
{
    this->num_verticies = num_verticies;
    E.resize(num_verticies, vector<int>(num_verticies, 0));
}

Graph::Graph(const string& filename)
{
    ifstream file;
    file.open(filename);

    if(file.is_open())
    {
        string line;
        num_verticies = 0;
        
        while (getline(file, line)) 
        {
            vector<int> row;
            istringstream iss(line);
            int num;

            while (iss >> num) 
                row.push_back(num);

            num_verticies = max(num_verticies, static_cast<int>(row.size()));
            E.push_back(row);
        }

        for (auto& row : E)
            row.resize(num_verticies, 0);

        file.close();
    }
    else
        cout << "Unable to open file: " << filename << endl;
}

/// @brief Adds an edge to the graph
/// @param i Column
/// @param j Row
/// @return True if added successfully
bool Graph::addEdge(int i, int j)
{
    if (num_verticies <= 0 || i < 0 || j < 0 || i > num_verticies || j > num_verticies)
        return false;
        
    if (E[i][j] == 1)
        return false;
    else 
    {
        E[i][j] = 1;
        return true;
    }
}

/// @brief Removes edge from graph
/// @param i Column
/// @param j Row
/// @return True if removed successfully
bool Graph::removeEdge(int i, int j)
{
    if (num_verticies <= 0 || i < 0 || j < 0 || i > num_verticies || j > num_verticies)
        return false;

    if (E[i][j] == 0)
        return false;
    else 
    {
        E[i][j] = 0;
        return true;
    }
}

/// @brief Checks if entered verticie is an edge
/// @param i Column
/// @param j Row
/// @return True if verticie is an edge
bool Graph::hasEdge(int i, int j)
{
    if (num_verticies <= 0 || i < 0 || j < 0 || i > num_verticies || j > num_verticies)
        return false;

    if (E[i][j] == 1)
        return true;
    else
        return false;
}

/// @brief 
/// @param i 
/// @return
string Graph::outEdges(int i)
{
    if (num_verticies <= 0)
        return "Number of verticies out of scope";
    if (i < 0 || i > num_verticies) 
        return "Input out of scope";
    string list;
    for (int j = 0; j < num_verticies; j++) 
    {
        if (E[i][j] == 1)
            if (j == num_verticies)
                list += to_string(j);
            else
                list += to_string(j) + " ";
    }
    if (list == "")
        list = "No Out Edges For That Input";
    return list;
}

/// @brief 
/// @param i 
/// @return 
string Graph::inEdges(int i)
{
    if (num_verticies <= 0)
        return "Number of verticies out of scope";
    if (i < 0 || i > num_verticies) 
        return "Input out of scope";
    string list = "";
    for (int j = 0; j < num_verticies; j++) 
    {
        if (E[j][i] == 1 && j != num_verticies)
            list += to_string(j) + " ";
        else if (E[j][i] == 1 && j == num_verticies)
            list += to_string(j);
    }
    if (list == "")
        list = "No In Edges For That Input";
    return list;
}

/// @brief Prints out adjacency matrix representing graph
void Graph::PrintOutAdjacencyMatrix()
{
    for (int i = 0; i < num_verticies; i++) 
    {
        for (int j = 0; j < num_verticies; j++) 
            cout << "[" << E[i][j] << "]";
        cout << "\n";
    }
}

/// @brief it searches i's child, and then that child's children until j is found. If not found through first child, it searches i's next child 
/// @param i start node
/// @param j target node
/// @return the path of nodes it took to try and reach target node, returns "Path Not Found" if no path exists from start to target
SearchResult Graph::DepthFirstSearch(int i, int j) 
{
    vector<bool> visited(num_verticies, false);
    vector<int> parent(num_verticies, -1); 
    stack<int> stack;

    visited[i] = true;
    stack.push(i);

    while (!stack.empty()) 
    {
        int current = stack.top();
        stack.pop();

        if (current == j) 
        {
            string pathStr;
            int node = j;
            while (node != -1) 
            {
                pathStr += to_string(node) + " ";
                node = parent[node];
            }
            reverse(pathStr.begin(), pathStr.end());
            return SearchResult(true, pathStr);
        }
    
        for (int neighbor = 0; neighbor < num_verticies; ++neighbor) 
        {
            if (E[current][neighbor] == 1 && !visited[neighbor]) 
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                stack.push(neighbor);
            }
        }
    }

    return SearchResult(false, "Path Not Found");
}

/// @brief starts at i and visits all of its "children" first in search of j, if not found visits the "children's" "children" and so on
        // until j is found or a path is deemed nonexistent
/// @param i start node
/// @param j target node
/// @return the path of nodes it took to reach the target j, if not found returns "Path Not Found"
SearchResult Graph::BreadthFirstSearch(int i, int j)
{
    vector<bool> visited(num_verticies, false); 
    vector<int> parent(num_verticies, -1); 
    queue<int> q;

    visited[i] = true;
    q.push(i);

    while (!q.empty()) 
    {
        int i = q.front();
        q.pop();

        if(i == j) 
        {
            string pathStr;
            int node = j;
            while (node != -1) 
            {
                pathStr += to_string(node) + " ";
                node = parent[node];
            }
            reverse(pathStr.begin(), pathStr.end());
            return SearchResult(true, pathStr);
        }

        for(int neighbor = 0; neighbor < num_verticies; ++neighbor) 
        {
            if(E[i][neighbor] == 1 && !visited[neighbor]) 
            {
                visited[neighbor] = true;
                parent[neighbor] = i;
                q.push(neighbor);
            }
        }
    }

    return SearchResult(false, "Path Not Found");
}

Graph::~Graph()
{
}
