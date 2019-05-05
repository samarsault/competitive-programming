#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;

	int A[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	sort(A, A + N);

	cout << A[K - 1] << endl;
	return 0;
}