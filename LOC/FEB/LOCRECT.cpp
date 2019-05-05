#include <iostream>
#include <cmath>

using namespace std;

long solvemin(long bl, long bw, long l2, long w2)
{
	if (l2 > bl && w2 < bw)
		return (bl * bw) + ((l2 - bl) * w2);
	else if (l2 < bl && w2 > bw)
		return (bl * bw) + ((w2 - bw) * l2);
	else
		return bl * bw;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	long T, l1, w1, l2, w2;
	cin >> T;
	
	while (T--)
	{
		cin >> l1 >> w1 >> l2 >> w2;
		long ar1 = l1 * w1, ar2 = l2 * w2;
		// max score is sum of areas as she can draw them separately (l & b < 5000)
		long mx = ar1 + ar2;
		long mn = ar1;

		if (ar1 > ar2)
		{
			mn = solvemin(l1, w1, l2, w2);
		}
		else
		{
			mn = solvemin(l2, w2, l1, w1);
		}

		cout << mn << " " << mx << endl;
	}
	return 0;
}