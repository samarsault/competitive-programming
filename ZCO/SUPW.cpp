#include <iostream>
#include <algorithm>
#include <climits>

#define MAX 107374182
using namespace std;

int n, * a, ** memo;

int solve(int i, int rest)
{
	if (i >= n)
		return 0;

	if (memo[i][rest] == -1)
	{
		if (rest == 2)
			memo[i][rest] = min(a[i] + solve(i + 1, 2), solve(i + 1, 1));
		else if (rest == 1)
			memo[i][rest] = min(a[i] + solve(i + 1, 2), solve(i + 1, 0));
		else
			memo[i][rest] = a[i] + solve(i + 1, 2);
	}
	return memo[i][rest];
}

int main(int argc, char *argv[])
{
	int i, j;
	cin >> n;
	memo = new int * [n];
	a = new int[n];
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
		memo[i] = new int[3];
	}
	for (i = 0;i < n;i++)
		for (j = 0;j < 3;j++)
			memo[i][j] = -1;

	cout << solve(0, 2) << endl;
	return 0;
}
