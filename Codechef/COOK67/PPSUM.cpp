#include <iostream>
#include <cmath>

using namespace std;

int sum(int d, int n)
{
	int sm = n * (n + 1) / 2;
	if (d > 1)
		return sum(d - 1, sm);
	return sm;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	int D, N;
	while (T--)
	{
		cin >> D >> N;
		cout << sum(D, N) << endl;
	}
	return 0;
}