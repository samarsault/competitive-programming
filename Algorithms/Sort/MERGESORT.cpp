#include <iostream>
#include <cmath>
#include <limits.h>

/* 
 * MERGE with sentinel
 */

void MERGE(int A[], int p, int q, int r)
{
    int n1 = (q - p) + 1;
    int n2 = (r - q);
    int L[n1 + 1], R[n2 + 1];

    // Sentinel

    // Copy arrays
    for (int i = 0;i < n1;i++)
        L[i] = A[p + i];

    for (int j = 0;j < n2;j++)
        R[j] = A[q + j + 1];

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
            j++;
        }
    }
}

void InsertionSort(int A[], int n)
{
    for (int i = 1;i < n;i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void MERGESORT(int A[], int p, int r, int k = 4)
{
    if (p < r)
    {
        if ((r - p) == 4)
            InsertionSort(A + p, r);
        else
        { 
            int q = (p + r) / 2;
            MERGESORT(A, p, q);
            MERGESORT(A, q + 1, r);
            MERGE(A, p, q, r);
        }
    }
}


// Print Array
void printA(int * A, int n)
{
    for (int i =0 ;i < n;i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
/* 
 * End MERGE with sentinel
 */

/* 
 * MERGE without sentinel
 */

// Merge Arrays A[p..q] and A[q..r]
// Complexity: O()
void merge(int A[], int p, int q, int r)
{
    int n1 = (q - p) + 1;
    int n2 = (r - q);

    int B[n1], C[n2];

    // Copy Arrays
    for (int i = 0;i < n1;i++)
        B[i] = A[p + i];

    for (int i = 0;i < n2;i++)
        C[i] = A[q + 1 + i];

    int i = 0, j = 0;
    int k = p;

    while(i < n1 && j < n2)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    // Add left out items
    while (i < n1)
    {
        A[k] = B[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = C[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int p, int r)
{
    if (p >= r)
        return;

    int q = (p + r) / 2;

    mergesort(A, p, q); // sort left half
    mergesort(A, q + 1, r); // sort right half
    merge(A, p, q, r); // merge sorted halfs
}
/* 
 * End MERGE without sentinel
 */
 
int main(int argc, char const *argv[])
{
    int N ;
	std::cin >> N;
	int A[N];
	for(int i=0;i<N;i++)std::cin>>A[i];

    MERGESORT(A, 0, N - 1);
    mergesort(A, 0, N - 1);
    // InsertionSort(A, N);

    printA(A, N);
    return 0;
}
