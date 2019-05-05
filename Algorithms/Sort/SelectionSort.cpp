#include <iostream>

using namespace std;

bool compareInteger(int a, int b)
{
	return a > b;
}

// Generic Selection Sort
// Complexity: n(n + 1) / 2
template <typename T>
void SelectionSort(T A[], size_t len, bool (*comp)(T, T))
{
	// index of smallest item
	size_t m = 0;

	for (int i = 0;i < len;i++)
	{
		m = i;
		for (int k = i;k < len;k++)
			if (comp(A[m], A[k]))
				m = k;

		swap(A[m], A[i]);
	}
}

int main(int argc, char const *argv[])
{
    int A[] = {15, 4, 16, 50, 8, 23, 42, 108};
    int L = sizeof(A) / sizeof(A[0]);
    // sort
    SelectionSort(A, L, compareInteger);
    // print
    for (int i = 0;i < L;i++)
    	cout << A[i] << " ";

    cout << endl;
	return 0;
}