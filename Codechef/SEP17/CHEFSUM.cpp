#include <iostream>
#include <set>

using namespace std;

typedef long long LL;
const int mx = 1e5 + 2;
int a[mx], n;
LL psum[mx] , ssum[mx]; // psum[i] = a[0] + a[1] + .. + a[i]

int solve()
{
	int i;
	cin >> n;
	set<int> s;
	for (i = 0;i < n;i++)cin >> a[i];
	// calculate prefix sums
	psum[0] = a[0];
	for (i = 1;i < n;i++)
		psum[i] = psum[i - 1] + a[i];
	// calculate suffix sums
	ssum[0] = psum[n - 1];
	for (i = 1;i < n;i++)
		ssum[i] = ssum[i - 1] - a[i - 1];
	// find max sums
	LL minsum = 1e15;
	for (i = 0;i < n;i++) 
		minsum = min(psum[i] + ssum[ i ], minsum);

	for (i = 0;i < n;i++)
		if (psum[i] + ssum[i] == minsum)
			s.insert(i+1);
	return *s.begin();
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	while (t--)
		cout << solve() << endl;
	return 0;
}
