#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long T, n, n2, ans;
    cin >> T;
    while(T--)
    {
        cin >> n;
        n2 = (long)log2(n);
        n2 = pow(2, n2);
        if (n==n2)
            ans=n2/2;
        else
            ans=n-n2;
        ans*=2;
        if(n == 1)
            ans = 1;
        cout << ans << endl;
    }
    return 0;
}