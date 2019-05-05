/* 
 * Problem
 * ---------
 *
 * On a positive integer, you can perform any one of the following 3 steps. 
 * 1.) Subtract 1 from it. ( n = n - 1 )
 * 2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )
 * 3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  ).
 * Find the minimum number of steps that takes n to 1
 *
 */

#include <iostream>

using namespace std;

int minSteps(int n)
{
	int dp[n + 1];
	dp[1] = 0;
	for (int i = 2;i <= n;i++)
	{
		dp[i] = 1 + dp[i - 1];
		if (i % 2 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 2]);
		if (i % 3 == 0)
			dp[i] = min(dp[i], 1 + dp[i / 3]);
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	cout << minSteps(9);
	return 0;
}