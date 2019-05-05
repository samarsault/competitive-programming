/*
 * SPOJ ALPHACODE
 */
#include <iostream>
#include <algorithm>

#define ochar(c1,c2) ((c1 == '1') || (c1 == '2' && c2 <= '6'))

typedef long long ll;
using namespace std;

int main(int argc, char *argv[])
{
	string s;
	while (true)
	{
		cin >> s;

		if (s == "0") break;

		int n = s.size();
		ll dp[n];
		// int dp[n];
		dp[0] = dp[1] = 1;

		if (ochar(s[0], s[1]) && (s[1] != '0'))
			dp[1]++;

		for (int i = 2;i < n;i++) {
			if (ochar(s[i-1],s[i])) {
				dp[i] = dp[i-2];
				if (s[i] != '0')
					dp[i] += dp[i-1];
			}
			else {
				dp[i] = dp[i-1];
			}
		}
		cout << dp[n-1] << endl;
	}
	return 0;
}
