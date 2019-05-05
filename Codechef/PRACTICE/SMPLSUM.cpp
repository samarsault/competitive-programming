#include <iostream>

using namespace std;

typedef long long LL;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int solve(int N)
{
	LL sum = 0;
	for (int i = 1;i <= N;i++)
	{
		sum += i / gcd(i, N);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int T;
	int N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << solve(N) << endl;
	}

	return 0;
}