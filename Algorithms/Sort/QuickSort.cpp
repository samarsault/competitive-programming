#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

// partition with extra space O(n)
int partition_arr(int *A, int m,  int n)
{
	int p = m; // first element as pivot
	int length = n - m + 1;
	int B[length];

	int start = 0, end = length - 1;
	for (int i = m;i <= n;i++)
	{
		if (i == p)
			continue;

		if (A[i] < A[p])
		{
			B[start] = A[i];
			start++;
		}
		else
		{
			B[end] = A[i];
			end--;
		}
	}
	B[start] = A[p];
	for (int i = 0;i < length;i++)
		A[m + i] = B[i];
	return start;
}

// In place partition
int partition_ip(int *A, int m, int n)
{
	// pivot = A[m] i.e. first element
	int p = m;
	int i = m + 1;
	for (int j = i;j <= n;j++)
	{
		if (A[j] < A[p])
		{
			swap(A[j], A[i]);
			i++;
		}
	}

	swap(A[m], A[i - 1]);

	return i - 1;
}

void quicksort(int a[], int m, int n)
{
	if (m >= n)
		return;

	int p = partition_ip(a, m, n);
	quicksort(a, m, p);
	quicksort(a, p + 1, n);
}

int main(void)
{
	int A[] = { 5, 2, 9, 1, 8, 7, 6, 4, 3};
	int N = sizeof(A) / sizeof(A[0]);
	quicksort(A, 0, N - 1);
	// partition_ip(A, 0, N - 1, 4);
	for (int i = 0;i < N;i++)
		cout << A[i] << ' ';
	cout << endl;
	return 0;
}
