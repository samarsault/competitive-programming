#include <iostream>

using namespace std;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size(), n = s2.size();

	int LCS[m + 1][n + 1], c, r;

	for (c = 0;c <= n;c++)
		LCS[m][c] = 0;

	for (r = 0;r <= m;r++)
		LCS[r][n] = 0;

	for (c = n - 1 ; c >= 0;c--)
	{
		for (r = m - 1; r >= 0;r--)
		{
			if (s1[r] == s2[c])
				LCS[r][c] = 1 + LCS[r + 1][c + 1];
			else 
				LCS[r][c] = max(LCS[r + 1][c], LCS[r][c + 1]);
		}
	}
	
	cout << LCS[0][0] << endl;
}
