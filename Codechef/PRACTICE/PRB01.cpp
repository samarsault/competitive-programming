#include <iostream>
#include <cmath>

bool isPrime(int n)
{
	if (n == 2)
		return true;

	if (n < 2 || n % 2 == 0)
		return false;

	int m = sqrt(n);
	for (int i = 3;i <= m;i+=2)
		if (n % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	using namespace std;

	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		if (isPrime(N))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}