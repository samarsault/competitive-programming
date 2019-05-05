#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int t=*b;
	*b = *a;
	*a = t;
}
int cmp(const void * a, const void * b)
{
	return *(int*)a > *(int*)b;
}
// generate the next permutation
void nextPerm(int * a, int n)
{
	int k = - 1;
	for (int i = n - 1;i >= 1;i--)
	{
		if (a[i] > a[i-1])
		{
			k = i-1;
			break;
		}
	}

	if (k<0)return;

	int j=-1;
	for (int i = k;i < n;i++)
	{
		if(a[i] > a[k])
		{
			if (j >=0 ){
				if(a[i] < a[j])
					j = i;
			} else {
				j=i;
			}
		}
	}

	swap(a + k, a + j);
	qsort(a+(k+1),n - (k+1),sizeof(int),cmp);
}

int main(int argc, char *argv[])
{
	int n,k;
	scanf("%d %d", &n, &k);
	while (k--)
	{
		int a[n];
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);

		nextPerm(a, n);

		for(int i =0;i < n;i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}
