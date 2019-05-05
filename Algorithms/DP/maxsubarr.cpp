/* 
	Find maximum subarray(i.e. with max sum) of array
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int A[] = { 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5, 1, 2, -5  };
	int N = sizeof(A) / sizeof(A[0]);

	int dp[N];
	// dp[i] max value from 0 to i
	dp[0] = max(0, A[0]);

	for (int i = 1;i < N;i++)
		dp[i] = max(dp[i - 1] + A[i], 0);

	cout << *max_element(dp, dp + N) << endl;
	return 0;
}
