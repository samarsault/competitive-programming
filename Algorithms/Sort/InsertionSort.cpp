#include <stdio.h>

int incount = 0;
void insertion_sort(int A[], int n) 
{
	for (int i = 1;i < n;i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			incount++;
			j--;
		}
		A[j + 1] = key;
	}
}

int main(int argc, const char *argv[])
{
    int arr[] = { 2, 3, 8, 6, 1 };
    int len = sizeof(arr) / sizeof(int);
    
    insertion_sort(arr, len);
    
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    printf("%d\n", incount);
    return 0;
}
