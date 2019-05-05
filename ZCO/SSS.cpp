/*
 * Save Spaceman Spiff
 * https://www.codechef.com/ZCOPRAC/problems/ZCO13004
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
const int size = 2500 + 1;
int n, m, k;

bool path[size][size];
bool valid[size][size];

bool isValid(double value) 
{
	double intpart;
	return modf(value, &intpart) == 0.0 && value >= 0;
}

int main(int argc, char *argv[])
{
	cin >> n >> m >> k;	
	int x,y,f,s;

	for(int i = 0;i < n;i++)
		for(int j= 0;j < m;j++)
			valid[i][j] = true;

	for (int i = 0;i < k;i++)
	{
		cin >> x >> y >> s >> f;
		x--;
		y--;

		valid[x][y] = false;

		for (int r = 1;r < n+m;r++)
		{
			// solve eqn in n for integral n
			if (isValid(1.0*(x + y - s)/f)) {
				if (x+r<n)
					valid[x + r][y] = false;
				if(y+r<m)
					valid[x][y + r] = false;
			}
			if (isValid( 1.0*(x+y-2*r -s)/f ))
			{
				if (y-r>=0)
					valid[x][y-r] = false;
				if(x-r>=0)
					valid[x-r][y] = false;
			}
		}
	}

	path[0][0] = valid[0][0];

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (i==0 && j==0) continue;

			if (!valid[i][j]) {
				path[i][j] = false;
				continue;
			}

			if (i >= 1 && j >= 1) {
				path[i][j] = path[i-1][j] || path[i][j-1];
			}
			else if (i >= 1) {
				path[i][j] = path[i-1][j];
			}
			else if (j>=1){
				path[i][j] = path[i][j-1];
			}
		}
	}

	if (path[n-1][m-1])
		cout << "YES\n" << (n-1)+(m-1) << endl;
	else
		cout << "NO\n" << endl;
	return 0;
}
