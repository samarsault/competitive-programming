#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int> > Graph;

int n, m, k;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	int u, v;
	cin >> n >> m >> k;
	
	Graph G (n + 1);

	int deg[n + 1];
	bool InQ[n + 1], del[n + 1];

	fill(deg, deg + n + 1, 0);

	for (int i = 0;i < m;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	queue<int> Q;	

	// book keeping
	for (int i = 1;i <= n;i++)
		del[i] = InQ[i] = false;

	for (int i = 1;i <= n;i++)
	{
		if (deg[i] < k)
		{
			Q.push(i);
			InQ[i] = true;
		}
	}

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		InQ[v] = false;
		del[v] = true;

		for (vector<int>::iterator it = G[v].begin();it != G[v].end();it++)
		{
			int w = *it;
			if (!InQ[w] && !del[w])
			{
				deg[w]--;
				if (deg[w] < k)
				{
					Q.push(w);
					InQ[w] = true;
				}
			}
		}
	}
	
	int ans = 0;
	
	for (int i = 1;i <= n;i++)
		if(!del[i]) 
			ans++;

	if (ans > 0)
		cout << "YES" << endl << ans << endl;
	else
		cout << "NO" << endl;
}
