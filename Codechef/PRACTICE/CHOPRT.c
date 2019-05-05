#include <stdio.h>

int main(int argc, char const *argv[])
{
	int T, A, B;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &A, &B);

		if (A > B)
			printf(">\n");
		else if (A < B)
			printf("<\n");
		else
			printf("=\n");
	}
	return 0;
}