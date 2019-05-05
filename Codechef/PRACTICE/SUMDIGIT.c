/*
 * Sum of Digits
 * https://www.codechef.com/problems/FLOW006
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int T, N, sum;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d", &N);
		sum = 0;

		while (N != 0) 
		{
			sum += N % 10;
			N = N / 10;
		}
		printf("%d\n", sum);
	}

	return 0;
}