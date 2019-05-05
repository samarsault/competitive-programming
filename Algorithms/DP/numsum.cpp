/*
 *  Given a number N, you've to find the number of 
 *  different ways to write it as the sum of 1, 3 and 4.
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N = 5;
	int dp[N + 1];
	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = 2;

	for (int i = 4;i <= N;i++)
		dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
	
	cout << dp[N] << endl;
	return 0;
}