/*
 * Discrete Binary Search
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int i, j, n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n][n];
		for (i = 0;i < n;i++)
			for (j = 0;j <= i;j++)
				cin >> a[i][j];

		int sum[n+1][n+1];
		for (i = 0;i <= n;i++)
			for (j= 0;j<=n;j++)
				sum[i][j] = 0;

		for (i = 0;i < n;i++) {
			sum[n - 1][i] = a[n - 1][i];
		}

		for (i = n - 2;i >= 0;i--)
			for (j = 0;j <= i;j++)
				sum[i][j] = a[i][j] + max(sum[i+1][j], sum[i+1][j+1]);

		cout << sum[0][0] << endl;
	}
}

