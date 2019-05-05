#include <iostream>

// fibonacci in O(n)
int fib(int n)
{
	int fib[n + 1];
	fib[0] = fib[1] = 1;
	for (int i = 2;i < n;i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	return fib[n - 1];
}
int main(int argc, char const *argv[])
{
	using namespace std;
	cout << fib(10) << endl;
	return 0;
}