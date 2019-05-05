/*
 *
 * Prime Generator
 * http://www.spoj.com/problems/PRIME1/
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
	int t;
	cin >> t;
	while (t--)
	{
		long from, to;
		cin >> from >> to;
		for (int i = from;i <= to;i++)
		{
			if (isPrime(i))
				cout << i << endl;
		}
		cout << endl;
	}
	return 0;
}