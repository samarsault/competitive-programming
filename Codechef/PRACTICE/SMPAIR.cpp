#include <iostream>
#include <algorithm>

int main(int argc, char const *argv[])
{
	using namespace std;

	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		int A[N];

		for (int i = 0;i < N;i++)
			cin >> A[i];

		sort(A, A + N);

		cout << (A[0] + A[1]) << endl; 
	}
	return 0;
}