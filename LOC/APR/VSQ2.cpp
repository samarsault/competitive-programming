#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;

LL dang(LL N)
{
	// ALITER: Array dp[1..N]
	LL a = 0, b = 1, tmp;
	for (LL i = 2;i <= N;i++)
	{
		tmp = a;
		a = ((i - 1) * (a + b)) % MOD;
		b = tmp;
	}
	return a;
}
int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << dang(N) << endl;
	}
	return 0;
}