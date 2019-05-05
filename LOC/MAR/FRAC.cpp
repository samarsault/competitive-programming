#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, x;
	cin >> n;

	int a[n];
	double ans = 0;

	for (int i = 0;i < n;i++)
		cin >> a[i];

	for (int i = 0;i < n;i++)
	{
		cin >> x;
		ans = max(ans, double(a[i]) / double(x));
	}

	cout << fixed << setprecision(7) << ans << endl;

	return 0;
}