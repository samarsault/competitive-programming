#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

char G[100][100];

int main(void)
{
	int i, j, n, m;
	cin >> n >> m;
	
	vector<pair<int,int> > vp;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			cin >> G[i][j];
			if (G[i][j] == 'A')
				vp.push_back(make_pair(i,j));
		}
	}
	
	for (i = 0;i < vp.size();i++)
	{
		search(vp[i]);
	}
}
