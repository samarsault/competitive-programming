#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int l_eq(int * a, int low, int high, int target)
{
	int mid;
	while (low < high)
	{
		mid = (low+high+1)/2; // round up
		if (a[mid] <= target)
			low = mid;
		else
			high = mid - 1;
	}
	if (a[low] <= target)
		return low;
	return -1;
}
int main(void)
{
	// Input
	int i, j, n, m, k, x, s;
	cin >> n >> m >> k;
	int a[m+1], b[m+1], c[k+1], d[k+1];
	// c[..] and d[...] sorted
	cin >> x >> s;
	for (i = 1;i <= m;i++)
		cin >> a[i];
	for (i = 1;i <= m;i++)
		cin >> b[i];
	for (i = 1;i <= k;i++)
		cin >> c[i];
	for (i = 1;i <= k;i++)
		cin >> d[i];

	a[0] = x;
	b[0] = 0;
	c[0] = 0;
	d[0] = 0;

	long long ans = 1LL * n * x;
	for (i = 0;i <= m;i++)
	{
		if (b[i] > s)
			continue;
		
		j = (l_eq(d, 0, k, s - b[i]));

		if (j >= 0)
			ans = min(ans, 1LL* a[i] * (n - c[j]));
	}

	cout << ans << endl;
	return 0;
}
