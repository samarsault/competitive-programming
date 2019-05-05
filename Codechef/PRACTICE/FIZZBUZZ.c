#include <stdio.h>

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("%s\n", "FIZZBUZZ");
		else if (i % 3 == 0)
			printf("%s\n", "FIZZ");
		else if (i % 5 == 0)
			printf("%s\n", "BUZZ");
		else
			printf("%d\n", i);
	}
	return 0;
}