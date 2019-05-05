#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int A[N];
	// B[i] is distance of A[i] from 0
	int B[N];
	// sum[i] = A[0] + A[1] + ... + A[i - 1] + A[i];
	
	int sum[N];
	for (int i = 0;i < N;i++)
	{
		cin >> A[i];
		B[i] = 0 - A[i];

		if (i == 0)
			sum[i] = A[i];
		else
			sum[i] = sum[i - 1] + A[i];
	}


	return 0;
}