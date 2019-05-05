#include <iostream>

using namespace std;

#define MAX 100005

int pre[MAX + 10];

bool isPal(int S[], int i, int N)
{
	for (int i = 0;i < N / 2;i++)
		if (S[i] != S[N - i - 1])
			return false;

	return true;
}

bool palindrome(int N)
{
	int i = 0;
	int digits[6];

	while (N > 0)
	{
		digits[i] = N % 10;
		N /= 10;
		i++;
	}

	return isPal(digits, 0, i);
}

int main(int argc, char const *argv[])
{
	int T, L, R;
	cin >> T;
	// [i, MAX)
	// precompute values
	for (int i = 1;i < MAX;i++)
	{
		pre[i] = pre[i - 1];
		if (palindrome(i))
			pre[i] += i;
	}

	while (T--)
	{
		cin >> L >> R;
		cout << pre[R] - pre[L - 1] << endl;
	}

	return 0;
}