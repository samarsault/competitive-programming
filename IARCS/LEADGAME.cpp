/*
 * Points: 40/100
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a, b, mx = 0, ml = 0;
	int pa = 0, pb = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> a >> b;
		pa += a;
		pb += b;
		if (abs(pa - pb) > mx)
		{
			mx = abs(pa - pb);
			if (pa > pb)
				ml = 1;
			else
				ml = 2;
		}
	}

	cout << ml << ' ' << mx << endl;

	return 0;
}
