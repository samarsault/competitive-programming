/*
 * Second Largest
 * https://www.codechef.com/problems/FLOW017
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int T, A, B, C, SL;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d %d", &A, &B, &C);

		if (A > B && A < C)
			SL = A;
		else if (A > C && A < B)
			SL = A;
		else if (B > A && B < C)
			SL = B;
		else if (B < A && B > C)
			SL = B;
		else
			SL = C;

		printf("%d\n", SL);

	}

	return 0;
}