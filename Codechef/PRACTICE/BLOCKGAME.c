#include <stdio.h>

int reverse(int num)
{
	int rev_num = 0;
	while (num != 0)
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
		if(N == reverse(N))
			printf("wins\n");
		else
			printf("losses\n");
	}
	return 0;
}