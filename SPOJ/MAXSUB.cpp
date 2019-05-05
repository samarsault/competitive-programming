#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	// Input
	int T;
	cin >> T;
	while (T--)
	{
		int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
		int N = sizeof(A) / sizeof(A[0]);
	
		int max_ending, max_so_far;
		// Kadane's algorithm
		max_ending = max_so_far = A[0];
		
		for (int i = N;i >= 0;i--)
		{
			max_ending = max(A[i], max_ending + A[i]);
			max_so_far = max(max_so_far, max_ending);
		}
		// Output
		cout << max_so_far << endl;
	}
	return 0;
}