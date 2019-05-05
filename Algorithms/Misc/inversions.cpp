#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mergeinversions(int A[], int p, int q, int r)
{
	int n1 = (q - p) + 1,
		n2 = r - q,
		inversions = 0;
	bool counted = false;
	int L[n1 + 1], R[n2 + 1];

	for (int i = 0;i < n1;i++)
		L[i] = A[p + i];

	for (int i = 0;i < n1;i++)
		R[i] = A[q + i + 1];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0, j = 0;

	for (int k = p;k < r;k++)
	{
		if(!counted && R[j] < L[i])
		{
			inversions = inversions + n1 - i;
			counted = true;
		}
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else 
		{
			A[k] = R[j];
			j++;
			counted = false;
		}
	}

	return inversions;
}

int countinversions(int A[], int p, int r)
{
	int inversions = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		inversions += countinversions(A, p, q);
		inversions += countinversions(A, q + 1, r);
		inversions += mergeinversions(A, p, q, r);
	}
	return inversions;
}

int main(int argc, char const *argv[])
{
	int A[] = {4, 3, 2, 1};
	cout << countinversions(A, 0, sizeof(A) / sizeof(A[0])) << endl;
    return 0;
}