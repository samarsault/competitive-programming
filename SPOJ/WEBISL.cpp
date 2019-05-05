#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > graph;

bool *exp;

void DFS(graph G, int u)
{
	exp[u] = true;
	for (vector<int>::iterator v = G[u].begin();v != G[u].end();v++)
		if (!exp[*v])
			DFS(G, *v);
}

void dfsloop(graph G, int n)
{
	int s;
	
	exp = new bool[n + 1];
	fill(exp, exp + n + 1, false);
	
	for (int u = 1;u <= n;u++)
	{
		if (!exp[u])
		{
			s = u;
			DFS(G, u);
		}
	}

}

int SCC(graph G)
{

}

int main(void)
{
	int n, m;
	cin >> n >> m;
}
