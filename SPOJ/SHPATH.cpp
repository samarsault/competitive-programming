#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>

#define W(u,v) weight[make_pair(u,v)]
using namespace std;

typedef pair<int,int> pi;

int n;
unordered_map<string, int> names;
unordered_map<pi, int> weight;
vector<vector<int> > G;

int dijkstra(int src, int end)
{
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	int dist[n+1];
	fill(dist, dist + n + 1, INT_MAX);
	dist[src] = 0;
	Q.push(make_pair(0, src));
	while (!Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			int v = *it;
			if (dist[v] > dist[u] + W(u, v))
			{
				dist[v] = dist[u] + W(u, v);
				Q.push(make_pair(dist[v], v));
			}
		}
	}
	if (dist[end] == INT_MAX) return -1;
	return dist[end];
}

void solve()
{

	names.clear();
	weight.clear();

	cin >> n;
	G.resize(n + 1);
	int p, v, w;
	string start, end, name;
	for (int u = 1; u <= n; u++)
	{
		cin >> name >> p;
		names.insert(make_pair(name, u));
		while (p--)
		{
			cin >> v >> w;
			G[u].push_back(v);
			G[v].push_back(u);
			weight[make_pair(u, v)] = weight[make_pair(v, u)] = w;
		}
	}

	int r;
	cin >> r;
	for (int i = 0;i < r;i++)
	{
		cin >> start >> end;
		cout << dijkstra(names[start], names[end]) << endl;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
}
