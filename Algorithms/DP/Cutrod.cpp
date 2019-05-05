/*
 * Rod Cutting Problem
 * Dynamic Programming
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	// extend to n - 1 so answer comes more naturally
	int p[n+1], r[n+1], q;
	for (int i  = 1;i <= n;i++)
		cin >> p[i];

	r[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		// revenue from cutting a rod of length i
		r[i] = INT_MIN;
		for (int j = 1;j <= i;j++)
			r[i] = max(r[i], p[j] + r[i - j]);
	}
	cout << r[n] << endl;
}
