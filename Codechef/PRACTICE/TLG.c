#include <stdio.h>

int main(void)
{
	int N, W = 0, L = 0, p1, p2, ps = 0, ps2 = 0, i = 0;
	scanf("%d", &N);

	while (i < N)
	{
		scanf("%d %d", &p1, &p2);
		ps += p1;
		ps2 += p2;

		if (ps2 > ps && L < (ps2 - ps)) 
		{
			L = ps2 - ps;
			W = 2;
		}
		else if (ps > ps2 && L < (ps - ps2))
		{
			L = ps - ps2;
			W = 1;
		}
		i++;
	}

	printf("%d %d", W, L);
	return 0;
}