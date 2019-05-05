#include <iostream>
#include <vector>

using namespace std;

int n, m;
int A[10][10];

int solve()
{
	cin >> n >> m;
	vector<string> V(n);
	for (int i = 0;i < n;i++)
		cin >> V[i];	
	
	int col[m + 1];
	fill(col, col + m + 1, 0);
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (V[i][j] == '1')
				col[j]++;
		}
	}

	int ans = 0;
	
	for (int i = 0;i < m;i++)
		if (col[i] > 1)
			ans++;
	
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
}
