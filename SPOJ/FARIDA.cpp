/*
 * Problem: FARIDA
 */

#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
int main(void)
{
	int t, n, i, j;
	cin >> t;
	for (j = 1;j<=t;j++)
	{
		cin >> n;
		LL a[n], dp[n+2];
		for (i = 0 ;i < n;i++)
			cin >> a[i];
		// dp[i] be max no. of coins 0..i, he collects coin i
		
		// Base Case
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);

		// Inductive Definition
		for (i = 2;i < n;i++)
			dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
		cout << "Case " << j << ": " << dp[n-1] << endl;
	}
}
