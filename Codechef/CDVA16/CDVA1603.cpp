#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
int binsearch(T A[], T value, int n)
{
	int low = 0;
	int high = n;
	int q;
	while (low <= high)
	{
		q = (low + high) / 2;
		if (A[q] == value)
			return q;
		else if (A[q] > value)
			high = q - 1;
		else
			low = q + 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	unsigned int T, N, Q;
	cin >> T;
	while (T--)
	{
		cin >> N >> Q;
		double A[N];
		for (int i = 0;i < N;i++)
			cin >> A[i];

		sort(A, A + N);

		while (Q--)
		{
			double query;
			cin >> query;
			int m = binsearch(A, query, N);
			cout << N - m - 1 << endl;
		}
	}
	return 0;
}