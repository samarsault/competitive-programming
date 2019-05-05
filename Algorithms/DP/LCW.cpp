/*
 * Longest Common Subword/Substring
 * Dynamic Programming
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void bruteForce(string s1, string s2)
{
	int m = s1.size(), n = s2.size();
	int mx = 0;

	//for (int k = 1;k <= min(m, n);k++)
	//{
	// find common subword of length k
	for (int i = 0;i < m;i++)
	{
		int len = 0 ;
		for (int j = 0;j < n;j++)
		{
			if (s1[i] == s2[j])
			{
				len++;
				i++;
			}
		}
		mx = max(mx, len);
	}
	//}
	cout << mx << endl;

}

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;

	int m = s1.size(), n = s2.size();
	// LCW[i][j] = longest common substring starting with a[i] and b[j]
	int LCW[m + 1][n + 1];

	for (int i = 0;i <= m;i++)
		LCW[i][n] =  0;

	for (int j = 0;j <= n;j++)
		LCW[m][j] = 0;

	int maxlen = 0;
	for (int j = n - 1;j >= 0;j--)
	{
		for (int i = m - 1;i >= 0;i--)
		{
			if (s1[i] == s2[j])
			{
				LCW[i][j] = 1 + LCW[i + 1][j + 1];
				maxlen = max(LCW[i][j], maxlen);
			}
			else {
				LCW[i][j] = 0;
			}
		}
	}
	cout << maxlen <<endl;
}
