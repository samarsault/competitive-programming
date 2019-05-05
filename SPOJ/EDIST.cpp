#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <cstring>

using namespace std;

int dp[2001][2001];

int min(int a, int b, int c)
{
    return min(min(a, b), c);
}

int ldist(string str1, int m, string str2, int n)
{
    for (int i=0; i <= m; i++)
    {
        for (int j=0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;              

            else if (j == 0)
                dp[i][j] = i; 

            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];            
            
            else
                dp[i][j] = 1 + min(dp[i][j-1],  
                                   dp[i-1][j],  
                                   dp[i-1][j-1]); 
        }
    }
 
    return dp[m][n];
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		string A, B;
		cin >> A >> B;
		cout << ldist(A, A.size(), B, B.size()) << endl;
	}
	return 0;
}
