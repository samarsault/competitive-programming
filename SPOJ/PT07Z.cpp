#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, *dist, *visited;
vector<vector<int> > G;

int BFS(int s)
{
	// all nodes unvisited initially
	fill(visited, visited + n + 1, false);
	int u;
	queue<int> Q;
	visited[s] = true;
	dist[s] = 0;
	Q.push(s);

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			if (!visited[*it])
			{
				Q.push(*it);
				dist[*it] = 1 + dist[u];
				visited[*it] = true;
			}
		}
	}

	int maxdist = 0, node = s;
	for (int i = 1;i <= n;i++)
	{
		if (dist[i] > maxdist)
		{
			maxdist = dist[i];
			node = i;
		}
	}
	
	return node;
}

int main(int argc, char *argv[])
{
	int u, v;
	cin >> n;

	// Memory
	dist = new int[n + 1];
	visited = new int[n + 1];
	G.resize(n + 1);

	while (cin >> u >> v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int farthest = BFS(1);
	cout << dist[BFS(farthest)];
	return 0;
}

