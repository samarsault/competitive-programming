#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, M, N;
	cin >> T;

	while (T--)
	{
		cin >> N >> M;
		if (N == M)
		{
			cout << "No Winner" << endl;
			continue;
		}

		int q = max(N, M);
		if (q == N)
		{
			cout << "Bipin" << " ";
		}
		else
		{
			cout << "Balaji" << " ";
		}

		cout << abs(M - N) << endl;
	}
	return 0;
}