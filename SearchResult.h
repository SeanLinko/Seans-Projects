#pragma once
#include <string>

using namespace std;

class SearchResult 
{
public:
    // Default Constructor
    SearchResult();
    // Constructor
    SearchResult(bool isFound, string nodes_searched);

    bool isFound;
    
    string nodes_searched;
};