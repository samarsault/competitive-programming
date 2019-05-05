#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solve(string s, int** dp, int i, int j) 
{
	if (i==j) return 0;
	if (dp[i][j] >= 0 )
		return dp[i][j];
	if (s[i] == s[j])
		dp[i][j] = solve(s, dp, i + 1, j + 1);
	else
		dp[i][j] = min(1 + solve(s, dp, i, j - 1), 1 + solve(s, dp, i + 1, j));

	return dp[i][j];
}
int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		int n = a.size();
		int **dp = new int*[n];
		for (int i = 0;i < n;i++)
			dp[i] = new int [n];

		for(int i =0;i<n;i++)
			for (int j =0;j<n;j++)
				dp[i][j] = -1;

		cout << solve(a, dp, 0, n - 1);
	}
	return 0;
}
