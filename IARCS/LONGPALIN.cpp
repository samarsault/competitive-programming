#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int i, j, n;
	cin >> n;
	string s1, s2;
	cin >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());

	int **LCW;
	LCW = new int*[n+1];
	for (i = 0;i <= n;i++)
		LCW[i] = new int[n+1];

	// Base cases
	for (j = 0;j <= n;j++)
		LCW[n][j] = 0;

	for (j = 0;j <= n;j++)
		LCW[j][n] = 0;

	int ans = 0, p = -1;
	for (i = n - 1;i >= 0;i--)
	{
		for (j = n-1; j >= 0; j--)
		{
			if ( s1[i] == s2[j] )
				LCW[i][j] = 1 + LCW[i + 1][j + 1];
			else
				LCW[i][j] = 0;

			if (LCW[i][j] > ans)
			{
				ans = LCW[i][j];
				p = i;
			}
		}
	}

	if (p >= 0)
	{
		cout << ans << endl;
		for (i = p;i < (p + ans);i++)
			cout << s1[i];
		cout << endl;
	}

	delete [] LCW;

}

