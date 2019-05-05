//
// ZCO - Break Up
// https://www.codechef.com/ZCOPRAC/problems/ZCO15001
// Complexity: O(n^3)
//

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

const int size = 301;
int n;
int a[size];
bool palin[size][size];
int dp[size]; // dp[i] -> min splits from i..n

int solve(int i)
{
	if (i >= n)
		return 0;

	if (dp[i] != -1) 
		return dp[i];

	int ans = INT_MAX;

	for (int k = i;k < n;k++) 
		if (palin[i][k])
			ans = min(ans, 1 + solve(k + 1));

	dp[i] = ans;
	return ans;
}

int main(int argc, char *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	
	for (int i = 0;i < n;i++)
		dp[i] = -1;

	// calculate palindromic substrings
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			palin[i][j] = true;
			for (int p = i, q = j;p <= q;p++,q--) {
				if (a[p] != a[q]) {
					palin[i][j] = false;
					break;
				}
			}
		}
	}

	cout << solve(0) << endl;
	return 0;
}
