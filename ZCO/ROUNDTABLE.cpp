#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int size = 1e6 + 1;
int n;
int c[size];

int main(int argc, char *argv[])
{
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> c[i];
	if (n == 1) {
		cout << c[0] << endl;
		return 0;
	}
	int dp[n]; // dp[i] -> min cost from 0..i when ith king get's the dessert
	dp[0] = c[0];
	dp[1] = c[1];
	for (int i = 2;i < n;i++) 
		dp[i] = c[i] + min(dp[i-1], dp[i-2]);
	int a1 = dp[n-1];
	reverse(c, c + n);
	dp[0] = c[0];
	dp[1] = c[1];
	for (int i = 2;i < n;i++) 
		dp[i] = c[i] + min(dp[i-1], dp[i-2]);
	cout << min(a1, dp[n-1]) << endl;
	return 0;
}
