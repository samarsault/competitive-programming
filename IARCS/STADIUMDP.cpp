/*
 * Siruseri Sports Stadium (Event Scheduling)
 * IARCS Sept 2004
 * Dynamic Programming O(n^2) Solution
 *
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// sort according to ending times
bool cmp(pair<int, int> pa, pair<int, int> pb)
{
	return pa.second < pb.second;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n;

	vector<pair<int, int> > M;

	for (int i = 0;i < n;i++)
	{
		// a - start, b - length
		cin >> a >> b;
		// M[i] = (start, end)
		M.push_back(make_pair(a, a + b));
	}

	// sort according to ending times
	sort(M.begin(), M.end(), cmp);

	// dp[i] is length of longest schedule who's last event is i
	int dp[n];

	fill(dp, dp + n, 0);

	// base case
	dp[0] = 1;

	int ans = 0;

	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < i;j++)
			if (M[j].second < M[i].first)
				dp[i] = max(dp[i], dp[j] + 1);

		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}

