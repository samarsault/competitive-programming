#include <stdio.h>
#include <math.h>

int numdigits (int num)
{
	int n = 0;
	while (num != 0)
	{
		num /= 10;
		n++;
	}
	return n;
}

int rev (int num)
{
	int n = numdigits(num);
	int res = 0;
	int i = 0;
	while (num != 0)
	{
		int x = (int) pow(10, n-1);
		int l = num/x;
		num -= l * x;
		res += l * pow(10, i);
		n--;
		i++;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int T, a, b;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &b);
		int n = rev(a) + rev(b);
		printf("%d\n", rev(n));
	}
	return 0;
}