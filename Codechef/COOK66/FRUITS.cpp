#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	int T, N, M, K;
	cin >> T;

	while (T--)
	{
		cin >> N >> M >> K;
		int n = max(N, M) - min(N, M) - K;
		if (n < 0)
			cout << 0 << endl;
		else
			cout << n << endl;
	}
	return 0;
}