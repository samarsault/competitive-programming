#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int m = s1.size(), n = s2.size(), r, c, ans = 0;

	int LCW[m + 1][n + 1];

	for (r = 0;r <= m;r++)
		LCW[r][n] = 0;

	for (c = 0;c <= n;c++)
		LCW[m][c] = 0;

	for (r = m - 1;r >= 0;r--)
	{
		for (c = n - 1;c >= 0;c--)
		{
			if (s1[r] == s2[c]) 
				LCW[r][c] = 1 + LCW[r + 1][c + 1];	
			else
				LCW[r][c] = 0;
			ans = max(LCW[r][c], ans);
		}
	}
	
	cout << ans << endl;
}
