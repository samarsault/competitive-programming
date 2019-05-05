#include <iostream>
#include <cstring>

using namespace std;

string s;
int dp[6100][6100], n;

int bestinsert(int i, int j)
{
	if (i >= j || j >= s.size() || i < 0) return 0;
	if (dp[i][j] == -1) {
		if (s[i] == s[j]) {
			dp[i][j] = bestinsert(i+1,j-1);
		} else {
			dp[i][j] = 1 + min( bestinsert(i + 1, j), bestinsert(i, j - 1));
		}
	}
	return dp[i][j];
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) 
	{
		cin >> s;
		n = s.size();
		memset(dp,-1,sizeof(dp));
		cout << bestinsert( 0, n- 1) << endl;
	}
	return 0;
}
