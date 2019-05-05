#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *message = "What an obedient servant you are!";
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		if (N < 10)
			printf("%s\n", message);
		else
			printf("%d\n", -1);
	}
	return 0;
}