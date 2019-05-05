/*
 * Codeforces 628 B
 */

#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

inline int toint(char c) {
	return c - '0';
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	string S;
	LL ans = 0;
	cin >> S;
	long l = S.size();

	for (int i = 0;i < l;i++)
	{
		int d = toint(S[i]);
		if (d % 4 == 0)
			ans++;
		if (i > 0)
		{
			int pd = toint(S[i - 1]);
			if ((pd * 10 + d) % 4 == 0)
				ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}