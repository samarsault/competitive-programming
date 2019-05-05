#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>

using namespace std;

int *X, *Y, n;
bool *reached;

vector<vector<int> > G;

// Whether Cow at Point i can reach cow at point j
bool reach(int i, int j, double p)
{
	int x1 = X[i], x2 = X[j], y1=Y[i], y2=Y[j];
	return (x2 - x1)*(x2 - x1) + (y2-y1)*(y2-y1) <= p;
}

// no. of cows when broadcasted from i with radius r
int solve(int i, double r)
{
	int count = 0;
	for (int j = 0;j < n;j++)
	{
		if (reach(i, j, r) && !reached[j])
		{
			reached[j] = true;
			count += 1 + solve(j, r);
		}
	}
	return count;
}

int main()
{
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	fin >> n;

	X = new int[n];
	Y = new int[n];
	reached = new bool[n];

	for (int i = 0;i < n;i++)
		fin >> X[i] >> Y[i]; 

	long long lo = 0, hi = 2 * 25000 * 25000, r, k;
	while (lo < hi)
	{
		fill(reached, reached + n, false);
		
		r = lo + (hi - lo)/2;
		k = (solve(0, r)); // MISTAKE: double precision

		if (k < n)
			lo = r + 1;
		else
			hi = r;
	}

	fout << lo << endl;
	return 0;
}
