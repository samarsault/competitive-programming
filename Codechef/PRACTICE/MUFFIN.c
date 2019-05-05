#include <stdio.h>

int main()
{
	unsigned int T, N;
	scanf("%u", &T);

	while (T--)
	{
		scanf("%u", &N);
		// floor(N / 2) if N is float
		printf("%u\n", N / 2 + 1);
	}
	return 0;
}