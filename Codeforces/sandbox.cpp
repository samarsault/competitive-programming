#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void)
{
	int i, j, n, m;
	cin >> n >> m;
	int c[m];
	for (i = 0; i < m; ++i)
		cin >> c[i];

	int dp[n+1];
	fill(dp, dp + n + 1, 0);
	
	for (i = 0;i < m;i++)
		dp[c[i]] = 1;

	for (i = 1;i <= n;i++)
		for (j = i - 1;j > 0;j--)
			if (dp[j])
				dp[i]+=dp[j];

	cout << dp[n] << endl;
	return 0;
}
