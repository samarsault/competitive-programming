#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include <set>
#include <queue>

#define MAX 2000

using namespace std;

int G[MAX+1][MAX+1], n = 1;
long long inf = 0;

int ShortestPath(int s, int e)
{
	bool exp[n+1];
	long long dist[n+1];
	
	fill(dist, dist + n + 1, inf);
	fill(exp, exp + n + 1, false);

	dist[s] = 0;

	for (int i = 0;i <= n;i++)
	{
		int u = -1;
		for (int j = 1;j <= n;j++)
		{
			if (!exp[j])
			{
				if (u == -1 || dist[j] < dist[u])	
					u = j;
			}
		}

		if (u == e) break;

		exp[u] = true;

		for (int j = 1;j <= n;j++)
			if (G[u][j])
				dist[j] = min(dist[j], dist[u] + G[u][j]);
	}
	
	if (dist[e] == inf) 
		return -1;
	
	return dist[e];
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	
	for (int i = 0;i<=MAX;i++)
		for (int j = 0;j<=MAX;j++)
			G[i][j] = 0;

	int m, u, v, w, a, b;
	cin >> m >> a >> b;
	
	for (int i = 0;i < m;i++)
	{
		cin >> u >> w >> v;
		n = max(max(u, v), n);
		if (!G[u][v])
			G[u][v] = G[v][u] = w;
		else
			G[u][v] = G[v][u] = min(G[u][v], w);
		inf += w;
	}
	

	inf *= 2;
	
	int ans = ShortestPath(a, b);
	if (ans >= 0)
		cout << "YES" << endl << ans << endl;
	else
		cout << "NO" << endl;
	return 0;
}
