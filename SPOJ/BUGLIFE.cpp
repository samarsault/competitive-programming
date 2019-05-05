/*
 * Bipartite Graph
 */

#include <iostream>
#include <vector>

using namespace std;

int gender[2001], visited[2001], susp = false;

void dfs(vector<vector<int> > & G, int u)
{
	visited[u] = true;
	for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
	{
		if (gender[u] == -1)
		{
			if (visited[*it])
				gender[u] = !gender[*it];
			else
				gender[u] = 1;
		}
		
		if (!visited[*it])
		{
			if (gender[u] == 1)
				gender[*it] = 0;
			else 
				gender[*it] = 1;

			dfs(G, *it);
		}
		else {
			if (gender[u] == gender[*it])
			{
				susp = true;
				break;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int t, T;
	cin >> T;

	int i, n, ml, u, v;
	for (t = 1;t <= T;t++)
	{
		fill(gender, gender + 2001, -1);
		fill(visited, visited + 2001, false);

		susp = false;
		cin >> n >> ml;

		vector<vector<int> > G(n+1);
		
		for (i = 0;i < ml;i++)
		{
			cin >> u >> v;
			G[u].push_back(v);
		}

		for (int i = 1;i <= n;i++)
		{
			if (!visited[i] && !susp)
			{
				dfs(G, i);
			}
		}

		cout << "Scenario #" << t << ':' << endl;
		
		if (susp)
			cout << "Suspicious bugs found!" << endl;
		else 
			cout << "No suspicious bugs found!" << endl;
	}
	return 0;
}
