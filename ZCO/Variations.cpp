#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int i,  n, k, pos, ans = 0;
	cin >> n >> k;
	int a[n];
	for (i = 0;i < n;i++)
		cin >> a[i];
	sort(a, a + n);

	for (i = n - 1;i >= 0;i--)
	{
		pos = distance(a, upper_bound(a, a + n, a[i] - k)); 
		ans += pos;
	}
	cout << ans << endl;
}
