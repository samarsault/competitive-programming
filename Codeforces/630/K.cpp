/* TLE */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long ans = 1; // include 1

	for (int i = 11;i <= n;i+=2)
		if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
			ans++;

	cout << ans << endl;
	return 0;
}