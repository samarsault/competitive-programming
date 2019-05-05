/*
	Depth First Search (DFS)
	Implemented using -
		1. Stack
		2. Recursion
	Complexity: O(|V| + |E|)
	Space: O(|V|) to maintain the vertices visited till now
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 5;

vector< vector<int> > G;

void DFSVisit(int s, bool *exp)
{	
	cout << s << endl;
	vector<int>::iterator v;
	exp[s] = true;
	for (v = G[s].begin();v != G[s].end();v++)
		if (!exp[*v])
			DFSVisit(*v, exp);
}

void DFS(int s)
{
	bool *exp = new bool[N + 1];
	fill(exp, exp + N + 1, false);
	
	DFSVisit(s, exp);
}

void buildGraph()
{
	vector<int> tmp;
    // G[0];
	G.push_back(tmp);

	vector<int> V1, V2, V3, V4, V5;
	V1.push_back(2);
	V1.push_back(5);
	G.push_back(V1);

	V2.push_back(1);
	V2.push_back(5);
	V2.push_back(3); 
	V2.push_back(4);
	G.push_back(V2);

	V3.push_back(2);
	V3.push_back(4);
	G.push_back(V3);

	V4.push_back(2);
	V4.push_back(5);
	V4.push_back(3);
	G.push_back(V4);

	V5.push_back(4);
	V5.push_back(1);
	V5.push_back(2);
	G.push_back(V5);
}

int main(void)
{
	buildGraph();
	DFS(1);
}
