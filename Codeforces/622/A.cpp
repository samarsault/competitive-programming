#include <iostream>

int main(int argc, char const *argv[])
{
	using namespace std;
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;

	for (long i = 1;i <= n;i++)
	{
		n -= i;
		if (n < 0)
		{
			n += i;
			break;
		}
	}

	cout << n << endl;
	return 0;
}