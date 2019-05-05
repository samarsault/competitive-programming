#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

// a[i] <= val
int less_eq(int * a, int n, int val)
{
	int low = 0, high = n - 1, mid;
	while (low < high)
	{
		mid = (low + high + 1)/2;
		if (a[mid] <= val)
			 low = mid;
		else
			high = mid - 1;
	}
	return low;
}

int main(int argc, char *argv[])
{
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");

	int i, j, l, r, n, q;
	fin >> n >> q;
	int a[n];
	for (i = 0; i < n; ++i) {
		fin >> a[i];
	}

	sort(a, a+n);

	while (q--)
	{
		fin >> l >> r;
		i = distance(a, lower_bound(a, a + n, l));
		j = less_eq(a, n, r);
		fout << j - i + 1 << endl;
	}
	
	return 0;
}
