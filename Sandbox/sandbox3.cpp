#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = { 3, -2, -1, 2, 2 };
	int n = sizeof(a)/sizeof(int);
	int ans = INT_MIN;
	for (int start = 0; start < n; ++start)
	{
		int sum = 0;
		for (int size = 1; size <= n; ++size)
		{
			if ((start + size) > n)
				break;
			sum += a[start + size - 1];
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}