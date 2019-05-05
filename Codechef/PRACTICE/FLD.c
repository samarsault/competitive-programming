/*
 * https://www.codechef.com/problems/FLOW004
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		int nDigits = floor(log10(abs(N))) + 1;
		if (nDigits == 1)
			printf("%d\n", N);
		else
		{
			float firstDigit = floor(N/pow(10, nDigits - 1));
			float lastDigit = N % 10;
			printf("%0.f\n", firstDigit + lastDigit);
		}

	}
	
	return 0;
}