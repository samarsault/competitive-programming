#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// first element less than or equal to val
int lower(int * a, int low, int high, int val)
{
	int mid;
	
	while (low < high)
	{
		mid = (low + high+1)/2;
		if (a[mid] <= val)
			low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int main(void)
{
	int i, n, x, y;

	// Input
	cin >> n >> x >> y;

	int V[x], W[y], start[n], end[n];

	for (i = 0;i < n;i++)
		cin >> start[i] >> end[i];

	for (i = 0;i < x;i++)
		cin >> V[i];

	for (i = 0;i < y;i++)
		cin >> W[i];

	// End Input

	sort(W, W + y);
	sort(V, V + x);

	int ans = INT_MAX ,t1,t2;

	for (i = 0;i < n;i++)
	{
		// find v[i] such that V[i] < start[i]
		t1 = lower(V, 0, x - 1, start[i]);
		if (V[t1] <= start[i])
		{
			t1 = V[t1];
			t2 = *lower_bound(W, W + y, end[i]);
			if (t2 >= end[i])
				ans = min(ans, t2 - t1 + 1);
		}
	}

	/* output */
	cout << ans << endl;
}
