#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

const int inf = 1e9;
int *Hx, *Hy, *Gx, *Gy, n, m;

inline int dist(int x1, int y1, int x2, int y2)
{
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

inline int D(int i, int j)
{
	return dist(Hx[i], Hy[i], Hx[j], Hy[j]);
}

inline int Dg(int i, int j)
{
	return dist(Gx[i], Gy[i], Gx[j], Gy[j]);
}

inline int Dhg(int i, int j)
{
	return dist(Hx[i], Hy[i], Gx[j], Gy[j]);
}

int main()
{
	int i, j; // iterator for H, G
	cin >> n >> m;
	Hx = new int[n];
	Hy = new int[n];
	Gx = new int[m];
	Gy = new int [m];

	for (i = 0;i < n;i++)cin>>Hx[i] >> Hy[i];
	for (i = 0;i < m;i++)cin>>Gx[i] >> Gy[i];

	int hol[n][m]; // minimum energy to visit nth holestein and mth guerney ending at nth holestein
	int gu[n][m]; // minimum energy to visit nth holestein and mth guerney ending at nth guerney

	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			hol[i][j] = gu[i][j] = inf;
	
	for (i = 0;i < m;i++)
		hol[0][i] = 0;

	for (i = 0;i < m;i++)
		gu[i][0] = 0;

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (i > 0)
				hol[i][j] = min(hol[i - 1][j] + D(i - 1, j), gu[i - 1][j] + Dhg(i, j));

			if (j > 0)
				gu[i][j] = min(gu[i][j - 1] + Dg(j - 1, j), hol[i][j - 1] + Dhg(i, j));
		}
	}

	cout << hol[n - 1][m - 1] << endl;
	return 0;
}
