#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	long long A[N];
	for (int i = 0;i < N;i++)
		cin >>A[i];

	long long sum = 0;
	for (int i = 0;i < N;i++)
		sum += A[i];

	if (sum % 2 == 1)
	{
		// if sum is odd
		long long min = 0;
		for (int i = 0;i < N;i++)
		{
			if (min == 0 && A[i] % 2 == 1)
				min = A[i];
			else if (A[i] < min && A[i] % 2 == 1)
				min = A[i];
		}

		sum -= min;
	}

	cout << sum << endl;
	return 0;
}