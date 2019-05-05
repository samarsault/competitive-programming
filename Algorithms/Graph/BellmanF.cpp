#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> pi;

// No. of Vertices, Edges
int n, m;
// Graph
// vector<vector<pi> > G;
// Weight
map<pi, int> weight;
// Edge Set
vector<pi> E;

#define INF 1000000000
#define W(u, v) weight[make_pair(u, v)]

// Checking -ve cycle
// Iterate n times instead of n - 1
// Check if any entry changed during the nth iteration
// If yes, the graph has a negative cycle
void Bellman_Ford(int s)
{
	int dist[n+1];
	
	for (int i = 1;i <= n;i++)
		dist[i] = INF;

	dist[s] = 0;
	
	cout << "Shortest Paths from " << s << endl;
	
	for (int i = 0;i < n - 1;i++)
	{
		for (int p = 0;p < m;p++)
		{
			int j = E[p].first, k = E[p].second;
			dist[k] = min(dist[k], dist[j] + W(j, k));
		}
	}
	
	for (int i = 1;i <= n;i++)
		cout << "To " << i << ": " << dist[i] << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	G.resize(n + 1);
	int u, v, w;
	for(int j = 0;j < m;j++) 
	{
		cin >> u >> v >> w;
		E.push_back(make_pair(u, v));
		//G[u].push_back(make_pair(v, w)); *redundant
		weight[make_pair(u, v)] = w;
	}
	Bellman_Ford(1);
}
