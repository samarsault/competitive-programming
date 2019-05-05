#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
#include <climits>
#include <fstream>
#include <queue>

#define M make_pair

using namespace std;

//ifstream fin("lasers.in");
//ofstream fout("lasers.out");

//#define cin fin
//#define cout fout

typedef pair<int,int> pii;
const int inf = 1e9;

int main(int argc, char *argv[])
{
	int n, barnX, barnY, lX, lY, i;
	cin >> n >> barnX >> barnY >> lX >> lY;

	// (X[0], Y[0]) = (lX, lY) i.e. laser source coordinates
	// (X[n+1], Y[n+1]) = (barnX, barnY)
	int X[n+2], Y[n+2];

	unordered_map<int, vector<int> > mpX, mpY;

	mpX[lX].push_back(0);
	mpY[lY].push_back(0);

	for (int i = 1;i <= n;i++) 
	{
		cin >> X[i] >> Y[i];
		mpX[X[i]].push_back(i);
		mpY[Y[i]].push_back(i);
	}

	mpX[barnX].push_back(n+1);
	mpY[barnY].push_back(n+1);

	// (lX, lY) to (barnX, barnY) 
	priority_queue<pii, vector<pii>, greater<pii> > Q;

	// nodes[i] = no. of nodes in the path
	int dist[n+2], nodes[n+2];

	fill(dist, dist + n + 2, inf);
	fill(nodes, nodes + n + 2, 0);

	dist[0] = 0;

	Q.push(M(0, 0));

	while (!Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		if (mpX[X[u]].size() > 1) 
		{
			for (typeof(mpX[X[u]].begin()) it = mpX[X[u]].begin();it!=mpX[X[u]].end();it++)
			{
				if (*it==u)continue;
				if (dist[*it] > dist[u] + abs(X[*it] - X[u]))
				{
					dist[*it] = abs(X[*it] - X[u]);
					Q.push(M(abs(X[*it] - X[u]), *it));
					nodes[*it] = nodes[u] + 1;
				}
			}
		}
		else if(mpY[Y[u]].size() > 1)
		{
			for (typeof(mpY[Y[u]].begin()) it = mpY[Y[u]].begin();it!=mpY[Y[u]].end();it++)
			{
				if (*it==u)continue;
				if (dist[*it] > dist[u] + abs(Y[*it] - Y[u]))
				{
					dist[*it] = abs(Y[*it] - Y[u]);
					Q.push(M(abs(Y[*it] - Y[u]), *it));
					nodes[*it] = nodes[u] + 1;
				}
			}

		}
	}
	cout << nodes[n+1] - 1 << endl;
	return 0;
}
