/*
 * Matrix Chain Multiplication
 * Dynamic Programming
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
	int n, r, c, k;
	cin >> n;
	// nth matrix has dimensions r[i] * c[i]
	// MMC[i][j] = cost of multiplying Matrices M_i x M_i+1 x ... M_j
	int C[n], R[n], MMC[n][n];

	for (int i = 0;i < n;i++)
		cin >> R[i] >> C[i];

	for (r = 0;r < n;r++)
		MMC[r][r] = 0;

	for (c = 1;c < n;c++)
	{
		for (r = c - 1; r >= 0;r--) // mistake: r = c, thus MMC[r][c] = inf instead of 0
		{
			MMC[r][c] = INT_MAX;
			for (k = r;k < c;k++)
				MMC[r][c] = min(MMC[r][c], MMC[r][k] + MMC[k + 1][c]+ R[r] * C[k] * C[c]);
		}
	}
	cout << MMC[0][n-1]<<endl;
}
