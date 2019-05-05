#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int T, p, i = 0;
	scanf("%d", &T);

	int *arr = (int*) malloc(12 * sizeof(int));

	for (int i = 0; i <= 12; i++)
	{
		arr[i] = (int) pow(2, i);
	}
	while (i < T)
	{
		scanf("%d", &p);

		i++;
	}
	return 0;
}