#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int A[N];
	for (int i = 0;i < N;i++)
		cin >> A[i];

	// solve
	sort(A, A + N);

	LL sum = 0, revenue = 0;

	for (int i = 0;i < N - 1;i++)
	{
		sum += A[i];
		revenue += (A[i + 1] * (i + 1) - sum);
	}

	cout << revenue << endl;
	
	return 0;
}