/*
 * RAILCATER IARCS
 * Dynamic Programming O(n)
 * Optimise memory use of dp array to prevent seg fault
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int n, k, ans = 0;
	cin >> n >> k;
	int a[n];

	for (int i = 0;i < n;i++)
		cin >> a[i];
	
	int sum = 0;
	for (int i = 0;i < k;i++)
		sum += a[i];

	
	//int sumk[n + 1], bestk[n + 1];

	//sumk[k - 1] = sum;
	//bestk[k - 1] = sum;

	ans = sum;

	int prev_sum = sum, prev_best = sum;
	int sumk, bestk;
	for (int j = k;j < n;j++)
	{
		sumk = prev_sum + a[j] - a[j - k];
		bestk = max(prev_best + a[j], sumk);
		ans = max(ans, bestk);
		prev_sum = sumk;
		prev_best = bestk;
	}

	cout << ans << endl;
}
