#include <stdio.h>
#include <stdlib.h>

int m;
int v[1000000];
// precede
int cmp(const void * p, const void * q){
	return *(int*)p > *(int*)q;
}

int main(int argc, char *argv[])
{
	int a,b;
	scanf("%d",&m);
	for (int i = 0;i < m;i++)
	{
		scanf("%d %d",&a,&b);
		v[i] = ( a < b ) ? a : b;
	}

	qsort(v,m,sizeof(int), cmp);
	int ans = 0, curr = 1;
	for (int i = 0; i < m; ++i) 
	{
		if (v[i] >= curr) {
			ans++;
			curr++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
