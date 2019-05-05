//
// Fibonacci Sequence
// Dynamic Programming
// Complexity: O(n)
//
#include <iostream>
#include <vector>

using namespace std;

vector<long> dp;

long fib(int n)
{
	for (int i = 2;i <= n;i++)
		dp.push_back(dp[i - 1] + dp[i - 2]);

	return dp[n];
}

int main(int argc, char const *argv[])
{
	dp.push_back(1);
	dp.push_back(1);

	cout << fib(1000) << endl;
	return 0;
}