/*
 * FCTRL
 *
 * https://www.codechef.com/problems/FCTRL
 * http://www.spoj.com/problems/FCTRL/
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	
	int T;
	long n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		int fives = 0;

		// below also works
		// while (n > 0)
		// {
		// 	fives += n / 5;
		// 	n /= 5;
		// }
		for (int i = 5; (n / i) >= 1;i *= 5)
			fives += n / i;

		cout << fives << endl;
	}
	return 0;
}