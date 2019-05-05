#include <iostream>
using namespace std;

const int size = 1e6+1;
int cnt[size];
int  main(int argc, char *argv[])
{
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i=0;i<n;i++)
		cin>>a[i];

	fill(cnt,cnt+size, 0);
	int ans = 0;

	for (int i = 2;i < n;i++)
	{
		for (int j = 0;j < i-1;j++)
			cnt[ a[i-1] + a[j] ]++;

		for (int k = i + 1;k < n;k++){
			if (t-(a[i]+a[k])>=0)
				ans += cnt[t - (a[i] + a[k])];
		}
	}

	cout << ans << endl;
	return 0;
}
