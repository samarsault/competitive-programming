/*
 * Reverse number
 */
#include <stdio.h>

int reverse(int *n)
{
	int num = *n;
	int rev_num = 0;
	while (num > 0)
	{
		rev_num = (rev_num * 10) + (num % 10);
		num /= 10;
	}
	return rev_num;
}

int main(int argc, char const *argv[])
{
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		int x = reverse(&N);
		printf("%d\n", x);
	}
	return 0;
}