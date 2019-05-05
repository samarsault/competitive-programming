
#include <cmath>
 
using namespace std;
 
bool isprime(long n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
 	long m = sqrt(n);

	for (long i = 3;i <= m;i+=2)
		if(n % i == 0)
			return false;

	return true;
}
 
// P1 + P2^2 + P3^3 = N
// P3^3 = N - P1  P2^2
// P2^2 = N - P3^3 - P1
// P1 = N - P3^3 - P2^2
int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n && n != 0)
	{
		bool found = false;
		for (int i = 2;i < n;i++)
		{
			if (i * i * i < n && isprime(i))
			{
				for (int k = 2; (k * k) < n;k++)
				{
					int p = n - (i * i * i) - (k * k);
					if (isprime(k) && isprime(p))
					{
						found = true;
						cout << p << " " << k << " " << i << endl;
						goto end;
					}
				}
			}
		}
 
	end:
		if (!found)
			cout << "0 0 0" << endl;
	}
	return 0;
} 