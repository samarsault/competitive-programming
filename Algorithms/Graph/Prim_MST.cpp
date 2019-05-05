#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii, int> edge;

int n, m;
vector<vector<pii> > G;
vector<edge> > E;

// Prim's Minimum Spanning Tree
// V = [1, n] e N
void Prim(int s = 1)
{
	int visited[n];
	int dist_tv[n], nbr_tv[n];
	for (int i = 1;i <= n;i++)
	{
		visited[i] = false;
		nbr_tv[i] = -1;
		dist_tv[i] = INF;
	}

	vector<int> TE;
	visited[s] = false;

	for (vector<vector<pii> >::iterator it = G[s].begin();it != G[s].end();it++)
	{
		nbr_tv[it->first] = 1;
		dist_tv[it->first] = it->second;
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}
