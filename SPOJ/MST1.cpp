#include <iostream>

using namespace std;

const int size = 2 * 1e7;
int dp[size + 1];

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;

	fill(dp, dp + size + 1, -1);
	dp[1] = 0;

	for (int i = 1;i <= T;i++)
	{
		cin >> N;
		for (int i = 2;i <= N;i++)
		{
			dp[i] = 1 + dp[i - 1];
			if (i % 2 == 0)
				dp[i] = min(dp[i], 1 + dp[i / 2]);
			if (i % 3 == 0)
				dp[i] = min(dp[i], 1 + dp[i / 3]);
		}
		cout << "Case " << i << ": " << dp[N] << endl;
	}
	return 0;
}