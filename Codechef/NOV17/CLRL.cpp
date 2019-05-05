#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	int t,n,r;
	cin >> t;
	while (t--)
	{
		cin >> n >> r;
		int a[n];
		for (int i = 0;i < n;i++)
			cin >> a[i];
		int lo = 0, hi = 1e9;
		bool ans = true;
		for (int i = 0 ;i < n-1;i++)
		{
			if (a[i] > r) {
				if (a[i] > hi) {
					ans = false;
					break;
				}
				hi = a[i];
			}
			else {
				if (a[i] < lo)
				{
					ans = false;
					break;
				}
				lo = a[i];
			}
		}
		if(a[n-1]!=r)ans=false;
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
