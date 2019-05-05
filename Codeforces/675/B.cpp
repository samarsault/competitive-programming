#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int n, a, b, c, d;

typedef long long LL;

bool legal(int j)
{
	return j >= 1 && j <= n;
}

int main(int argc, char const *argv[])
{
	LL ans = 0;
	cin >> n >> a >> b >> c >> d;

	for (int x = 1;x <= n;x++)
	{
		int y = (x + b) - c;
		int z = (x + a) - d;
		int w = (y + a) - d;

		if (legal(y) && legal(z) && legal(w))
			ans++;
	}
	ans *= n;
	cout << ans << endl;
	return 0;
}