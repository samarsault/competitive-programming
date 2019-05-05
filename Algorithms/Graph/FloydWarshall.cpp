#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> pi;

// No. of Vertices, Edges
int n, m;
// Edge Set
vector<pair<pi, int> > E; // < (u, v), w >

#define INF 1000000000
#define W(u, v) weight[make_pair(u, v)]

int FloydWarshall()
{
	// W[i][j][k] = shortest path from i to k using the vertices 1, 2, ... k
	int W[n+1][n+1][n+1];

	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			W[i][j][0] = INF;

	for (vector<pair<pi,int> >::iterator edge = E.begin();edge != E.end();edge++)
	{
		int i = edge->first.first, j = edge->first.second;
		W[i][j][0] = edge->second;
	}

	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				W[i][j][k] = min(W[i][j][k - 1], W[i][k][k - 1] + W[k][j][k - 1]); // second can overflow infinity value
	
	int ans = 0, u,v;

	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (W[i][j][n] != INF)
				ans = max(ans, W[i][j][n]);
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int u, v, w;
	for(int j = 0;j < m;j++) 
	{
		cin >> u >> v >> w;
		E.push_back(make_pair(make_pair(u, v), w));
		E.push_back(make_pair(make_pair(v, u), w)); // undirected
		//G[u].push_back(make_pair(v, w)); *redundant
	}
	cout << FloydWarshall();
}
