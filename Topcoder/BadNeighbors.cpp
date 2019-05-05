/*
 * TCCC 2004 Round 4
 * Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BadNeighbors
{
public:
	int maxDonations(std::vector<int> a)
	{
		int i, n = a.size(), a1;
		// max earnings from 0..i
		int dp[n];
		dp[0] = a[0];
		dp[1] = max(a[0], a[1]);
		dp[2] = max(dp[0] + a[2], dp[1]);
		
		// in a straight line
		for (i = 3;i < n-1;i++)
			dp[i] = max(a[i] + dp[i - 2], a[i - 1] + dp[i - 3]);
		
		a1 = dp[n-2]; // not including the last element
		
		// don't include the first element
		dp[0] = 0;
		dp[1] = a[1];
		dp[2] = max(a[1], a[2]);

		for (i = 3;i < n;i++)
			dp[i] = max(a[i] + dp[i - 2], a[i - 1] + dp[i - 3]); 

		return max(a1, dp[n-1]);

	}
};

int main(void)
{
	BadNeighbors bn;
	vector<int> v; int n,t;
	cin >> n;
	while (n--)
	{
		cin >> t;
		v.push_back(t);
	}
	cout << bn.maxDonations(v);
	return 0;
}
