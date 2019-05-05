#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int> > graph;

int n, m, p;

int bfs(graph G, int s, int n)
{
	int count = 0;
	queue<int> Q;
	bool visited[n + 1];
	fill(visited, visited + n + 1, false);
	Q.push(s);
	visited[s] = true;
	
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		for (vector<int>::iterator i = G[u].begin();i != G[u].end();i++)
		{
			if (!visited[*i])
			{
				Q.push(*i);
				visited[*i] = true;
			}
		}
	}

	for (int i = 1;i <= n;i++)
		count += visited[i];

	return (count - 1);

}

int main()
{
	int n, m, p;
	cin >> n;
	graph G(n + 1);
	
	for (int i = 1;i <= n;i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> p;
			G[i].push_back(p);
		}
	}
	
	for (int i = 1;i <= n;i++)
	{
		cout << "Minister " << i << " : " << bfs(G, i, n) << endl;
	}

	return 0;
}
