//
// Bamboo Art using DP
// O(n^2 log n)
// 
#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
#include <iomanip>
#include <cstdio>

using namespace std;

int dp[2500][2500];

int a[2500];
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) 
	cin >> a[i];
	
	//for (int i = 0;i < 2500;i++)
	//for (int j = 0;j < 2500;j++)
	//dp[i][j] = 0;
	
	sort(a, a + n);
	
	int ans = 0;
	
	for (int i = 0;i < n;i++)
	{
		if (a[i]==6)
			cout;

		for (int j = i + 1;j < n;j++)
		{ 
			// a[i] -> second last
			// a[j] -> last
			
			int d = a[j] - a[i];
			int el = a[i] - d;
			int lo = 0, hi = i - 1, mid,t,k=-1;
			while (lo <= hi)
			{
				mid = (lo+hi)/2;
				t = el - a[mid];
				if (t == 0) {
					k = mid;
					break;
				} else if (t < 0) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			if (k >= 0)
				dp[i][j] = 1 + dp[k][i];
			else
				dp[i][j] = 2;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
