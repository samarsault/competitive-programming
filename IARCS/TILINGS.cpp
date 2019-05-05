/*
 * Number of Tilings (IARCS)
 * Dynamic Programming O(n)
 */

#include <iostream>
#include <algorithm>

#define MAX 10000

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int f[n + 1], g[n + 1];

	// base cases
	g[0] = 0;
	g[1] = 1;

	f[0] = 1;
	f[1] = 1;

	for (int i = 2;i <= n;i++)
	{
		g[i] = (f[i - 1] + g[i - 1]) % MAX;
		f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 2]) % MAX;
	}

	cout << f[n] % 10000 << endl;

	return 0;
}
