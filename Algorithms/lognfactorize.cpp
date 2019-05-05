//
// Complexity: O(log n) roughly
// http://codeforces.com/blog/entry/7262
//
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool prime[1000];
int sp[1000]; // sp[i] = smallest prime factor of i

void sieve(int n)
{
	for (int i = 0;i < n;i++)
		prime[i] = true;

	prime[0] = prime[1] = false;

	for (int i = 2;i <= n;i+=2)
		sp[i] = 2;

	for (int i = 3;i < n;i+=2)
	{
		if (prime[i])
		{
			sp[i] = i;
			for (int p = i * 2;p <= n;p += i) {
				sp[p] = i;
				prime[p] = false;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	sieve(1000);
	cout << "=== Factorizer ===\n";
	int n;
	cout << "Enter number:";
	cin >> n;
	cout << n << " = ";
	while (n != 1) {
		cout << sp[n];
		n /= sp[n];
		if (n != 1)
			cout << " * ";
	}
	cout << endl;
	return 0;
}

