#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

#define SLEN 500

int primes[SLEN];

// start from 2
void sieve(int n)
{
    memset(primes, true, sizeof(primes));

    for (int p = 2; p * p <= n; p++)
    {
        if (primes[p])
        {
            for (int i = p * 2; i <= n; i += p)
                primes[i] = false;
        }
    }
}

void printfact(vi v)
{
	size_t L = v.size() - 1;
	for (int i = 0;i < L;i++)
		cout << v[i] << " x ";
	cout << v[L] << endl;
}

vi factorize(int n)
{
	vi factors;

	for (int i = 2;i <= n && i < SLEN;i++)
	{
		if (primes[i])
		{
			while (n % i == 0)
			{
				factors.push_back(i);
				n /= i;
			}
		}
	}

	return factors;
}

int main(int argc, char const *argv[])
{
	sieve(SLEN);
	for (int i = 2;i <= 100;i++)
	{
		cout << i << " = ";
		printfact(factorize(i));
	}
	return 0;
}