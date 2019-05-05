#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 0, T, A, B;

	scanf("%d", &T);
	while (i < T)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A % B);
		i++;
	}
	return 0;
}