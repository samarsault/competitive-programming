/*
 * TODO: detect cycles
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > G (n + 1);

	int x, y;

	for (int i = 0;i < m;i++)
	{
		cin >> x >> y;
		G[x].push_back(y);	
		G[y].push_back(x);
	}

	// bool cycle = false;

	bool exp[n + 1];
	memset(exp, false, sizeof(exp));
	// no. of connected components
	int conn = 0;
	
	queue<int> Q;

	for (int i = 1;i <= n;i++)
	{
		if (!exp[i])
		{
			Q.push(i);
			exp[i] = true;
			
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop();
				
				for (vector<int>::iterator v = G[u].begin();v != G[u].end();v++)
				{
					if (!exp[*v])
					{
						Q.push(*v);
						exp[*v] = true;
					}
				}
			}
			conn++;
		}
	}

	if (conn == 1 && m==n-1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}
