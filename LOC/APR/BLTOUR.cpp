#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<vector<int> > G;
int n, a;
const int MOD = 1e9 + 7;

// start node: a
void dfs(int root)
{
	for (vector<int>::iterator it = G[root].begin();it != G[root].end();it++)
	{
		
	}
}

int main(int argc, char const *argv[])
{
	int t, u, v;
	cin >> t;
	while (t--)
	{
		cin >> n;
		G.resize(n + 1);

		for (int i =  0;i < n;i++)
		{
			cin >> u >> v;	
			G[u].push_back(v);
			G[v].push_back(u);
		}

		cin >> a;

		dfs(a);
	}

	return 0;
}