/*
 * Operation on Sets (Arrays)
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Union of Set
 * Returns Void
 */
void set_union(int *unionSet, int *set1, int len1, int *set2, int len2)
{
	for (int i = 0; i < len1; i++)
	{
		unionSet[i] = set1[i];
	}

	for (int k = len1; k < (len1 + len2); k++)
	{
		unionSet[k] = set2[k - len1];
	}

}

/*
 * Intersection of Set
 * Returns Length of Intersection
 */
int set_intersection(int *result, int *set1, int len1, int *set2, int len2)
{
	int ri = 0;
	for (int i = 0; i < len1; i++)
	{
		for (int k = 0; k < len2; k++)
		{
			if (set1[i] == set2[k]) 
			{
				result[ri] = set1[i];
				ri++;
			}
		}
	}
	return ri;
}

int main(int argc, char const *argv[])
{
	// Example Sets
	int s1[6] = { 1, 2, 3, 4, 5, 6 };
	int s2[6] = { 5, 6, 7, 8, 9, 10 };

	// Set Union
	int un[10];
	set_union(un, s1, 6, s2, 6);

	// Set Intersection
	int ins[5];
	int len = set_intersection(ins, s1, 6, s2, 6);

	printf("Set 1: { 1, 2, 3, 4, 5, 6 }\n");
	printf("Set 2: { 5, 6, 7, 8, 9, 10 }\n");

	// Print Union of Sets
	printf("A ∪ B = { ");

	for (int i = 0; i < 10; ++i)
	{
		if (i == 9) {
			printf("%d",un[i]);
			break;
		}
		printf("%d, ", un[i]);
	}
	printf(" }\n");

	// Print Intersection of Sets
	printf("A ∩ B = { ");

	for (int i = 0; i < len; i++)
	{
		if (i == (len - 1))
		{
			printf("%d", ins[i]);
			break;
		}
		printf("%d, ", ins[i]);
	}
	printf(" }\n");

	return 0;
}