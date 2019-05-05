#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n, m, k, i, j;
	cin >> m >> n;
	cin >> n >> k;
	int a[m][n], b[n][k], c[m][k];

	for (i = 0;i < m;i++)
		for (j = 0;j < n;j++)
			cin >> a[i][j];

	for (i = 0;i < n;i++)
		for (j = 0;j < k;j++)
			cin >> b[i][j];

	for (i = 0;i < m;i++)
	{
		for (j = 0;j < k;j++)
		{
			c[i][j] = 0;
			for (int p = 0;p < n;p++)
				c[i][j] += a[i][p] * b[p][j];
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}

}

