# Lab09

Must follow standards cited here:
https://github.com/olekaspt/LabStandards/blob/main/README.md

## Objective
The objective of this lab is to explore creating and traversing graphs

## Task 1:  Create a directed graph G=(V,E) using Adjacency Matrix method.

Here V is a set of vertices and E is a set of ordered pairs of vertices called edges. An edge(i,j) is directed from i to j.
Design and implement a graph class using the adjacency matrix methodology as explained in the class lecture.  
The class should have the following methods fully implemented.

*	Constructor – This should have an overload indicating the number of vertices in the graph.
*	addEdge(i,j) – Add the edge (i,j) to E.
*	removeEdge(i,j) – Remove the edge (i,j) from E.
*	hasEdge(i,j) – Check if the edge (i,j) ∈ E.
*	outEdges(i) – Return a list of all integers j such that edge (i,j) ∈ E.
*	inEdges(i) – Return a list of all integers j such that edge (j,i) ∈ E.
*	PrintOutAdjacencyMatrix
*	DepthFirstSearch(i,j) - where i is the start node, and j is target.  This will return a struct\class that contains a bool if found, and string that traces the path of nodes searched.
*	BreadthFirstSearch(i,j) - where i is the start node, and j is target.  This will return a struct\class that contains a bool if found, and string that traces the path of nodes searched.
*	Destructor
In your lab report discuss your design for the internal structure for storing vertices and edges.

## Task 2 Create a program that tests the graph class created in Task 1.

Prompt the user for which class method to invoke.  This may look like:

```
How many nodes are in graph?
<get input>

And then show a output like this?

Press 1 to add an edge to graph.
Press 2 remove an edge from graph.
Press 3 Find an edge in the graph.
Press 4 Find the out edges of a vertices
Press 5 Find the in edges of a vertices
Press 6 To Print out Adjacency Matrix
Press 7 to quit.
```

One way To dynamically allocate a 2D array use this code (https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new)

```c++
int nodes = 100;
vector< vector<int> > f(nodes, vector<int>(nodes, 0));
f[3][2] = 1; // use it like arrays
```

1.	Use your test program to test all member functions and ensure the class is working correctly. Check both for positive and negative cases (e.g. removing an edge which is not present in the graph). 
1.	Provide a methodology to read in an adjacency matrix to initialize the graph object.  See previous lab where file was read in (towers of Hannoi).  Can be a specific  option MyExe.exe -f file.txt 
Include in your submission a sample graph that is interesting, say at least 10 nodes, and about 15-20 edges.
1.	Include in the lab report screen shots of the output of all your test results.

## Task 3:  UnitTests
Provide 2 Unit Tests for AT LEAST every method mentioned in Task 1 (except destructor)


## Lab Submission
1. Include all source code from all tasks, input and output files (if any), and any special instructions to compile in a single tar file.
1. A sample graph of a reasonable sized graph (10 nodes, with about ~16 edges) in a adj matrix txt file.  This can be used for testing by the TA
1. Participation Rubric And Lab Report


Participation rubric of teammates.  List out for your all team members how much they participated.  This will go into your Lab report.
```
	               Sean	   Andrew
  Sean (opinion)	50       50	     
  Andrew (opinion)	50	     50	     
```			
			
Example 			
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	20	     40	     40
Member3 (opinion)	20	     40	     40
```



## Lab Grading:
1.	40% - Task 1 has been correctly implemented and meets all requirements.
2.	40% - Task 2 has been correctly implemented and meets all requirements. 
3.	20% - Task 3 has been correctly implemented and meets all requirements.
If program fails to compile, 0% will be given for that Task.
