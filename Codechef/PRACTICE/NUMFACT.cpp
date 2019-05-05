#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef vector<int> vi;

#define SLEN 1000000

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
#ifdef DEBUG

void printfact(vi v)
{
	size_t L = v.size() - 1;
	for (int i = 0;i < L;i++)
		cout << v[i] << " x ";
	cout << v[L] << endl;
}

#endif

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
	int T;
	cin >> T;
	sieve(SLEN);

	while(T--)
	{
		int N;
		cin >> N;
		int n;
		map<int, int> factors;
		for (int i = 0;i < N;i++) 
		{
			cin >> n;
			for (int i = 2;i <= n && i < SLEN;i++)
			{
				if (primes[i])
				{
					while (n % i == 0)
					{
						if (factors.find(i) != factors.end())
							factors[i]++;
						else
							factors.insert(pair<int, int>(i, 1));
						n /= i;
					}
				}
			}
		}

		map<int, int>::iterator it;
		long ans = 1;
		for (it = factors.begin();it != factors.end();it++)
		{
			ans *= it->second + 1;
		}
		cout << ans << endl;

	}
	return 0;
}