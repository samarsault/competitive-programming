#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int i, n, m;
	cin >> n >> m;
	int a[n];
	for (i = 0 ;i < n;i++)
		cin >> a[i];

	int sum[n], ans; // sum[i] = max sum ending at i
	sum[0] = (a[0] <= m) ? a[0] : INT_MIN;
	ans = a[0];
	for (int i = 1;i <= n;i++)
	{
		sum[i] = max(a[i], a[i] + sum[i - 1]);
		if (sum[i] > ans && sum[i] <= m)
			ans = sum[i];
	}
	cout << ans << endl;

	return 0;
}
