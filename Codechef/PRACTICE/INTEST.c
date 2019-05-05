#include <stdio.h>

int main(void) 
{
	int n, k, ti, dv = 0;
	scanf("%d %d", &n, &k);

	int i = 0;
	while (i < n)
	{
		scanf("%d", &ti);
		if ((ti % k) == 0)
			dv++;
		i++;
	}
	printf("%d", dv);

	return 0;
}