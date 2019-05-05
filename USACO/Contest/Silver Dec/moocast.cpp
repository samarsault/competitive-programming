#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>

#ifdef DEBUG
	#define fin cin
	#define fout cout
#endif

using namespace std;

int *X, *Y, *P, n;
bool *reached;

// Whether Cow at Point i can reach cow at point J
bool reach(int i, int j)
{
	int x1 = X[i], x2 = X[j], y1=Y[i], y2=Y[j], p = P[i];
	return (x2 - x1)*(x2 - x1) + (y2-y1)*(y2-y1) <= p*p;
}

// no. of cows when broadcasted from i
int solve(int i)
{
	int count = 0;
	for (int j = 0;j < n;j++)
	{
		if (reach(i, j) && !reached[j])
		{
			reached[j] = true;
			count += 1 + solve(j);
		}
	}
	return count;
}

int main()
{
	fin >> n;
	X = new int[n];
	Y = new int[n];
	P = new int[n];
	reached = new bool[n];

	for (int i = 0;i < n;i++)
		fin >> X[i] >> Y[i] >> P[i];
	
	int ans = 0;
	for (int i = 0;i < n;i++)
	{
		fill(reached, reached + n, false);
		ans = max(ans, solve(i));
	}
	fout << ans << endl;
	return 0;
}
