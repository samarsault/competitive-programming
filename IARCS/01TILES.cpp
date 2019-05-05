#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int fib[n];
	
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;
	
	for (int i = 3;i <= n;i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 15746;

	cout << fib[n] << endl;

	return 0;
}
