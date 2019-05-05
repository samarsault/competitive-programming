#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int,int> pi;

int n;
unordered_map<string, int> names;
vector<vector<pi> > G;

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

		if (u == end) break;

		for (vector<pi>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			int v = it->first, cost = it->second;
			if (dist[v] > dist[u] + cost)
			{
				dist[v] = dist[u] + cost;
				Q.push(make_pair(dist[v], v));
			}
		}
	}

	return dist[end];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		names.clear();
		cin >> n;
		G.clear();
		G.resize(n + 1); // MISTAKE: resize may not always clear
		int p, v, w;
		string start, end, name;
		for (int u = 1; u <= n; u++)
		{
			cin >> name >> p;
			names.insert(make_pair(name, u));
			while (p--)
			{
				cin >> v >> w;
				G[u].push_back(make_pair(v, w));
			}
		}

		int r;
		cin >> r;
		for (int i = 0;i < r;i++)
		{
			cin >> start >> end;
			cout << dijkstra(names.at(start), names.at(end)) << endl;
		}
	}
}
