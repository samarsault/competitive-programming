#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M[10][10], R[10][10], n;

void rotate_col(int c)
{
	int k = 0, first = M[0][c], last = M[n - 1][c];
	if (c > 0)
	{
		for (int r = 1;r < n;r++)
				M[k++][c] = M[r][c];
		M[k++][c] = first;
	}
	else
	{
		c = abs(c);
		k = 1;
		for (int r = 0;r < n;r++)
		{
			M[k++ % n][c] = M[r][c];
		}
	}
}

int main(int argc, char const *argv[])
{
	int i, j;
	cin >> n;
	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++)
			cin >> M[i][j];
	rotate_col(-3);

	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
			cout << M[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
