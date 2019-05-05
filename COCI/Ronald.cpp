#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<vector<int> > G;
bool *visit;

void dfs(int s)
{
	visit[s] = true;	
	for (vector<int>::iterator it = G[s].begin();it!=G[s].end();it++)
		if (!visit[*it])
			dfs(*it);
}
int main(void)
{
	int u,v;
	cin >> n >> m;
	visit = new bool[n+1];
	G.resize(n+1);
	for (int i =0;i<m;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cc = 0;
	fill(visit,visit+n, false);
	for (int i = 1;i <= n;i++)
	{
		if (!visit[i])
		{
			dfs(i);
			cc++;
		}
	}
	if (m == 0) cc = 0;
	if (cc <= n/2 - (n%2))
		cout << "DA" << endl;
	else
		cout << "NE" << endl;
	return 0;
}
