#include <iostream>
#include <string>

using namespace std;

bool subsetSum(int A[], int N, int S, int i = 0)
{
	if (i == N)
		return (S == 0);
	return (subsetSum(A, N, S, i + 1) || subsetSum(A, N, S - A[i], i + 1));
}

int main(int argc, char const *argv[])
{
	int A[] = { -2, 1, 3, 8 };
	cout << subsetSum(A, 4, 12) << endl;
	return 0;
}