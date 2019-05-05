#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

map<LL, LL> H;

LL solve(LL n)
{
	if (n == 0)
		return 0;
	if (H[n] == 0)
		H[n] = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
	return H[n];
}

int main(int argc, char const *argv[])
{
	LL n;
	while (cin >> n) cout << solve(n) << endl;
	return 0;
}