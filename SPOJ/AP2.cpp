#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
	LL T;
	cin >> T;
	while (T--)
	{
		LL first, last, sum;
		cin >> first >> last >> sum;
		LL n = (2 * sum) / (first + last);
		LL d  = (last - first) /  (n - 5);
		LL a = first - (2 * d);
		cout << n << endl;
		for (LL i = 0;i < n;i++)
			cout << a + (i * d) << ' ';
		cout << endl;
	}
	return 0;
}