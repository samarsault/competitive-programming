/*
 *
 * Prime After N
 * http://www.spoj.com/problems/AU12/
 *
 */
#include <iostream>
#include <cmath>

using namespace std;

// Brute Force
bool isPrime(int n)
{
	if (n < 2)
		return false;

	if (n == 2)
		return true;

	if (n % 2 == 0)
		return false; 
	int m = sqrt(n);

	for (int i = 3;i <= m;i++)
		if (n % i == 0)
			return false;

	return true;
}

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (N = N + 1;!isPrime(N);N++)
			;
		cout << N << endl;
	}
	return 0;
}