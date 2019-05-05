#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, a, b;
	cin >> T;
	int powv;
	while (T--)
	{
		cin >> a >> b;
		if (b == 0)
		{
			cout << 1 << endl;
			continue;
		}
		if (b % 4 == 0)
			powv = (int) pow(a, 4);
		else
			powv = (int) pow(a, (b % 4));

		cout << powv % 10 << endl;
	}
	return 0;
}