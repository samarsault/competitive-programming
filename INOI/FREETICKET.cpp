#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

#define INF 1000000000 
#define P(x,y) make_pair(x,y)

int c, f;
vector<vector<pii> > G;
int *dist;

void dijkstra(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	int u, v, w;
	dist = new int[c+1];
	fill(dist, dist + c + 1, INF);
	dist[s] = 0;
	Q.push(P(0, s));
	
	while(!Q.empty())
	{
		u =	Q.top().second;
		Q.pop();
		for (vector<pii>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			v = it->first;
			w = it->second;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				Q.push(P(dist[v], v));
			}
		}
	}
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	
	cin >> c >> f;
	G.resize(c+1);
	int u, v, w;
	for (int i = 0;i < f;i++)
	{
		cin >> u >> v >> w;
		G[u].push_back(P(v, w));
		G[v].push_back(P(u, w));
	}
	int ans = 0;
	for (u = 1;u <= c;u++)
	{
		dijkstra(u);
		for (int v = u + 1;v <= c;v++)
			ans = max(ans, dist[v]);
	}
	cout << ans << endl;
	return 0;
}
