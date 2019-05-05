#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int i,j,r,c,d;
	cin >> r >> c >> d;
	int G[r+1][c+1];

	for (i = 1;i  < r;i++)
		for (j = 1;j < c;j++)
			cin >> G[i][j];

	// G(i)(j) = # of paths from (0,0) to(i, j)
	for (i = 1;i < r;i++)
	{
		for (j = 1;j < c;j++)
		{
			if (G[i][j])
				G[i][j] = G[i - 1][j] + G[i][j - 1];
		}
	}
	return 0;
}
