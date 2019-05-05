#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char *argv[])
{
	int i, j, k, n;
	while (cin >> n)
	{
		cin >> n;
		int col[n];
		for (i = 0;i < n;i++)
			cin >> col[i];

		// dp[i][j] = min smoke from mixing col[i] + col[i+1] + ... + col[j - 1] + col[j]
		// mcol[i][j] = resultant color after mixing col[i] + ... + col[j]
		int dp[n][n], csum[n][n]; 

		for (i = 0;i < n;i++)
			dp[i][i] = 0;

		// csum[i][j] = col[i] + col[i + 1] + ... + col[j - 1] + col[j] % 100
		for (i = 0;i < n;i++)
		{
			csum[i][i] = col[i];
			for (j = i + 1;j < n;j++)	
				csum[i][j] = (csum[i][j - 1] + col[j]) % 100;
		}


		for (j = 1;j < n;j++)
		{
			for (i = j - 1;i >= 0;i--)
			{
				dp[i][j] = INT_MAX;
				for (k = i;k < j;k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + csum[i][k] * csum[k + 1][j]);
			}
		}
		cout << dp[0][n - 1] << endl;
	}
	return 0;
}
