// C++ program for solution of M
// Coloring problem using backtracking

#include <bits/stdc++.h>
using namespace std;

class Graph{
	bool** graph;
	int vertices;
	int* color;

public:

	Graph();
	void printSolution(int);
	bool isSafe(int, int);
	bool graphColoringUtil(int, int);
	bool graphColoring(int);
	void printSolution();
	void initializeGraph();	
};

Graph :: Graph(){
	graph = nullptr;
	color = nullptr;
	vertices = 0;
}

bool Graph :: isSafe(int v, int c){
	/* A utility function to check if
	the current color assignment
	is safe for vertex v i.e. checks
	whether the edge exists or not
	(i.e, graph[v][i]==1). If exist
	then checks whether the color to
	be filled in the new vertex(c is
	sent in the parameter) is already
	used by its adjacent
	vertices(i-->adj vertices) or
	not (i.e, color[i]==c) */


	for (int i = 0; i < vertices; i++)
		if (graph[v][i] && c == color[i])
			return false;

	return true;
}

bool Graph :: graphColoringUtil(int m, int v){
	/* A recursive utility function
	to solve m coloring problem */


	/* base case: If all vertices are
	assigned a color then return true */
	if (v == vertices)
		return true;

	/* Consider this vertex v and
	try different colors */
	for (int c = 1; c <= m; c++) {

		/* Check if assignment of color
		c to v is fine*/
		if (isSafe(v, c)) {
			color[v] = c;

			/* recur to assign colors to
			rest of the vertices */
			if (graphColoringUtil(m, v + 1) == true) return true;

			/* If assigning color c doesn't
			lead to a solution then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	this vertex then return false */
	return false;
}

bool Graph :: graphColoring(int m){
	/* This function solves the m Coloring
	problem using Backtracking. It mainly
	uses graphColoringUtil() to solve the
	problem. It returns false if the m
	colors cannot be assigned, otherwise
	return true and prints assignments of
	colors to all vertices. Please note
	that there may be more than one solutions,
	this function prints one of the
	feasible solutions.*/


	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	for (int i = 0; i < vertices; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(m, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}

	// Print the solution
	printSolution();
	return true;
}

void Graph :: printSolution(){
	/* A utility function to print solution */

	cout << "Solution Exists:"
		<< " Following are the assigned colors"
		<< "\n";
	for (int i = 0; i < vertices; i++)
		cout << " " << color[i] << " ";

	cout << "\n";
}

void Graph :: initializeGraph(){
	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/

	// Allocate memory space to color array and graph
	graph = new bool*[vertices];
	color = new int[vertices];


	for(int i = 0; i < vertices; i++){
		graph[i] = new bool[vertices];
	}

	//	Initialize color and graph to default 0 values
	for(int i = 0; i < vertices; i++){
		color[i] = 0;
		for(int j = 0; j < vertices; j++){
			graph[i][j] = 0;
		}
	}

	// Store graph as adjacency matrix
	int edges = 0;
	int n1 = 0;
	int n2 = 0;
	cout<<"Enter number of vertices in the graph: ";
	cin>>vertices;
	cout<<"Enter number of edges in the graph: ";
	cin>>edges;

	for(int i = 0; i < edges; i++){
		cout<<"Enter end vertices of the edges (n1 n2): ";
		cin>>n1>>n2;
		graph[n1][n2] = 1;
		graph[n2][n1] = 1;
	}
}

// Driver code
int main()
{
	Graph grpObj;
	grpObj.initializeGraph();
	// Function call
	int m = 0;
	cout<<"Enter m-color test number(m):";
	cin>>m;
	grpObj.graphColoring(m);

	return 0;
}







