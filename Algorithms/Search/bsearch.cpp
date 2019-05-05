#include <iostream>
#include <cassert>

typedef int BOOL;

int bsearch(int A[], int n, int x)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (A[middle] == x)
			return middle;
		else if (A[middle] < x)
			low = middle + 1;
		else
			high = middle - 1;
	}
	// not found
	return -1;
}


// Recursive
template<typename T>
int binarySearch_r(T key, T A[], int p, int r)
{
	if (p > r)
		return -1;
	int q = (p + r) / 2;
	if (key == A[q])return q;
	if (key < A[q])
		return binarySearch_r(key, A, p, q - 1);
	else
		return binarySearch_r(key, A, q + 1, r);
}

int main(int argc, char const *argv[])
{
	int Odds[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
	int n = sizeof(Odds) / sizeof(int);
	assert(Odds[bsearch(Odds, n, 27)] == 27);
	assert(bsearch(Odds, n, 22) == -1);
	assert(Odds[bsearch(Odds, n, 9)] == 9);
	return 0;
}
