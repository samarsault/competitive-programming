#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int M[N], F[N];

		for (int i = 0;i < N;i++)
			cin >> M[i];

		for (int i = 0;i < N;i++)
			cin >> F[i];

		sort(M, M + N);
		sort(F, F + N);

		long sum = 0;
		for (int i = 0;i < N;i++)
			sum += M[i] * F[i];
		cout << sum << endl;
	}
	return 0;
}