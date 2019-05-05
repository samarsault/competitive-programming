/*
 *  Levenshtein Distance Algorithm
 *  (Recursive)
 *  Calculate The minimum number of steps to change a string into another
 *
 *  Steps include -> Deletion of character,
 *  				 -> Addition of character,
 *  				 -> Replacement of Character
 */

#include <string>
#include <cmath>

using namespace std;

int min(int a, int b, int c)
{
	return min(min(a, b), c);
}

// Levenshtein distance b/w 2 strings changing  A -> B
int ldist(string A, int n, string B, int n2)
{
	int cost;

	// base case
	if (n == 0) return n2;
	if (n2 == 0) return n;

	// test if last chars of string match
	if (A[n - 1] == B[n2 - 1])
		cost = 0;
	else
		cost = 1;

	return min(1 + ldist(A, n - 1, B, n2),  // deletion
			   1 + ldist(A, n,  B, n2 - 1), // addition
			cost + ldist(A, n - 1, B, n2 - 1)); // replace
}