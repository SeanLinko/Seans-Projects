#include <iostream>
#include "SearchResult.h"

using namespace std;

SearchResult::SearchResult()
{
    isFound = false;
    nodes_searched = "";
}

SearchResult::SearchResult(bool isFound, string nodes_searched)
{
    this->isFound = isFound;
    this->nodes_searched = nodes_searched;
}
