#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector< vector<int> > Graph;

int n, m;

Graph G;

void BFS(bool *exp, int s)
{	
	if (!exp[s])
	{
		queue<int> Q;
		Q.push(s);
		exp[s] = true;
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for (vector<int>::iterator it = G[u].begin();it != G[u].end();it++)
			{
				if(!exp[*it])
				{
					exp[*it] = true;
					Q.push(*it);
				}
			}
	
		}
	}
}

int CC(int n,int ig)
{
	int count = 0;
	
	bool explored[n + 1];
	memset(explored, false, sizeof(explored));

	for (int i = 1;i <= n;i++)
	{
		if (!explored[i] && i != ig)
		{
			BFS(explored, i);
			count++;
		}
	}

	return count;
}

int main(void)
{
	cin >> n >> m;
	G.resize(n + 1);

	int u, v;
	for (int i = 0;i < m;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	set<int> ci;

	for (u = 1;u <= n;u++)
	{
		// remove edge	
		for (vector<int>::iterator i = G[u].begin();i != G[u].end();i++)
			G[*i].erase(find(G[*i].begin(), G[*i].end(), u));

		if (CC(n, u) > 1)
			ci.insert(u); // critical intersection

		// insert edge
		for (vector<int>::iterator i = G[u].begin();i != G[u].end();i++)
			G[*i].push_back(u);
	}

	cout << ci.size() << endl;
	copy(ci.begin(), ci.end(), ostream_iterator<int>(cout, "\n"));
}
