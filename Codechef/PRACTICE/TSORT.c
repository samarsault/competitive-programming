#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2)
{
	return (*(int*)elem1) > (*(int*)elem2);
}

int main(int argc, char const *argv[])
{
	int t, N, i = 0;
	scanf("%d", &t);

	int arr[t];
	while (i < t)
	{
		scanf("%d", &N);
		arr[i] = N;
		i++;
	}
	qsort(arr, t, sizeof(arr), comp)
	i = 0;
	while (i < t)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return 0;
}