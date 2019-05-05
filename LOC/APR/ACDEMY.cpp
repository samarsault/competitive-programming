#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int solve(int *A, int N, int i = 0, bool origin = false)
{
	if (i <= 2 && origin)
		return 1;

	if (i <= 2)
		return 0;

	if (A[i - 1] + A[i - 2] == A[i])
		return 3 + max(solve(A, N, i - 1, true), solve(A, N, i - 2, true));

	return 0;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int A[N];
		for (int i = 0;i < N;i++)
			cin >> A[i];

		int ans = 0;

		for (int i = 2;i < N;i++)
		{
			while ()
		}

		cout << ans << endl;
	}
	return 0;
}