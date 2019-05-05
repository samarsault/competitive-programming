#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Gauss' formula
int gsum(int n)
{
	return n * (n + 1) / 2;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string S;
	int ans = 0;
	int rCount = 0, cCount = 0;
	vector<string> grid;

	// columns
	for (int i = 0;i < n;i++)
	{
		cCount = 0;
		cin >> S;
		grid.push_back(S);

		for (int k = 0;k < n;k++)
		{
			if (S[k] == 'C')
			{
				cCount++;
			}
		}

		ans += gsum(cCount - 1);
	}

	// rows
	for (int i = 0;i < n;i++)
	{
		rCount = 0;

		for (int k = 0;k < n;k++)
		{
			if(grid[k][i] == 'C')
			{
				rCount++;
			}
		}

		ans += gsum(rCount - 1);
	}

	cout << ans << endl;
	return 0;
}