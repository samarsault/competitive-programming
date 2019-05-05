#include <iostream>
#include <cstring>

using namespace std;

int *a, n, *best;

int main(void)
{
	cin >> n;
	a = new int[n];
	// best[i] is length of largest subseq including i
	best = new int[n];
	fill(best, best + n, 0);
	
	for (int i = 0;i < n;i++)
		cin >> a[i];

	best[0] = 1;
	int ans = 0;
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < i;j++)
		{
			if (a[i] % a[j] == 0)
			{
				best[i] = max(best[i], best[j] + 1);	
			}
		}
		ans = max(ans, best[i]);
	}
	
	cout << ans << endl;
}
