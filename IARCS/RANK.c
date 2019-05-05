// Complexity: O(n^2)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0;i < n;i++)
		scanf("%d",&a[i]);

	int l = 0, r[n];
	for (int i = 0;i < n;i++) 
	{
		int k = a[i];
		int j = 0;
		while (j < l && r[j] > k)
			j++;
		int rank = -1;
		int insertAt = j;
		if (j == 0 ) {
			insertAt = 0;
			rank = 1;
		}
		for (int p = l;p > insertAt;p--)
			r[p] = r[p-1];
		r[insertAt] = k;
		if (rank < 0) rank = j + 1;
		l++;
		printf("%d\n", rank);
	}
	return 0;
}
