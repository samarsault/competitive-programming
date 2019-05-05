/*
 * Breadth First Search
 * Find shortest path in unweighted graph
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
#include <cstdio>

using namespace std;

// no. of vertices in graph
const int N = 5;

vector< vector<int> > G;

// dist[i] is the shortest path from S -> i after BFS
int dist[N + 1];

// visited[i] indicated whether a vertex has been visited
bool visited[N + 1];


// BFS (start vertex)
void BFS(int S)
{
	queue<int> Q;
	visited[S] = true;

	Q.push(S);

	vector<int>::iterator it;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (it = G[u].begin();it != G[u].end();it++)
		{
			int v = *it;
			if (!visited[v])
			{
				visited[v] = true;
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
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

int main()
{

	// Build Graph
	buildGraph();

	BFS(3);

	cout << dist[5] << endl;
	return 0;
}
