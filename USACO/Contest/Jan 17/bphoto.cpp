#include <iostream>
#include <fstream>
#include <algorithm>

#define JUDGE
using namespace std;

#ifdef JUDGE
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");
	#define cin fin
	#define cout fout
#endif

int main(void)
{
	int i, j, n, unb=0;
	cin >> n;
	int h[n];
	for (i = 0;i < n;i++)
		cin >> h[i];

	for (i = 0;i < n;i++)
	{
		int l = 0, r = 0;

		for (j = i - 1;j >= 0;j--)
			if (h[j] > h[i])
				l++;
		for (j = i + 1;j < n;j++)
			if (h[j] > h[i])
				r++;

		if (max(l, r) > 2*min(l, r)) unb++;
	}
	cout << unb << endl;
	return 0;
}
