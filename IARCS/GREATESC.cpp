#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

int main(void)
{
	int n, m, u;

	cin >> n >> m;
	int x, y, s, t;

	// Graph
	vector< vector<int> > G (n + 2);

	for (int i = 0;i < m;i++)
	{
		cin >> x >> y;

		// undirected graph
		G[x].push_back(y);
		G[y].push_back(x);
	}

	// start - s
	// end - t
	cin >> s >> t;

	if (s > 0 && t > 0 && s <= n && t <= n)
	{
		// explored vertices
		bool exp[n + 2];
		// distances
		int dist[n + 2];

		memset(dist, -1, sizeof(dist));
		memset(exp, false, sizeof(exp));

		queue<int> Q;

		exp[s] = true;
		dist[s] = 0;

		Q.push(s);

		vector<int>::iterator w;

		while (!Q.empty())
		{
			u = Q.front();
			Q.pop();

			for (w = G[u].begin();w != G[u].end();w++)
			{
				if (!exp[*w])
				{
					exp[*w] = true;
					Q.push(*w);
					dist[*w] = dist[u] + 1;
				}
			}
		}

		if (dist[t] == -1)
			cout << (0) << endl;
		else
			cout << dist[t] << endl;

	}
	else {
		cout << (0) << endl;
	}
}
