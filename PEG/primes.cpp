#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static bool primes[100000000];

void sieve(int n)
{
	for (int i = 2;i <= sqrt(n);i++)
	{
		if (primes[i])
		{
			for (int p = i * 2;p <= n;p += i)
				primes[p] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	int M, N;
	cin >> N >> M;
	//primes.resize(M+1);
	for (int i = 0;i <=M;i++) 
		primes[i] = true;
	
	primes[1] = primes[0] = false;

	sieve(M);
	
	for (int i = N;i <= M;i++)
		if (primes[i])
			cout << i << endl;
	return 0;
}

