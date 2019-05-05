//
// Common Elements
//
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
	int m,n;
	cin >> m >> n;
	int a[m], b[n];
	for (int i = 0;i < m;i++) cin >> a[i];
	for (int i = 0;i < n;i++) cin >> b[i];

	sort(a,a+m);
	sort(b, b+n);
	int i = m - 1, j = n - 1,ans=0;	
	while(i >= 0 && j >= 0)
	{
		if (a[i] > b[j]) i--;
		else if(a[i] < b[j]) j--;
		else {
			ans++;
			i--;j--;
		}
	}
	cout << ans << endl;
	return 0;
}
