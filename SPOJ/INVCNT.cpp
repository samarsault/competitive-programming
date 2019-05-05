#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef long long LL;

LL countsplit(int A[], int p, int q, int r)
{
	LL inversions = 0;
	size_t n1 = (q - p) + 1;
	size_t n2 = (r - q);
	int L[n1 + 1], R[n2 + 1];

	// Copy arrays
	for (int i = 0;i < n1;i++)
	    L[i] = A[p + i];

	for (int j = 0;j < n2;j++)
	    R[j] = A[q + j + 1];

	// Sentinel
	L[n1] = R[n2] = std::max(L[n1 - 1], R[n2 - 1]) + 1;

	int i = 0, j = 0;

	// Merge Left and Right
	for (int k = p;k <= r;k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}

		else 
		{
			A[k] = R[j];
			inversions += (n1 - i);
			j++;
		}
	}

    return inversions;
}

LL count_inversions(int A[], int p, int r)
{
	LL inversion = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		inversion += count_inversions(A, p, q);
		inversion += count_inversions(A, q + 1, r);
		inversion += countsplit(A, p, q, r);
	}
	return inversion;
}

int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int A[n];
		for (int i = 0;i < n;i++)
			cin >> A[i];
		cout << count_inversions(A, 0, n - 1) << endl;
	}
	return 0;
}