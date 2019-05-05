#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, i, u, v;
	cin >> n;
	int col[n];
	for (i = 0; i < n; ++i) 
		cin >> col[i];

	vector<vector<int> > G (n+1);
	for (i = 1;i < n;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
	}

	bool visited[n+1];
	queue<int> Q;

	for (int s = 1;s <= n;s++)
	{
		Q.push(s);
		while (!Q.empty())
		{
			u = Q.front();
			Q.pop();
			for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
				if (!visited[*it])
				{
					visited[*it] = true;
					Q.push(*it);
				}
			}
			
		}
	}

}
