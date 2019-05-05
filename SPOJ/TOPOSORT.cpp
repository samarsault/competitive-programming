#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int> > graph;

int main(int argc, char *argv[])
{
	int i, u, v, n, m;
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	graph G (n + 1);
	int indegree[n+1];

	std::fill(indegree, indegree + n + 1, 0);

	for (i = 0;i < m;i++)
	{
		cin >> u >> v;
		indegree[v]++;
		G[u].push_back(v);
	}

	priority_queue<int, vector<int>, greater<int> > Q;

	for (u = 1;u <= n;u++)
		if (indegree[u] == 0)
			Q.push(u);

	
	int vis = 0;

	vector<int> sol;
	while (!Q.empty())
	{
		vis++;
		u = Q.top();
		sol.push_back(u);
		Q.pop();
		for (std::vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			indegree[*it]--;
			if (indegree[*it] == 0)
				Q.push(*it);
		}
	}
	if (vis != n)
		cout << "Sandro fails.";
	else {
		for (i = 0, n = sol.size();i<n;i++)
			cout << sol[i] << ' ';

	}
	cout << endl;
	return 0;
}
