#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <gtest/gtest.h>
#include "Graph.h"
#include "SearchResult.h"

using namespace std;

TEST(AddEdgeTest, WithinBounds)
{
    auto test = Graph(10);

    ASSERT_TRUE(test.addEdge(1,3));
}

TEST(AddEdgeTest, OutsideBounds)
{
    auto test = Graph(10);

    ASSERT_FALSE(test.addEdge(12,12));
}

TEST(RemoveEdgeTest, Removed)
{
    auto test = Graph(10);
    test.addEdge(1,3);

    ASSERT_TRUE(test.removeEdge(1,3));
}
TEST(RemoveEdgeTest, NotRemoved)
{
    auto test = Graph(10);
    test.addEdge(1,3);

    ASSERT_FALSE(test.removeEdge(4,6));
}

TEST(HasEdgeTest, EdgeNotPresent) 
{
    auto test = Graph(10);
    test.addEdge(5,4);

    ASSERT_FALSE(test.hasEdge(2,8));
}
TEST(HasEdgeTest, EdgePresent) 
{
    auto test = Graph(10);
    test.addEdge(5,4);

    ASSERT_TRUE(test.hasEdge(5,4));
}

TEST(OutEdgesTest, OutEdgesAreExpected)
{
    auto test = Graph(10);
    test.addEdge(1,2);
    test.addEdge(1,4);
    test.addEdge(1,7);
    test.addEdge(1,8);
    test.addEdge(1,9);

    ASSERT_EQ(test.outEdges(1), "2 4 7 8 9 ");   
}
TEST(OutEdgesTest, NoOutEdges)
{
    auto test = Graph(10);
    test.addEdge(9,2);
    test.addEdge(2,4);
    test.addEdge(6,7);
    test.addEdge(5,8);
    test.addEdge(3,9);

    ASSERT_EQ(test.outEdges(1), "No Out Edges For That Input");   
}

TEST(InEdgesTest, InEdgesAreExpected)
{
    auto test = Graph(10);
    test.addEdge(0,4);
    test.addEdge(3,4);
    test.addEdge(6,4);
    test.addEdge(7,4);
    test.addEdge(9,4);

    ASSERT_EQ(test.inEdges(4), "0 3 6 7 9 ");   
}

TEST(InEdgesTest, NoInEdges)
{
    auto test = Graph(10);
    test.addEdge(1,5);
    test.addEdge(4,3);
    test.addEdge(2,7);
    test.addEdge(6,4);
    test.addEdge(8,0);

    ASSERT_EQ(test.inEdges(2), "No In Edges For That Input");   
}

TEST(DFSTest, ExistingPath)
{
    auto test = Graph(5);

    test.addEdge(0,1);
    test.addEdge(1,3);
    test.addEdge(1,4);
    test.addEdge(3,1);
    test.addEdge(3,4);
    test.addEdge(4,2);

    string line = test.DepthFirstSearch(0,2).nodes_searched;

    ASSERT_EQ(test.DepthFirstSearch(0,2).nodes_searched, " 0 1 4 2");
}

TEST(DFSTest, NonExistentPath)
{
    auto test = Graph(5);

    test.addEdge(0,0);
    test.addEdge(2,3);
    test.addEdge(1,4);
    test.addEdge(2,0);

    string line = test.DepthFirstSearch(2,4).nodes_searched;

    ASSERT_EQ(test.DepthFirstSearch(2,4).nodes_searched, "Path Not Found");
}

TEST(BFSTest, ExistingPath)
{
    auto test = Graph(5);

    for (int i = 0; i < 4; ++i)
        test.addEdge(i, i + 1);

    ASSERT_EQ(test.BreadthFirstSearch(0, 4).nodes_searched, " 0 1 2 3 4");
}
TEST(BFSTest, NonExistentPath)
{
    auto test = Graph(5);
    
    test.addEdge(0, 1);
    test.addEdge(1, 2);
    test.addEdge(3, 4);

    ASSERT_EQ(test.BreadthFirstSearch(0, 4).nodes_searched, "Path Not Found");   
}

TEST(FileTest, FileDataTOGraph) 
{
    auto test = Graph("/home/seanlinko/Lab09/filetest.txt");

    test.PrintOutAdjacencyMatrix();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}