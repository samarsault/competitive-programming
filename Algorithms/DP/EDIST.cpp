/*
 * Edit Distance
 * Dynamic Programming
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.size(), n = s2.size();

	// ED[i][j] = minimum edit distance of string starting at (i, j)
	int ED[m][n];

	for (int  r = 0;r <= m;r++)
		ED[r][n + 1] = m - r + 1;
}
