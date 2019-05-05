#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 100000

using namespace std;

int d, n, *a, dmax;

int main(void)
{
	int i, j, n, ans = 1;
	cin >> n;
	a = new int[n];
	for (i = 0;i < n;i++) 
		cin >> a[i];
	sort(a, a + n);

	// L[i] = index of i in a[i]
	int L[MAX], prev, len = 0;
	fill(L, L + MAX, -1);
	for (i = 0;i < n;i++)
		L[a[i]] = i;
	
	// dp[i][j] = longest arithmetic sequence with last element a[j] and second last element a[i]
	// so d = a[j] - a[i]
	for (i = 0;i < n;i++)
	{
		for (j = i + 1;j < n;j++)
		{
			len = 1;
			prev = a[j] - (a[j] - a[i]);
			while (prev >= 0 && L[prev] != -1) 
			{
				len++;
				prev -= (a[j] - a[i]);
			}
			ans = max(ans, len);
		}
	}
	cout << ans << endl;
	delete [] a;
}
