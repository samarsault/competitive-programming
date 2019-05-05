/*
 * Complexity: O(n^2)
 * TCCC Semifinals 2003
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ZigZag
{
public:
	int longestZigZag(vector<int> a)
	{
		int i, j, n = a.size(), ans = 1;
		int l[n][2];
		
		for (i = 0;i < n;i++)
			for (j = 0;j <= 1;j++)
				l[i][j] = 1;
		
		for (i = 0 ;i < n;i++)
		{
			for (j = i - 1;j >= 0;j--)
			{
				if (a[i] - a[j] > 0)
					l[i][1] = max(l[i][1], 1 + l[j][0]);
				else if(a[i] - a[j] < 0)
					l[i][0] = max(l[i][0], 1 + l[j][1]);
				ans = max(ans , max(l[i][0], l[i][1]));
			}
		}
		return ans;
	}
};

