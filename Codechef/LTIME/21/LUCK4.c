/*
 * LuckFOUR
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int T, N;
	scanf("%d", &T);
	while (T--)
	{
		int n4s = 0;
		scanf("%d", &N);
		
		while (N != 0)
		{
			if (N % 10 == 4)
				n4s++;
			N /= 10;
		}

		printf("%d\n", n4s);
	}

	return 0;
}