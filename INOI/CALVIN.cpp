#include <iostream>
#include <vector>

using namespace std;

const int mxn = 3000;
int n, k, a[mxn];
typedef vector<int> vi;

vi back( mxn , -1);
vi forw( mxn , -1); // max score going from k to i

int main(int argc, char *argv[])
{
	cin >> n >> k;
	int a[n];
	k--;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	back[k] = forw[k] = 0;
	forw[k+1] = a[k+1];
	for (int i = k+2;i < n;i++)
		forw[i] = a[i] + max(forw[i-1] , forw[i-2]);
	back[k-1] = a[k-1];
	for (int i = k - 2;i >= 0;i--)
		back[i] = a[i] + max(back[i+1], back[i+2]);
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		ans = max(ans, forw[i] + back[i]);
	}
	cout << ans << endl;
	return 0;
}
