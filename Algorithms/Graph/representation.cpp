/*
	Representations of graph -
	1. Adjacency Matrix (2D Array) of size | V | x | V |
	2. Adjacency List
*/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	const int N = 10;
	// Adjacency Matrix
	// V[i][j] = 1 if V[i] and V[j] are connected by an edge, 0 otherwise
	int V[N][N];

	// Adjacency List
	// Each vertex maintains a list of vertices that are adjacent to it.
	vector< vector<int> > G;
	/*
		Operations
		Check if Edge V[i], V[j] is present in G
			1. Matrix - O(1)
			2. List - O(min(deg(V[i]), deg(v[j])))
		Iterating through the list of neighbours
			1. Matrix - O( | V | )
			2. List - O(deg(V[i]))
	*/
	return 0;
}
