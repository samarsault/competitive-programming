#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
 
using namespace std;
bool sameSign(int x, int y)
{
    return (x >= 0) ^ (y < 0);
}
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int a[n];
	int dp[n];
	for(int i = 0 ;i < n;i++){
		cin>>a[i];
		dp[i] = 1;
	}
 
	int ans = 1;
	for (int i = 1;i < n;i++)
	{
		for (int j = i - 1;j >= 0;j--)
		{
			if ( !sameSign(a[i], a[j]) && (abs(a[j]) < abs(a[i])) )
			{
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
 
