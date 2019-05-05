/*
 * Mistake: INT_MIN Rounds up to INT_MAX on addition
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
 
using namespace std;
 
const int size = 501;
const int minx = -2000000000;
int n, m;

int g[size][size];
bool valid[size][size];
int path[size][size];
 
int main(int argc, char *argv[])
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> g[i][j];
 
	int x, y, k;
 
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			path[i][j] = minx;
 
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			valid[i][j] = false;

	for (int p = 0;p < m;p++)
	{
		cin >> x >> y >> k;
 
		x--;
		y--;

		int i2 = k + x, j2 = k + y; // upper limits
		int i3 = x - k, j3 = y - k; // lower limits
 
		if (i3 < 0) i3 = 0;
		if (j3 < 0) j3 = 0;
 
		if (i2 >= n) i2 = n-1;
		if (j2 >= n) j2 = n-1;
 
		for (int i = i3;i <= i2;i++)
		{
			for (int j = j3;j <= j2;j++)
			{
				if (abs(x-i) + abs(y-j) <= k)
					valid[i][j] = true;
			}
		}
	}
 
	// solution
 
	if (valid[0][0]) 
		path[0][0] = g[0][0];

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (!valid[i][j] || ( i == 0 && j == 0) )
				continue;

			if (i >= 1 && j >= 1) {
				path[i][j] = g[i][j] + max(path[i][j-1], path[i-1][j]);
			}
			else if (i == 0) { // first row
				path[i][j] = g[i][j] + path[i][j-1];
			}
			else if (j == 0) {
				path[i][j] = g[i][j] + path[i-1][j];
			}
		}
	}

	if (path[n-1][n-1] >= -1e9)
		cout << "YES\n" << path[n-1][n-1]<<endl;
	else
		cout << "NO\n";
 
	return 0;
}
 
