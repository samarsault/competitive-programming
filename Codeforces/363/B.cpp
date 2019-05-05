#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;

	int A[N];
	long pre[N + 2], t; // prefix array
	
	// pre[i] is the sum of 1 to i + k;

	for(int i = 0 ;i < N;i++)
		cin >> A[i];

	pre[0] = A[0];

	for (int i = 1;i < N;i++)
		pre[i] = pre[i - 1] + A[i];

	int jm = pre[K - 1], ji = 0;

	for (int i = 1;i <= N - K;i++)
	{
		t= pre[i + K - 1] - pre[i - 1];
		if (t < jm)
		{
			jm = t;
			ji = i;
		}
	}
	// 1-indexed
	cout << ji + 1 << endl;
	return 0;
}