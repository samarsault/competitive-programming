#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n, * fee, **best, m = 3;
 
int solve(int i, int left)
{
	if (i >= n)
		return 0;
 
	if (best[i][left] == -1)
	{
		if (left == 2)
			best[i][left] = max(fee[i] + solve(i + 1, 1), solve(i + 1, 2));
		else 
			best[i][left] = max(fee[i] + solve(i + 2, 2), solve(i + 1, 2));
	}
	return best[i][left];
}
int main(int argc, char *argv[])
{
	int i, j;
	cin >> n;
 
	fee = new int[n];
	best = new int*[n];	
 
	for (i = 0;i < n;i++)
		cin >> fee[i];
	for (i = 0;i < n;i++)
		best[i] = new int[3];
 
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			best[i][j] = -1;
	cout << solve(0, 2) << endl;;
	return 0;
}
 
