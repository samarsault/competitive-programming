#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long LL;
using namespace std;

// a[i] + a[j] < k
// a[j] < (k - a[i])

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int i, n, k,j;

	// Input
	cin >> n >> k;
	int a[n];
	for (i = 0;i < n;i++)
		cin >> a[i];

	sort(a, a+n);

	int low, high, mid, target;
	LL count=0;
	for (i = 0;i < n;i++)
	{
		low = i+1, high = n - 1;
		target = k - a[i];
		while (low < high) // upper_bound functino
		{
			mid = (low+high+1)/2; // division truncate above
			if(a[mid] < target)
				low = mid;
			else
				high = mid - 1;
		}

		if (a[low] < target)
			count+=(low - (i+1)+1);
	}
	cout << count << endl;
}
