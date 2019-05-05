/*
 * Longest Path in DAG (Unweighted)
 * Complexity: O(m + n)
 * NOTE: Longest Path in arbitrary graph is NP-Complete
 */

#include <iostream>
#include <queue>
#include <vector>
#include <iterator>

using namespace std;

typedef vector<vector<int> > graph;

// Adjacency List
graph G;
// n = no. of vertices
// m = no. of edges
int n, m;

void inputGraph()
{
	cin >> n >> m;
	G.resize(n + 1);
	int u, v;
	for (int i = 0;i < m;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
	}
}

int main(int argc, char *argv[])
{
	inputGraph();

	// indegree[i] = in-degree of the ith vertex
	// lpath[i] = longest path to the ith vertex
	int indegree[n + 1], lpath[n + 1];

	fill (indegree, indegree + n + 1, 0);
	fill (lpath, lpath + n + 1, 0);
	// Calculate Indegree of vertices
	for (int u = 1;u <= n;u++)
		for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
			indegree[*it]++;

	queue<int> Q;
	vector<int> order; // topological order

	for (int u = 1;u <= n;u++)
		if (indegree[u] == 0)
			Q.push(u);

	// BFS
	while (!Q.empty())
	{
		int u = Q.front();
		order.push_back(u);
		Q.pop();
		for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			indegree[*it]--;

			lpath[*it] = max(lpath[*it], 1 + lpath[u]);

			if (indegree[*it] == 0)
				Q.push(*it);
		}
	}

	for (int i = 1;i <= n;i++)
		cout << "Longest path to " << i << " -> " << lpath[i] << ' ';
	cout << endl;
	return 0;
}
