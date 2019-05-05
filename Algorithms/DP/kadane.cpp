/*
	Kadane's Algorithm for finding the maximum subarray
	https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane.27s_algorithm
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	// Input
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int N = sizeof(A) / sizeof(A[0]);

	// Kadane's algorithm
	int max_ending = 0, max_so_far = 0;
	for (int i = 0;i < N;i++)
	{
		max_ending = max(0, max_ending + A[i]);
		max_so_far = max(max_so_far, max_ending);
	}
	// Output
	cout << max_so_far << endl;
	return 0;
}