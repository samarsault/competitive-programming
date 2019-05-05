#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	
	for (int i =0 ;i < n;i++)
		cin >> a[i];

	sort(a, a + n);

	int ans = 0;
	
	for (int i = 0;i < n;i++)
	{
		if (a[i] == a[i - 1] || a[i] == a[i + 1])
		{
			ans++;
			continue;
		}
		
		int l = i - 1;
		int h = i + 1;
		int sum;
		while ((l >= 0) && h < n)
		{
			sum = a[l] + a[h];
			if (sum == 2*a[i])
			{
				ans++;
				break;
			}

			if (sum < 2*a[i])
				h++;
			else
				l--;
		}
	}

	cout << ans << endl;
}
