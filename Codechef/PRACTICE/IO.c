/*
 * FILE I/O TESTS
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 80000

int main(int argc, char const *argv[])
{
	char *content = (char*) malloc(SIZE * sizeof(char));
	FILE* fptr;

	fptr = fopen("ATM.c", "r");

	if (fptr)
	{
		fscanf(fptr, "%[^\n]", content);
		while (!feof(fptr))
		{
			printf("%s", content);
			fscanf(fptr, "%s\n", content);
		}
		printf("%s\n", content);
		fclose(fptr);
	}
}
