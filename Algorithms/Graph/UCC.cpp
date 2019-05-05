/*
 * Connected Components
 * In Undirected Graph using BFS
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void BFS(vector<vector<int> > & G, bool *exp, int s)
{	
	if (!exp[s])
	{
		queue<int> Q;
		Q.push(s);
		exp[s] = true;

		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			
			for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
			{
				if(!exp[*it])
				{
					exp[*it] = true;
					Q.push(*it);
				}
			}
	
		}
	}
}

int CC(vector<vector<int> > & G, int n)
{
	int count = 0;
	
	bool explored[n];
	memset(explored, false, sizeof(explored));

	for (int i = 0;i < n;i++)
	{
		if (!explored[i])
		{
			BFS(G, explored, i);
			count++;
		}
	}

	return count;
}

int main()
{
	int t, n, m, u, v;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector< vector<int> > G(n);
		for (int i = 0;i < m;i++)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout << CC(G, n) << endl;
	}
}
