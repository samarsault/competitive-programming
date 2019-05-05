/*
 * AGGR
 */
#include <iostream>
#include <algorithm>

using namespace std;

int * pos, n, c;

// F(x) = true if it is possible to place cow at a distance of at least x
bool F(int x)
{
	// pos[0..n-1] is sorted
	int cowsplaced = 1, lastpos = pos[0]; // 1 cow placed at pos[i]
	for (int i = 1;i < n;i++)
	{
		if (pos[i] - lastpos >= x)
		{
			cowsplaced++;
			if (cowsplaced == c)
				return true;
			lastpos = pos[i];
		}
	}
	return false;
}
int main()
{
	int t, i;
	cin >> n >> c;
	pos = new int[n];
	for (i = 0;i < n;i++)
		cin >> pos[i];
	
	sort(pos ,pos +n);
	int low = 0, high = pos[n-1]-pos[0] + 1, mid;	
	while (high - low > 1)
	{
		mid = (low+high)/2;
		if (F(mid))
			low = mid;
		else
			high = mid;
	}
	cout << low << endl;
}
