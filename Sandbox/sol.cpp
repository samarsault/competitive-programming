#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n,k;
        cin >> n >> k;
        ll sum = 0,ans=0;
        int a[2*n];
        for (int i = 0 ;i < n;i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum > 0) {
            ans = k * sum;
        } else {
            copy(a, a + n, a + n);
            int dp[2*n]; // dp[i] = max subarray ending at i
            for (int i = 0;i < 2*n;i++)
                dp[i] = a[i];
            for (int k = 1;k < 2*n;k++)
            {
                dp[k] = max(dp[k-1] + a[k], a[k]);
                ans = max(ans, (ll)dp[k]);
            }
        }
        cout << ans << endl;
    }
}